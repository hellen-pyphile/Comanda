//NEXT STEP: ARRAY PRICES
//ATTACH CODES ON INPUT
//ATTACH/STORE ON TAB

#include <stdio.h>
#include <string>

//functions
void fmenu();
void fmenuop();
void faddorder();
//void ftotal();

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
	const char *appetizer[] = {"Batata Frita", "Polenta Frita", "Bolinhas de Queijo"};
	const char *dishes[] = {"File de Peixe Empanado", "Frango a Parmegiana", "Frango a Passarinho", "Bisteca", "Cupim ao Molho"};
	const char *drinks[] = {"Pink Lemonade", "Refrigerante 250ml", "Suco Natural", "Cha Gelado"};
	const char *dessert[] = {"Milkshake", "Petit Gateu", "Sorvete"};
	
	//menu codes
	const char *cdapp[] = {"#084", "#037", "#091"};
	const char *cdds[]  = {"#015", "#072", "#048", "#066", "#029"};
	const char *cddk[]  = {"#053", "#004", "#088", "#019"};
	const char *cddt[]  = {"#077", "#042", "#061"};
	
	
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
		
		printf("Deseja adicionar uma novo prato? [1]Sim [2]Nao: ");
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

feditorder()
{
	
}
