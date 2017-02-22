#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;
#define OVERFLOW -1;
typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
	int length;
}SqStack;

Status InitStack(SqStack *S)
{
	/*����һ����ջ*/
	S->base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType)) ;
	if(!S->base) return OVERFLOW;
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	S->length=0;
	return OK;
}

Status Gettop(SqStack S)
{
	//ջ���գ��򷵻�ջ��Ԫ�����򣬷���ERROR
	if(S.top==S.base) {return ERROR;}
	else	{return *(S.top-1);}
} 

Status Push(SqStack *S,SElemType e)
{//e��ջ
	if(S->top-S->base>=S->stacksize)
	{//ջ�������ӿռ�
		S->base = (SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ =e;
	S->length++;
	return OK;
}
Status Pop(SqStack *S)
{//ջ������ջ��Ԫ��ջ�������أ����򷵻�ERROR
	SElemType e;
	if(S->top==S->base) return ERROR;
	e=*--S->top;
	S->length--;
	return e;
}
