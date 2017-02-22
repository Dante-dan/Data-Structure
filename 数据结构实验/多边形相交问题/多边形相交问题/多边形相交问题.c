#include "list.h"
void Input(Sqlist *L,int i)
{
	//输入函数，将输入的数据存储到顺序表当中
	ElemType ori,temp;
	temp.x=-1000;
	temp.y=-1000;
	printf("请输入第%d个多边形的第1个点坐标(x,y):\t",i);
	scanf("%f,%f",&ori.x,&ori.y);
	Append(L,ori);
	while(1)
	{
		if(ori.x==temp.x&&ori.y==temp.y) {Append(L,temp);printf("第%d个多边形结束\n",i);break;}	//输入的终点=起始点时输入结束，此时为一个闭合封闭的图形
		else 
		{
			printf("请输入第个%d多边形的第%d个点坐标(x,y):\t",i,(L->length+1));
			scanf_s("%f,%f",&temp.x,&temp.y);
			Append(L,temp);																		//插入节点
		}
	}
}

//aa, bb为一条线段两端点 cc, dd为另一条线段的两端点 相交返回true, 不相交返回false 
bool iscross(point aa, point bb, point cc, point dd)											//返回BOOL型变量
{ 
	//跨立实验和快速排斥实验
    return Max(aa.x, bb.x)>=Min(cc.x, dd.x) 
        && Max(aa.y, bb.y)>=Min(cc.y, dd.y) 
        && Max(cc.x, dd.x)>=Min(aa.x, bb.x) 
        && Max(cc.y, dd.y)>=Min(aa.y, bb.y) 
        && mult(cc, bb, aa)*mult(bb, dd, aa)>=0 
        && mult(aa, dd, cc)*mult(dd, bb, cc)>=0; 
}
int main()
{
	bool flag;
	int i,j,n=0;
	ElemType inter_point;
	Sqlist L,S;
	Sqlist *p,*q;
	p=&L;
	q=&S;
	printf("***********当最后的坐标等于最开始的坐标时视为输入结束*************\n");
	InitList_Sq(p);
	InitList_Sq(q);
	Input(p,1);
	Input(q,2);
	for(i=0;i<L.length-1;i++)
	{
		for(j=0;j<S.length-1;j++)
		{
			flag = iscross(L.elem[i],L.elem[i+1],S.elem[j],S.elem[j+1]);
			if(flag==1) 
			{
				n++;
				//printf("(%f,%f)-(%f,%f)\t(%f,%f)-(%f,%f)\n",L.elem[i].x,L.elem[i].y,L.elem[i+1].x,L.elem[i+1].y,S.elem[j].x,S.elem[j].y,S.elem[j+1].x,S.elem[j+1].y);
				inter_point=intersection_point(L.elem[i],L.elem[i+1],S.elem[j],S.elem[j+1]);
				printf("(%f,%f)\n",inter_point.x,inter_point.y);
			}
		}
	}																							//判断是否相交并输出交点
	if(n>0) printf("以上为图形的交点\n交点有%d个\n",n);
	else printf("两图形不相交\n");
	system("pause");
}

