// view tabs history
// g++ Comanda.cpp -o comanda

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define SERVICE_RATE 0.10f

// structs
struct item
{
	const char *name;
	float price;
	int code;
};

struct category
{
	const char *title;
	const struct item *items;
	int count;
};

struct orderline
{
	int code;
	int qty;
};

struct tab
{
	int number;
	bool open;
	int count;
	struct orderline lines[MAX_LINES];
};

const struct item appetizer[] = {
	{"Batata Frita", 22.00, 4},
	{"Polenta Frita", 18.00, 72},
	{"Bolinhas de Queijo", 24.00, 51}
};

const struct item dishes[] = {
	{"File de Peixe Empanado", 38.00, 15},
	{"Frango a Parmegiana", 42.00, 73},
	{"Frango a Passarinho", 35.00, 47},
	{"Bisteca", 32.00, 66},
	{"Cupim ao Molho", 46.00, 25}
};

const struct item drinks[] = {
	{"Pink Lemonade", 12.00, 53},
	{"Refrigerante 250ml", 5.00, 24},
	{"Suco Natural", 8.50, 33},
	{"Cha Gelado", 7.00, 12}
};

const struct item dessert[] = {
	{"Milkshake", 15.00, 57},
	{"Petit Gateau", 18.00, 42},
	{"Sorvete", 10.00, 61}
};

const struct category menu[] = {
	{"Entradas",   appetizer, sizeof(appetizer) / sizeof(appetizer[0])},
	{"Pratos",     dishes,    sizeof(dishes)    / sizeof(dishes[0])},
	{"Bebidas",    drinks,    sizeof(drinks)    / sizeof(drinks[0])},
	{"Sobremesas", dessert,   sizeof(dessert)   / sizeof(dessert[0])}
};
const int MENU_SIZE = sizeof(menu) / sizeof(menu[0]);

// status
struct tab currentTab = {0, false, 0, {}};
int tabCounter = 0;

// functions
int readInt(const char *prompt);
const struct item *findItem(int code);
int findLine(int code);
void fmenu();
void fmenuop();
void fopentab();
void faddorder();
void feditorder();
void fremove();
void fcancorder();
void fendorder();
void fshowtab();
float ftotal();

int main()
{
	printf("\tBon Apetit\n");
	fmenuop();
	printf("\nAte logo!\n");
	return 0;
}

int readInt(const char *prompt)
{
	char buf[64];
	int value;
	while (true)
	{
		printf("%s", prompt);
		if (fgets(buf, sizeof(buf), stdin) == NULL)
			exit(0); // fim da entrada
		if (sscanf(buf, "%d", &value) == 1)
			return value;
		printf("Entrada invalida! Digite um numero.\n");
	}
}

const struct item *findItem(int code)
{
	for (int c = 0; c < MENU_SIZE; c++)
		for (int i = 0; i < menu[c].count; i++)
			if (menu[c].items[i].code == code)
				return &menu[c].items[i];
	return NULL;
}

int findLine(int code)
{
	for (int i = 0; i < currentTab.count; i++)
		if (currentTab.lines[i].code == code)
			return i;
	return -1;
}

void fmenu()
{
	printf("\n| CARDAPIO \n\n");
	for (int c = 0; c < MENU_SIZE; c++)
	{
		printf("|%s\n", menu[c].title);
		for (int i = 0; i < menu[c].count; i++)
			printf("| %02d \t %-25s \t R$%.2f\n",
				menu[c].items[i].code, menu[c].items[i].name, menu[c].items[i].price);
	}
}

void fmenuop()
{
	int option;
	do
	{
		printf("\n| MENU PRINCIPAL \n\n");	
		printf("[1] Adicionar novo pedido\n");
		printf("[2] Editar pedido\n");
		printf("[3] Cancelar pedido\n");
		printf("[4] Encerrar pedido\n");
		printf("[5] Ver comanda\n");
		printf("[0] Sair\n");
		if (currentTab.open){
			printf("\nComanda #%d aberta\n", currentTab.number);
		}
		else{
			printf("\nNenhuma comanda aberta\n");
		}
		printf("--------------------------\n");
		option = readInt("Digite uma opcao: ");

		switch (option)
		{
			case 1: faddorder();   break;
			case 2: feditorder();  break;
			case 3: fcancorder();  break;
			case 4: fendorder();   break;
			case 5: fshowtab();    break;
			case 0:
				if (currentTab.open)
				{
					printf("Ha uma comanda aberta! Encerre ou cancele antes de sair.\n");
					option = -1;
				}
				break;
			default:
				printf("Digite uma opcao valida!\n");
		}
	} while (option != 0);
}

void fopentab()
{
	currentTab.number = ++tabCounter;
	currentTab.open = true;
	currentTab.count = 0;
	printf("\nComanda #%d aberta.\n", currentTab.number);
}

void faddorder()
{
	system("cls");
	if (!currentTab.open)
		fopentab();

	fmenu();
	while (true)
	{
		int code = readInt("\nCodigo do item (0 para terminar): ");
		if (code == 0)
			break;

		const struct item *it = findItem(code);
		if (it == NULL)
		{
			printf("Codigo inexistente!\n");
			continue;
		}

		int qty = readInt("Quantidade: ");
		if (qty <= 0)
		{
			printf("Quantidade invalida!\n");
			continue;
		}

		int idx = findLine(code);
		if (idx >= 0)
			currentTab.lines[idx].qty += qty;
		else if (currentTab.count < MAX_LINES)
		{
			currentTab.lines[currentTab.count].code = code;
			currentTab.lines[currentTab.count].qty = qty;
			currentTab.count++;
		}
		else
		{
			printf("Comanda cheia!\n");
			break;
		}
		printf("Adicionado: %dx %s = R$%.2f\n", qty, it->name, qty * it->price);
	}
	fshowtab();
}

void fshowtab()
{
	system("cls");
	if (!currentTab.open)
	{
		printf("\nNenhuma comanda aberta.\n");
		return;
	}
	printf("\n| COMANDA #%d \n", currentTab.number);
	if (currentTab.count == 0)
		printf("(vazia)\n");
	for (int i = 0; i < currentTab.count; i++)
	{
		const struct item *it = findItem(currentTab.lines[i].code);
		printf("%02d %dx %-25s R$%.2f\n", it->code, currentTab.lines[i].qty,
			it->name, currentTab.lines[i].qty * it->price);
	}
	printf("----------------------\n");
	printf("Subtotal: R$%.2f\n\n", ftotal());
}

float ftotal()
{
	float total = 0;
	for (int i = 0; i < currentTab.count; i++)
	{
		const struct item *it = findItem(currentTab.lines[i].code);
		total += currentTab.lines[i].qty * it->price;
	}
	return total;
}

void feditorder()
{
	if (!currentTab.open)
	{
		printf("\nNenhuma comanda aberta.\n");
		return;
	}

	system("cls");

	int option;
	do
	{
		printf("| EDITAR\n");
		printf("\n[1] Adicionar novo item\n");
		printf("[2] Retirar item da comanda\n");
		printf("[3] Excluir todos os itens da comanda\n");
		printf("[0] Voltar\n");
		printf("--------------------------------\n");
		option = readInt("Digite uma opcao: ");

		switch (option)
		{
			case 1: faddorder(); break;
			case 2: fremove();   break;
			case 3:
				system("cls");
				currentTab.count = 0;
				printf("Todos os itens foram removidos.\n\n");
				break;
			case 0: break;
			default: printf("Digite uma opcao valida!\n");
		}
	} while (option != 0);
}

void fremove()
{
	system("cls");
	fshowtab();
	if (currentTab.count == 0)
		return;

	int code = readInt("Codigo do item a retirar: ");
	int idx = findLine(code);
	if (idx < 0)
	{
		printf("Item nao esta na comanda!\n");
		return;
	}

	int qty = readInt("Quantidade a retirar: ");
	if (qty <= 0)
	{
		printf("Quantidade invalida!\n");
		return;
	}

	if (qty >= currentTab.lines[idx].qty)
	{
		for (int i = idx; i < currentTab.count - 1; i++)
			currentTab.lines[i] = currentTab.lines[i + 1];
		currentTab.count--;
	}
	else
		currentTab.lines[idx].qty -= qty;

	printf("Item atualizado.\n");
	fshowtab();
}

void fcancorder()
{
	system("cls");
	if (!currentTab.open)
	{
		printf("\nNenhuma comanda aberta.\n");
		return;
	}
	int confirm = readInt("Cancelar a comanda inteira? [1] Sim [2] Nao: ");
	if (confirm == 1)
	{
		currentTab.open = false;
		currentTab.count = 0;
		printf("Comanda cancelada.\n");
		system("cls");
	}
	else
		printf("Operacao abortada.\n");
}

void fendorder()
{
	system("cls");
	if (!currentTab.open)
	{
		printf("\nNenhuma comanda aberta.\n");
		return;
	}
	if (currentTab.count == 0)
	{
		printf("Comanda vazia! Adicione itens ou cancele.\n");
		return;
	}

	fshowtab();
	float subtotal = ftotal();
	float service = 0;

	int opt = readInt("Incluir taxa de servico de 10%? [1] Sim [2] Nao: ");
	if (opt == 1)
		service = subtotal * SERVICE_RATE;

	printf("\n| FECHAMENTO \n\n");
	printf("Subtotal: R$%.2f\n", subtotal);
	printf("Servico:  R$%.2f\n", service);
	printf("TOTAL:    R$%.2f\n", subtotal + service);
	printf("----------------------\n\n");

	int people = readInt("Dividir a conta por quantas pessoas? (1 = sem dividir): ");
	if (people > 1)
		printf("Valor por pessoa: R$%.2f\n", (subtotal + service) / people);

	currentTab.open = false;
	currentTab.count = 0;
	printf("\nComanda encerrada. Obrigado pela preferencia!\n");
}
