#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE   100		//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10			//���Ա�洢�ռ�ķ�������
typedef struct{
	float x;
	float y;
}Node;
typedef struct{
	Node *elem;
	int length;
	int size;
}List;
void Init_List(List *L)
{
	//����һ���յ����Ա�
	L->elem = (Node  *)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!L->elem) printf("The Sqlist is OVERFLOW");					//�洢����ʧ��
	L->length = 0;											//�ձ���Ϊ0
	L->size = LISTINCREMENT;								//��ʼ�洢����
}
void Input(List *L)
{
	//���뺯��
	Node *p;
	p = &L->elem[0];
	printf("�������εĵ�����(X,Y)\n");
	while (1)
	{
		scanf("%f,%f", p->x, p->y);
		if (!p->x) break;
		p++;
		++L->length;
	}
}