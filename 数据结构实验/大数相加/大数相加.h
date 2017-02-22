#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int status;					//定义复杂的构造类型
			
typedef struct DuCirNode{
	int data;
	struct DuCirNode *prior;
	struct DuCirNode *next;
	int len;
}DuCirNode, *DulinkList;

status createLink(DulinkList *L)
{	//创建链表
	if(!(*L=(DulinkList)malloc(sizeof(DuCirNode)))) return OVERFLOW;
	(*L)->next=*L;
	(*L)->prior=*L;
	(*L)->len=0;
	return OK;
}


status insertNode(DulinkList *L , int data)
{	//插入结点
	DulinkList p;
	if(!(p = (DulinkList)malloc(sizeof(DuCirNode)))) return OVERFLOW; /*生成新结点*/
	p->data=data;
	p->next=(*L)->next;
	(*L)->next->prior=p;
	(*L)->next=p;
	p->prior=*L;
	(*L)->len++;
	return OK;
}

/*deleteNode(*L,q);*/
status deleteFirst(DulinkList *L)
{
	DulinkList p;
	if((*L)->len==1)
	return 0;
	p=(*L)->next;
	(*L)->next=p->next;
	free(p);
	(*L)->len--;
	return OK;
}  

status input(DulinkList *L)
{
	int i=0,t=0,k;
	int j=0,sum=0,c=0;
	char *s,x;
	s=(char *)malloc(100*sizeof(char ));
	s[0]='0';
	x=getchar();
	while(x!='\n'&&x!=' ')
	{
		i++;
		t=i-1;
		if(i==1)
		{
			if(x>='0' && x<='9')
			{
				(*L)->data=1;s[i]=x;
			}
			else
				if(x=='-')
				{
					(*L)->data=-1;
					s[t]='-';
				}
				else if(x=='+')
				{
					(*L)->data=1;
					s[t]='+';
				}
					else
				{
					printf("input invalid!");
					return ERROR;
				}

			if(x>='0' && x<='9')
			{
				if(s[0]=='0')
				s[i]=x;
				else
				s[t]=x;
			}
			else
			{
				printf("input invalid!");
				return ERROR;
			}

		}
/* scanf("%c",&x);*/
		x=getchar();
	}
/* getchar();*/
	if(s[0]=='0')
	s[++i]='\0';
	else
	s[i]='\0';
/*s[++i]='\0';*/
	for(i=strlen(s)-1;i>0;i--)
	{
		if(s[1]=='0')
		{
			insertNode(L,0);
			return OK;
		}
		j=j%4;
		c=s[i]-'0';
		for(k=0;k<j;k++)
		c*=10;
		sum=sum+c;
		j++;
		if(j==4)
		{
			insertNode(L,sum);sum=0;
		}
/* j++;*/
	}
/*j--;*/
	if(j<4 /*&& j>=0*/)insertNode(L,sum);

	return OK;


}  
 
status add(DulinkList L1, DulinkList L2, DulinkList *result)
 {
	DulinkList p1,p2,q1,q2;
	int resData,t,*jinwei,*jiewei,i=1;
	jinwei=(int *)malloc(100*sizeof(int));
	jiewei=(int *)malloc(100*sizeof(int));
	p1=L1->prior;
	p2=L2->prior;
	jinwei[0]=0;
	jiewei[0]=0;

	if(L1->data*L2->data==1) /*L1与L2正负相同*/
	{
		while(p1!=L1 && p2!=L2)
		{
			jinwei[i]=0;
			resData=p1->data + p2->data+jinwei[i-1];
			t=resData;
			if(resData>=10000)
			{
				resData-=10000;
				jinwei[i]=1;
			}
			insertNode(result,resData);
			p1=p1->prior;p2=p2->prior;
			i++;
		}
/*if(t==10000) /*为了解决1000+9000的问题而设置的t
insertNode(result,1);*/
		if(p1==L1 && p2==L2 &&jinwei[i-1])
		insertNode(result,1);
		while(p1!=L1)
		{
			jinwei[i]=0;
			resData=p1->data+jinwei[i-1];
			if(resData>=10000)
			{
				resData-=10000;
				jinwei[i]=1;
			}
			insertNode(result,resData);
			i++;
			p1=p1->prior;
		}
		while(p2!=L2)
		{
			jinwei[i]=0;
			resData=p2->data+jinwei[i-1];
			if(resData>=10000)
			{
				resData-=10000;
				jinwei[i]=1;
			}
			insertNode(result,resData);
			i++;
			p2=p2->data;
		}

		(*result)->data=L1->data;
	} /*两数符号相同的if结束*/


	else /*L1与L2符号相反，即一正一负*/
   {
		/*以下说的大小指的是绝对值*/
		if(L1->len<L2->len)    /*L1的长度小于L2的长度,此时L1必小于L2,用L2-L1*/
		{
			while(p1!=L1 && p2!=L2)
			{
   /*p2->data-=jiewei[i];*/
				if(p2->data<p1->data) /*如果p2的值<p1的值则要向前一个结点借位，同时前一个结点的值减1*/
				{
   /*jiewei[i]=1;*/
					p2->prior->data-=1;
					resData=p2->data+10000-p1->data;
				}
				else /*如果够减*/
				{
					resData=p2->data-p1->data;
				}

				insertNode(result,resData);
				p1=p1->prior;p2=p2->prior;
   /*jiewei[i]=0;
   i++;*/
			}

			while(p2!=L2)
			{
				if((p2->prior==L2)&&(p2->data==0))/*若此时p2已是第一个数据且因代借位已变为0,则应停止向result插入节点*/
				break;
				if(p2->data==-1)
				{
					p2->prior->data-=1;
					resData=p2->data+10000;
					insertNode(result,resData);
				}
				else
				insertNode(result,p2->data);
				p2=p2->prior;
			}

			(*result)->data=L2->data;
		} /*L1长度小于L2的长度时的处理结束*/
		else   /*L1的长度大于或等于L2的长度,此时L1和L2的大小不定*/
			if(L1->len>L2->len) /*如果L1大于L2 */
			{
				while(p1!=L1 && p2!=L2)
				{
					if(p1->data<p2->data)
					{
						p1->prior->data-=1;
						resData=p1->data+10000-p2->data;
					}
					else
					{
						resData=p1->data-p2->data;
					}

					insertNode(result,resData);
					p1=p1->prior;p2=p2->prior;
   /*i++;*/
				}

				while(p1!=L1)
				{
					if(p1->prior==L1&&p1->data==0)
					break;
					insertNode(result,p1->data);
					p1=p1->prior;
				}

				(*result)->data=L1->data;
			} /*L1的长度大于L2的长度时的处理结束*/
			else /*L1、L2的长度相等*/
			{

				q1=L1->next;
				q2=L2->next;
				while(q1->data==q2->data&&q1!=L1&&q2!=L2)/*从第一个结点开始进行判断到底哪个大*/
				{
					q1=q1->next;
					q2=q2->next;
				}
				if(q1!=L1)
				{
					if(q1->data>q2->data) /* L1>L2,用L1-L2 */
					{
						while(p1!=L1 && p2!=L2)
						{
							if(p1->data<p2->data)
							{
								p1->prior->data-=1;
								resData=p1->data+10000-p2->data;
							}
							else
							{
								resData=p1->data-p2->data;
							}

							insertNode(result,resData);
							p1=p1->prior;p2=p2->prior;
						}
						(*result)->data=L1->data;
					}
					else /*L1<L2,then L2-L1*/
					{
						while(p1!=L1 && p2!=L2)
						{
							if(p2->data<p1->data) /*如果p2的值<p1的值则要向前一个结点借位，同时前一个结点的值减1*/
							{
								p2->prior->data-=1;
								resData=p2->data+10000-p1->data;
							}
							else /*如果够减*/
							{
								resData=p2->data-p1->data;
							}

							insertNode(result,resData);
							p1=p1->prior;p2=p2->prior;
						}
						(*result)->data=L2->data;
					}
				}
				else
				insertNode(result,0); /*L1和L2相等,则result的值等于0*/
			}
	} /*最外层else结束,即两数符号相反*/

   return OK;
 } 

int getLen(int n)
{
	int i,k=1000;
	for(i=4;i>=1;i--)
	{
		if(n/k)
		return i;
		k=k/10;
	}
	return i;
}

void print(DulinkList L)
{
	DulinkList p,q;
	int n=0,flag=1;
	if(L->data==-1)
	printf("%c",'-');
	q=L->next;
	while(q->data==0)
	{
		flag=deleteFirst(&L);
		if(flag==0)
		break;
		q=L->next;
	}
	p=L->next;
	printf("%d",p->data);
	p=p->next;
	while(p!=L)
	{ 
		printf(",");
		n=getLen(p->data);
		if(n==0)
		{
			printf("0000");
		}
		else
		{
			if(n==1)
			printf("000");
			else if(n==2)
			printf("00");
			else if(n==3)
			printf("0");  
		printf("%d",p->data);
		}

		p=p->next;
	}
} 
