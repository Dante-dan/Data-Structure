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
	/*构造一个空栈*/
	S->base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType)) ;
	if(!S->base) return OVERFLOW;
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	S->length=0;
	return OK;
}

Status Gettop(SqStack S)
{
	//栈不空，则返回栈顶元，否则，返回ERROR
	if(S.top==S.base) {return ERROR;}
	else	{return *(S.top-1);}
} 

Status Push(SqStack *S,SElemType e)
{//e入栈
	if(S->top-S->base>=S->stacksize)
	{//栈满，增加空间
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
{//栈不空则栈顶元出栈，并返回；否则返回ERROR
	SElemType e;
	if(S->top==S->base) return ERROR;
	e=*--S->top;
	S->length--;
	return e;
}
