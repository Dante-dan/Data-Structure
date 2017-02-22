#include "1.h"
void main()
{
	DulinkList L1, L2,result;
	int f=0;
	createLink(&L1);
	createLink(&L2);
	createLink(&result);
	printf("\nplease input the first jiashu:\n");
	f=input(&L1);
	while(f==0)
	{
		printf("\nplease input the first jiashu again:\n");
		f=input(&L1);
	}
	printf("\nplease input the second jiashu:\n");
	f=input(&L2);
	while(f==0)
	{
		printf("\nplease input the second jiashu again:\n");
		f=input(&L2);
	}
	printf("\nThe first jiashu you inputed is: ");
	print(L1);
	printf("\nThe second jiashu you inputed is: ");
	print(L2);
	add(L1,L2,&result);

	printf("\n Result is:");
	print(result);
	getch();
}  
 
