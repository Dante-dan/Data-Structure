#include "list.h"
void Input(Sqlist *L,int i)
{
	//���뺯��������������ݴ洢��˳�����
	ElemType ori,temp;
	temp.x=-1000;
	temp.y=-1000;
	printf("�������%d������εĵ�1��������(x,y):\t",i);
	scanf("%f,%f",&ori.x,&ori.y);
	Append(L,ori);
	while(1)
	{
		if(ori.x==temp.x&&ori.y==temp.y) {Append(L,temp);printf("��%d������ν���\n",i);break;}	//������յ�=��ʼ��ʱ�����������ʱΪһ���պϷ�յ�ͼ��
		else 
		{
			printf("������ڸ�%d����εĵ�%d��������(x,y):\t",i,(L->length+1));
			scanf_s("%f,%f",&temp.x,&temp.y);
			Append(L,temp);																		//����ڵ�
		}
	}
}

//aa, bbΪһ���߶����˵� cc, ddΪ��һ���߶ε����˵� �ཻ����true, ���ཻ����false 
bool iscross(point aa, point bb, point cc, point dd)											//����BOOL�ͱ���
{ 
	//����ʵ��Ϳ����ų�ʵ��
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
	printf("***********��������������ʼ������ʱ��Ϊ�������*************\n");
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
	}																							//�ж��Ƿ��ཻ���������
	if(n>0) printf("����Ϊͼ�εĽ���\n������%d��\n",n);
	else printf("��ͼ�β��ཻ\n");
	system("pause");
}

