#define LIST_INIT_SIZE   100		//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10			//���Ա�洢�ռ�ķ�������
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int num;
	int ele;
}Node;
typedef struct {
	Node * elem;
	int length;
	int listsize;
}SqList;
void InitList_Sq(SqList *L){
	//����һ���յ����Ա�
	L->elem = (Node  *)malloc(LIST_INIT_SIZE * sizeof(Node));	
	if (!L->elem) printf("The Sqlist is OVERFLOW");					//�洢����ʧ��
	L->length = 0;											//�ձ���Ϊ0
	L->listsize = LISTINCREMENT;								//��ʼ�洢����
}
void ListInsert(SqList *L, int i, Node e){
	//��˳���ĵ�i��λ�ü���Ԫ��
	//i�ĺϷ�ֵΪ1<=i<=ListLength.Sq(L)+1
	Node *newbase,*q;
	if (i<1 || i>L->length + 1) printf("iֵ���Ϸ�");
	if (L->length >= L->listsize)
	{//��ǰ�洢�ռ����������ӷ���
		newbase = (Node *)realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(Node));
		if (!newbase) 
		{
			printf("����ʧ��");
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i - 1]);
	*q = e;
	++L->length;
}
Node ListDelete(SqList *L, int i)
{//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
	Node e,*p, *q;
	//if ((i<1) || (i>L->length)) printf("iֵ���Ϸ�");
	p = &(L->elem[i - 1]);
	e = *p;
	q = &(L->elem + L->length - 1);
	for (++p; p <= q; ++p) *(p - 1) = *p;
	--L->length;
	i++;
	return e;
}
/*��pָ�����һ��Ԫ��ʱ���޷�ʵ��ɾ��*/