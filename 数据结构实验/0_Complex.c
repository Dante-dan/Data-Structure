#include <stdio.h>
typedef struct Complex
{
	float real;
	float img;
}complex;				//构造结构体变量
complex *p,*q;			//定义全局变量结构体指针，从而实现值传递
complex com_1,com_2;	//定义结构体
void InitComplex(complex *i)			//生成
{
	printf("Enter the Complex:\n");
	scanf("%f,%f",&i->real,&i->img);
}
void Print(complex *i)				//打印函数
{	
	float n,m;
	n=i->real;
	m=i->img;
	if(n==0&&m==0)					//实部、虚部都为零
		printf("0\n");
	else if(n==0)					//仅实部为零
		printf("%fi\n",m);
	else if(m==0)					//仅虚部为零
		printf("%f\n",n);
	else if(m>0)					//虚部大于零
		printf("%f+%fi\n",n,m);
	else							//虚部小于零
		printf("%f%fi\n",n,m);
}
void Add (complex *i,complex *j)	//加法
{
	i->real=i->real+j->real;
	i->img=i->img+j->img;
	Print(i);
}
void Sub (complex *i,complex *j)		//减法
{
	i->real=i->real-j->real;
	i->img=i->img-j->img;
	Print(i);
}
void Mul (complex *i,complex *j)		//乘积函数
{
	i->real=i->real*j->real;
	i->img=i->img*j->img;
	Print(i);
}
void Sep (complex *i)			//分离函数
{
	printf("real: %f\t,img: %f\t",i->real,i->img);
}
int menu()					//菜单函数，返回值作为循环判断依据
{	
	int a;
	printf("Select the function:\n 0.print;\n 1.Add;\n 2.Sub;\n 3.Mul;\n 4.Sep;\n 5.Exit\n");
	scanf("%d",&a);
	switch(a)
	{
	case 0: Print(p);break;								//打印
	case 1: InitComplex(q);Add(p,q);return 1;break;		//创建第二个复数并进行计算
	case 2: InitComplex(q);Sub(p,q);return 1;break;
	case 3: InitComplex(q);Mul(p,q);return 1;break;
	case 4: Sep(p);return 1;break;
	case 5: return 0;
	}
}

int main()
{
	p=&com_1;			//指针指向结构体
	q=&com_2;
	InitComplex(p);
	while(menu())		//判断循环是否结束
	{
		menu();
	}
}
