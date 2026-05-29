//adicionar codigos de identificacao em cada prato
//formatar o menu!!

#include <stdio.h>
#include <string>

//functions
void fmenu();
void fmenuop();
void faddorder();

int main()
{
	printf("\tBon Apetit\n\n");
	fmenu();
	fmenuop();
}

void fmenu()
{
	//menu
	const char *appetizer[] = {"Batata Frita", "Polenta Frita", "Bolinhas de Queijo"};
	const char *dishes[] = {"File de Peixe Empanado", "Frango a Parmegiana", "Frango a Passarinho", "Bisteca", "Cupim ao Molho"};
	const char *drinks[] = {"Pink Lemonade", "Refrigerante 250ml", "Suco Natural", "Cha Gelado"};
	const char *dessert[] = {"Milkshake", "Petit Gateu", "Sorvete"};
	
	//menu codes
	const char *cdapp[] = {"#011", "#021", "#031"};
	const char *cdds[] = {"#012", "#022", "#032", "#042", "#052"};
	const char *cddk[] = {"#013", "#023", "#033", "#043"};
	const char *cddt[] = {"#014", "#024", "#034"};
	
	
	//array size and print appetizer 
	int aptotal = sizeof(appetizer) / sizeof(appetizer[0]);
	for(int i = 0; i < aptotal; i++)
	{
		printf("| %s \t %s \t\n", cdapp[i], appetizer[i]);
	}
	
	//array size and print dishes 
	int dstotal = sizeof(dishes) / sizeof(dishes[0]);
	for(int i = 0; i < dstotal; i++)
	{
		printf("| %s \t %s \t\n", cdds[i], dishes[i]);
	}
	
	//array size and print drinks 
	int dktotal = sizeof(drinks) / sizeof(drinks[0]);
	for(int i = 0; i < dktotal; i++)
	{
		printf("| %s \t %s \t\n", cddk[i], drinks[i]);
	}
	
	//array size and print dessert 
	int dttotal = sizeof(dessert) / sizeof(dessert[0]);
	for(int i = 0; i < dttotal; i++)
	{
		printf("| %s \t %s \t\n", cddt[i], dessert[i]);
	}
	
	return;
}

void fmenuop()
{
	int option;
	printf("Digite uma opcao:\n\n");
	printf("1. Adicionar novo pedido.\n");
	printf("2. Editar pedido.\n");
	printf("3. Cancelar pedido.\n");
	printf("4. Encerrar pedido.\n");
	
	scanf("%d", &option);
	
	if((option > 4) || (option <= 0))
	{
		printf("Digite uma opcao valida!");
	}
	
	/*switch (op)
	{
		case 1:
			faddorder();
			break;
		case 2:
			feditorder();
			break;
		case 3:
			fcancorder();
			break;
		case 4:
			fendorder();
			break;
	}*/
}

void faddorder()
{
	
}

