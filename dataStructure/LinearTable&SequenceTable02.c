/* ˳���˳���Ĳ���                            */
/* 1.����˳�����̬�����ڴ棩*/
/* 2.���롢ɾ�������ҡ��������Ļ*/
#include<stdio.h>
#include<stdlib.h>
#define InitSize 5       /*��ʼ����СΪ5*/

typedef struct {         /*����һ����̬����ռ�Ľṹ�� ˳���*/
	int *data;           /*int����ָ��*/
	int length;			 /*��ǰ�ߴ�*/
	int MaxSize;      /*���趨SqList���ߴ���10,Ҳ��������10��Ԫ��*/
} SqList;

/*��Ϊ�����ĸ�����������main����֮��*/
/*������Ҫ�������ĸ�����*/
bool ListInsert(SqList &L, int i, int e);/*����һ��Ԫ�ص�˳���*/
bool ListDelete(SqList &L, int i);/*��˳���ɾ��һ��Ԫ��*/
int  LocateElem(SqList L, int e);/*����һ��Ԫ����˳����һ�γ��ֵ�λ��*/
void ListPrint(SqList L);/*��ӡ˳���*/

int main()
{
	int i = 0;    /*i��Ϊѭ��ʹ��*/
	SqList L;
	L.MaxSize = 10;
	L.data=(int*)malloc(sizeof(int)*InitSize);/*�����ڴ�ռ�*/
	L.length = 0; /*��Ϊ���ڻ�û�в�������,����L�ĳ���Ϊ0*/

	/*���while��Ϊ����������,ÿ�������i++*/
	printf("����%d��Ԫ��,ÿ����֮���ո�,��Ϻ󰴻س�\n", InitSize);
	while ((i < InitSize) && (L.length < L.MaxSize))
	{
		scanf_s("%d", &L.data[i]);/*��������,�����õ�scanf_s,�ȼ���scanf*/
		L.length++;            /*ÿ����һ������,L�ĳ�������1*/
		i++;                   /*ÿ��ѭ��i����1*/
	}
	/*������Ϻ��ӡL����Ļ*/
	ListPrint(L);

	/*ִ�в������,��������Լ��޸�,������ʲô��һ��*/
	printf("�ڵ�3��Ԫ��ǰ�����10\n");
	if (ListInsert(L, 3, 10) == true)
		ListPrint(L);
	/*ִ��ɾ������,��������Լ��޸�,������ʲô��һ��*/
	printf("ɾ����4��Ԫ��\n");
	if (ListDelete(L, 4) == true)
		ListPrint(L);

	/*ִ�в��Ҳ���,��������Լ��޸�,������ʲô��һ��*/
	printf("����ֵΪ1��Ԫ����L�е�һ�γ��ֵ�λ��\n");
	printf("ֵΪ1��Ԫ����L�е�һ�γ��ֵ�λ��Ϊ%d\n", LocateElem(L, 1));

	return 0;
}

/*˳������Ԫ�صľ���ʵ��*/
bool ListInsert(SqList *L, int i, int e)
{
	if (i >= L.length + 1 || i < 0 || L.length >= L.MaxSize)/*���ж�i�Ƿ�Ϊ��Чֵ,L.length�Ƿ񳬳������Ŀռ�*/
		return false;				  /*����ʧ��,����false*/
	/*realloc���Զ�̬�ı�ָ��ָ���ڴ�Ĵ�С*/
	/*�÷��� ָ���� =����������*��realloc��Ҫ�ı��ڴ��С��ָ�������µĴ�С����*/
	(int *)realloc(L.data, (L.length + 1) * sizeof(int));
	int *j;
	int *k;
	j = &(L.data[i - 1]);/*jָ��ʵ�ʲ����λ��*/
	for (k = &(L.data[L.length-1]); k >= j; k--)    /*�ѵ�j��֮�������ȫ������һλ,�������Ϊ��λ��*/
	{
		*(k + 1) = *k;
	}
	*j = e;              /*�ڿ�λ�ú󽫴�����Ԫ��e���뵽��j��λ��*/
	L.length++;          /*��������1*/
	return true;         /*����ɹ�,����true*/
}
/*˳���ɾ��Ԫ�صľ���ʵ��*/
bool ListDelete(SqList &L, int i)
{
	if (i >= L.length || i < 1)        /*�ȼ��i�Ƿ�Ϊ��Чֵ*/
		return false;
	int *j = &(L.data[i - 1]);/*��Ҫɾ����Ԫ��λ��*/
	int *k = &(L.data[L.length - 1]);/*���һ��Ԫ�ص�λ��*/
	for (; j < k; j++)   /*��ʼ�ѱ�ɾ����ֵ�����ֵǰ��*/
	{
		*(j) = *(j + 1);
	}
	L.length--;                 /*���ȼ���1*/
	return true;
}
/*����˳���ֵΪe��Ԫ�ص�һ�γ��ֵ�λ��*/
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)  /*��forѭ���ӵ�һ��λ�ÿ�ʼ��*/
	{
		if (L.data[i] == e)         /*����ҵ��˾ͷ��ر��ҵ���Ԫ�ص��±�+1*/
		{
			return i + 1;          /*��Ϊ�±��0��ʼ��,������Ҫ�ҳ��ֵ�λ������Ҫ+1*/
		}
	}
	return 0;                    /*û���ҵ��ͷ���0*/
}
/*���������Ա�*/
void ListPrint(SqList L)
{
	int i = 0;
	while (i < L.length && L.data[i] != NULL) /*ֻҪ����iС�����Ա�ĳ�����i��Ӧ�����ݲ�Ϊ�վ������Ԫ��*/
	{
		printf("%d\n", L.data[i]);
		i++;                             /*ÿ��ѭ��i����1*/
	}
	printf("�������Ա�ĳ���Ϊ��");
	printf("%d\n", L.length);             /*������Ա�ĳ���*/
	printf("------------------------------\n");
}
