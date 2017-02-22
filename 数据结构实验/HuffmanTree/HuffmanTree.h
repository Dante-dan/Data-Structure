#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//���������T���ݹ鶨��
BiTNode *CreateBiTree(BiTNode *T)
{
	char ch,c;
	BiTNode *p;
	printf("Input(������ո�Ϊ��):\n");
	p=T;
	ch=getchar();
	c=getchar();
	if(ch==' ')
	{
		p=NULL;
	}
	else
	{
		p=(BiTNode *)malloc(sizeof(BiTNode));
		p->data=ch;
		p->lchild=CreateBiTree(p->lchild);		//�ݹ�����
		p->rchild=CreateBiTree(p->rchild);
	}
	return p;
}
Status Visit(TElemType e)
{
	printf("%c",e);
	return OK;
}
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e))
{
	//�������
	if(T!=NULL){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit)) return OK;
				return ERROR;
				}else return OK;
}
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e))
{
	//�������
	if(T!=NULL){
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(InOrderTraverse(T->rchild,Visit)) return OK;
				return ERROR;
				}else return OK;
}
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e))
{
	//�������
	if(T!=NULL){
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data)) return OK;
				return ERROR;
				}else return OK;
}