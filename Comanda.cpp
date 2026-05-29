//adicionar codigos de identificacao em cada prato
//formatar o menu!!

#include <stdio.h>
#include <string>

//functions
void fmenu();
void fmenuop();
// pedido();


int main()
{
	
	menu();
}

void menu()
{
	//CHECK ABOUT \N INSIDE OF THE ARRAY
	const char *appetizer[] = {"Batata Frita", "Polenta Frita", "Bolinhas de Queijo"};
	const char *dishes[] = {"File de Peixe Empanado", "Frango a Parmegiana", "Frango a Passarinho", "Bisteca", "Cupim ao Molho"};
	const char *drinks[] = {"Pink Lemonade", "Refrigerante 250ml", "Suco Natural", "Cha Gelado"};
	const char *dessert[] = {"Milkshake", "Petit Gateu", "Sorvete"};
	
	//array size and print appetizer 
	int aptotal = sizeof(appetizer) / sizeof(appetizer[0]);
	for(int i = 0; i < aptotal; i++)
	{
		printf("%s\n", appetizer[i]);
	}
	
	//array size and print dishes 
	int dstotal = sizeof(dishes) / sizeof(dishes[0]);
	for(int i = 0; i < dstotal; i++)
	{
		printf("%s\n", dishes[i]);
	}
	
	//array size and print drinks 
	int dktotal = sizeof(drinks) / sizeof(drinks[0]);
	for(int i = 0; i < dktotal; i++)
	{
		printf("%s\n", drinks[i]);
	}
	
	//array size and print dessert 
	int dttotal = sizeof(dessert) / sizeof(dessert[0]);
	for(int i = 0; i < dttotal; i++)
	{
		printf("%s\n", dessert[i]);
	}
	
	return;
}

