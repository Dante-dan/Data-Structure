#include <stdio.h>
typedef struct Complex
{
	float real;
	float img;
}complex;				//����ṹ�����
complex *p,*q;			//����ȫ�ֱ����ṹ��ָ�룬�Ӷ�ʵ��ֵ����
complex com_1,com_2;	//����ṹ��
void InitComplex(complex *i)			//����
{
	printf("Enter the Complex:\n");
	scanf("%f,%f",&i->real,&i->img);
}
void Print(complex *i)				//��ӡ����
{	
	float n,m;
	n=i->real;
	m=i->img;
	if(n==0&&m==0)					//ʵ�����鲿��Ϊ��
		printf("0\n");
	else if(n==0)					//��ʵ��Ϊ��
		printf("%fi\n",m);
	else if(m==0)					//���鲿Ϊ��
		printf("%f\n",n);
	else if(m>0)					//�鲿������
		printf("%f+%fi\n",n,m);
	else							//�鲿С����
		printf("%f%fi\n",n,m);
}
void Add (complex *i,complex *j)	//�ӷ�
{
	i->real=i->real+j->real;
	i->img=i->img+j->img;
	Print(i);
}
void Sub (complex *i,complex *j)		//����
{
	i->real=i->real-j->real;
	i->img=i->img-j->img;
	Print(i);
}
void Mul (complex *i,complex *j)		//�˻�����
{
	i->real=i->real*j->real;
	i->img=i->img*j->img;
	Print(i);
}
void Sep (complex *i)			//���뺯��
{
	printf("real: %f\t,img: %f\t",i->real,i->img);
}
int menu()					//�˵�����������ֵ��Ϊѭ���ж�����
{	
	int a;
	printf("Select the function:\n 0.print;\n 1.Add;\n 2.Sub;\n 3.Mul;\n 4.Sep;\n 5.Exit\n");
	scanf("%d",&a);
	switch(a)
	{
	case 0: Print(p);break;								//��ӡ
	case 1: InitComplex(q);Add(p,q);return 1;break;		//�����ڶ������������м���
	case 2: InitComplex(q);Sub(p,q);return 1;break;
	case 3: InitComplex(q);Mul(p,q);return 1;break;
	case 4: Sep(p);return 1;break;
	case 5: return 0;
	}
}

int main()
{
	p=&com_1;			//ָ��ָ��ṹ��
	q=&com_2;
	InitComplex(p);
	while(menu())		//�ж�ѭ���Ƿ����
	{
		menu();
	}
}
