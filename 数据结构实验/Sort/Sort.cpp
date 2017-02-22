#include "Sort.h"
#include <time.h>
int Input(SqList &L,int &n)
{
	int i,e;
	printf("输入元素个数\n");
	scanf_s("%d",&n);
	printf("请输入元素\n");
	for(i=1;i<=n;i++)
	{
		scanf_s("%d",&e);
		ListAppend_Sq(L,e);
	}
	return OK;
}
int Rand(SqList &L,int &n)
{
	int i,number;
	srand((unsigned)time(NULL));
	printf("输入要产生的随机数\n");
	scanf_s("%d",&n);
	for(i=1;i<=n;i++)
	{
		number =rand();
		ListAppend_Sq(L,number);
	}
	return OK;
}

int menu(SqList &L)
{
	int i=0,n;
	SqList *p=&L;
		while(i!=7)
	{
		printf("please choose the function\n");
		printf("**************************\n");
		printf("0.输入要排序的序列\n1.产生随机数列\n2.直接插入排序\n3.希尔排序\n4.冒泡法\n5.输出数列\n6.重新输入\n7.退出\n");
		printf("**************************\n");
		scanf_s("%d",&i);

		switch(i)
		{
		case 0:printf("*****输入数列*****\n");Input(L,n);break;
		case 1:Rand(L,n);break;
		case 2:printf("*****InsertSort*****\n");InsertSort(L);Print(L);break;
		case 3:
			{if(n%2!=0){printf("*****ShellInsert*****\n");ShellInsert(L,5);ShellInsert(L,3);ShellInsert(L,1);Print(L);}
			else{printf("*****ShellInsert*****\n");ShellInsert(L,4);ShellInsert(L,2);ShellInsert(L,1);Print(L);}}
			break;
		case 5:Print(L);break;
		case 6:free(p);InitList_Sq(L);break;
		}
	}
	return OK;
}
int main()
{
	SqList L;
	InitList_Sq(L);
	menu(L);
	return 0;
}
