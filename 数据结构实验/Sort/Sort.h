#include "SqList.h"
#include <stdio.h>
void Print(SqList &L)
{
	int i;
	for(i=1;i<=L.length;i++)
	{
		printf("%d\t",L.r[i].key);
	}
	printf("\n");
}

void InsertSort(SqList &L)
{
	//Ö±½Ó²åÈëÅÅÐò
	int i,j;
	for(i=2;i<=L.length;++i)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(j=i-2;L.r[0].key<L.r[j].key;--j)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
	}
}
void ShellInsert(SqList &L,int dk)
{
	//Ï£¶ûÅÅÐò
	int i,j;
	for(i=dk+1;i<=L.length;++i)
	{
		if(L.r[i].key<L.r[i-dk].key)
		{
			L.r[0]=L.r[i];
			for(j=i-dk;j>0&&(L.r[0].key<L.r[j].key);j-=dk)
				L.r[j+dk]=L.r[j];
			L.r[j+dk]=L.r[0];
		}
	}
}
