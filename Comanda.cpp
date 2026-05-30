//ATTACH CODES ON INPUT - STRUCT
//ATTACH/STORE ON TAB

#include <stdio.h>
#include <string>

//functions
void fmenu();
void fmenuop();
void fopentab();
void faddorder();
void feditorder();
//void ftotal();

struct item
{
	const char *name;
	float price;
	int code;
};

int main()
{
	printf("\tBon Apetit\n\n");
	
	fmenu();
	printf("\n\nAdicionar pedido.\n");
	faddorder();
	fmenuop();
}

void fmenu()
{
	//menu
	struct item appetizer[] = {
		{"Batata Frita", 22.00, 004},
		{"Polenta Frita", 18.00, 072},
		{"Bolinhas de Queijo", 24.00, 051}
	};
	
	struct item dishes[] = {
		{"File de Peixe Empanado", 38.00, 015}, 
		{"Frango a Parmegiana", 42.00, 072},
		{"Frango a Passarinho", 35.00, 047},
		{"Bisteca", 32.00, 066},
		{"Cupim ao Molho", 46.00, 025}
	};
	
	struct item drinks[] = {
		{"Pink Lemonade", 12.00, 053},
		{"Refrigerante 250ml", 5.00, 024},
		{"Suco Natural", 8.50, 033},
		{"Cha Gelado", 7.00, 012}
	};
	
	struct item dessert[] = {
		{"Milkshake", 15.00, 057},
		{"Petit Gateu", 18.00, 042},
		{"Sorvete", 10.00, 061}
	};
	
	//array size and print appetizer 
	printf("|Entradas\n");
	int aptotal = sizeof(appetizer) / sizeof(appetizer[0]);
	for(int i = 0; i < aptotal; i++)
	{
		printf("| %d \t %-25s \t R$%.2f\n", appetizer[i].code, appetizer[i].name, appetizer[i].price);
	}
	
	//array size and print dishes 
	printf("|Pratos\n");
	int dstotal = sizeof(dishes) / sizeof(dishes[0]);
	for(int i = 0; i < dstotal; i++)
	{
		printf("| %d \t %-25s \t R$%.2f\n", dishes[i].code, dishes[i].name, dishes[i].price);
	}
	
	//array size and print drinks
	printf("|Bebidas\n"); 
	int dktotal = sizeof(drinks) / sizeof(drinks[0]);
	for(int i = 0; i < dktotal; i++)
	{
		printf("| %d \t %-25s \t R$%.2f\n", drinks[i].code, drinks[i].name, drinks[i].price);
	}
	
	//array size and print dessert 
	printf("|Sobremesas\n");
	int dttotal = sizeof(dessert) / sizeof(dessert[0]);
	for(int i = 0; i < dttotal; i++)
	{
		printf("| %d \t %-25s \t R$%.2f\n", dessert[i].code, dessert[i].name, dessert[i].price);
	}
	
	return;
}

void fmenuop()
{
	int option;
	printf("\n1. Adicionar novo pedido.\n");
	printf("2. Editar pedido.\n");
	printf("3. Cancelar pedido.\n");
	printf("4. Encerrar pedido.");
	printf("\nDigite uma opcao: ");
	scanf("%d", &option);
	
	if((option > 4) || (option <= 0))
	{
		printf("Digite uma opcao valida!");
	}
	
	switch (option)
	{
		case 1:
			faddorder();
			break;
//		case 2:
//			feditorder();
//			break;
//		case 3:
//			fcancorder();
//			break;
//		case 4:
//			fendorder();
//			break;
	}
}

void faddorder()
{
	char apporder[4];
	char dsorder[4];
	char dkorder[4];
	char dtorder[4];
	int appamt, dsamt, dkamt, dtamt;
	int appnew, dsnew, dknew, dtnew;
	
	do
	{
		printf("\nDigite o codigo da entrada (0 para nenhum): ");
		scanf("%s", &apporder);
		
		printf("Quantidade: ");
		scanf("%d", &appamt);
		//ADD QUANTITY ON PRICE
		
		printf("Deseja adicionar uma nova entrada? [1]Sim [2]Nao: ");
		scanf("%d", &appnew);
		
		if(appnew > 2)
		{
			printf("Digite uma entrada valida!\n");
		}
		if(appnew == 2)
			break;
			
	}while(appnew == 1);
	
	do
	{
		printf("\nDigite o codigo do prato (0 para nenhum): ");
		scanf("%s", &dsorder);
		
		printf("Quantidade: ");
		scanf("%d", &dsamt);
		//ADD QUANTITY ON PRICE
		
		printf("Deseja adicionar um novo prato? [1]Sim [2]Nao: ");
		scanf("%d", &dsnew);
		
		if(dsnew > 2)
		{
			printf("Digite uma entrada valida");
		}
		if(dsnew == 2)
			break;
			
	}while(dsnew == 1);
	
	do
	{
		printf("\nDigite o codigo da bebida (0 para nenhum): ");
		scanf("%s", &dkorder);
		
		printf("Quantidade: ");
		scanf("%d", &dkamt);
		//ADD QUANTITY ON PRICE
		
		printf("Deseja adicionar uma nova entrada? [1]Sim [2]Nao: ");
		scanf("%d", &dknew);
		
		if(dknew > 2)
		{
			printf("Digite uma entrada valida");
		}
		if(dknew == 2)
			break;
			
	}while(dknew == 1);
	
	do
	{
		printf("\nDigite o codigo da sobremesa (0 para nenhum): ");
		scanf("%s", &dtorder);
		
		printf("Quantidade: ");
		scanf("%d", &dtamt);
		//ADD QUANTITY ON PRICE
		
		printf("Deseja adicionar uma nova entrada? [1]Sim [2]Nao: ");
		scanf("%d", &dtnew);
		
		if(dtnew < 2)
		{
			printf("Digite uma entrada valida");
		}
		if(dtnew == 2)
			break;
			
	}while(dtnew == 1);
}

void fopentab()
{
	
}

void feditorder()
{
	int option;
	printf("\n1. Adicionar novo item.\n");
	printf("2. Retirar item da comanda.\n");
	printf("3. Excluir comanda.");
	printf("\nDigite uma opcao: ");
	scanf("%d", &option);
	
	if((option > 4) || (option <= 0))
	{
		printf("Digite uma opcao valida!");
	}
	switch (option)
	{
		case 1:
			faddorder();
			break;
		/*case 2:
			fremove();
			break;
		case 3:
			fdelete();*/
	}
}
