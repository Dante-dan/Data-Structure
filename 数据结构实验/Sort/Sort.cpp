#include "Sort.h"
#include <time.h>
int Input(SqList &L,int &n)
{
	int i,e;
	printf("����Ԫ�ظ���\n");
	scanf_s("%d",&n);
	printf("������Ԫ��\n");
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
	printf("����Ҫ�����������\n");
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
		printf("0.����Ҫ���������\n1.�����������\n2.ֱ�Ӳ�������\n3.ϣ������\n4.ð�ݷ�\n5.�������\n6.��������\n7.�˳�\n");
		printf("**************************\n");
		scanf_s("%d",&i);

		switch(i)
		{
		case 0:printf("*****��������*****\n");Input(L,n);break;
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
