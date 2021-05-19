/* ˳���˳���Ĳ���                            */
/* 1.����˳�����̬�����ڴ棩*/
/* 2.���롢ɾ�������ҡ��������Ļ*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef struct {    /*˳���ṹ��*/
	int data[MaxSize];  /*˳���������Ĵ�СΪ5*/
	int length;   /*˳���ĳ���*/
} SqList;          /*˳��������*/

typedef int bool;
#define true 1
#define false 0

/*��Ϊ�����ĸ�����������main����֮��*/
/*������Ҫ�������ĸ�����*/
bool ListInsert(SqList *L, int i, int e);/*����һ��Ԫ�ص�˳���*//*i��ʾ����λ�ã�e��ʾ��iλ��ǰ�������ֵ*/
bool ListDelete(SqList *L, int i);/*��˳���ɾ��һ��Ԫ��*/
int  LocateElem(SqList L, int e);/*����һ��Ԫ����˳����һ�γ��ֵ�λ��*/
void ListPrint(const SqList *L);/*��ӡ˳���*/

int main()
{
	int i = 0;    /*i��Ϊѭ��ʹ��*/
	SqList L;   /*����һ��˳���ṹ��L*/
	L.length = 0; /*��Ϊ���ڻ�û�в�������,����L�ĳ���Ϊ0*/

	/*���while��Ϊ����������,ÿ�������i++,��i=MaxSize��������*/
	printf("����%d��Ԫ��,ÿ����֮���ո�,��Ϻ󰴻س�\n",MaxSize);
	int tmp;
	while (i < MaxSize)
	{
		scanf("%d", &tmp);
		if (tmp == 444)
		{
			break;
		}
		L.data[i] = tmp;
		L.length++;            /*ÿ����һ������,L�ĳ�������1*/
		i++;                   /*ÿ��ѭ��i����1*/
	}
	/*������Ϻ��ӡL����Ļ*/
	ListPrint(&L);

	/*ִ�в������,��������Լ��޸�,������ʲô��һ��*/
	printf("�ڵ�3��Ԫ��ǰ�����10\n");
	if (ListInsert(&L, 3, 10) == true)
		ListPrint(&L);

	/*ִ��ɾ������,��������Լ��޸�,������ʲô��һ��*/
	printf("ɾ����4��Ԫ��\n");
	if (ListDelete(&L, 4) == true)
		ListPrint(&L);

	/*ִ�в��Ҳ���,��������Լ��޸�,������ʲô��һ��*/
	printf("����ֵΪ1��Ԫ����L�е�һ�γ��ֵ�λ��\n");
	printf("ֵΪ1��Ԫ����L�е�һ�γ��ֵ�λ��Ϊ%d\n", LocateElem(L, 1));

	return 0;
}

/*˳������Ԫ�صľ���ʵ��*/
bool ListInsert(SqList *L, int i, int e)
{
	printf("debugInfo:L->length = %d\n", L->length);
	if (i >= L->length + 1 || i < 0)    /*���ж�i�Ƿ�Ϊ��Чֵ */
	{
		printf("����λ�ô���.\n");
		return false;				  /*����ʧ��,����false*/
	}
	if (L->length >= MaxSize)           /*���ж�˳����Ƿ��Ѿ�����*/
	{
		printf("˳�������.\n");
		return false;                /*����ʧ��,����false*/
	}
	int j;
	for (j = L->length; j >= i; j--)    /*�ѵ�i��֮�������ȫ������һλ,�������Ϊ��λ��*/
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;              /*�ڿ�λ�ú󽫴�����Ԫ��e���뵽��i��λ��*/
	L->length++;                 /*��������1*/
	return true;                /*����ɹ�,����true*/
}
/*˳���ɾ��Ԫ�صľ���ʵ��*/
bool ListDelete(SqList *L, int i)
{
	if (i >= L->length || i < 1)        /*�ȼ��i�Ƿ�Ϊ��Чֵ*/
		return false;
	int j;
	for (j = i; j < L->length; j++)   /*��ʼ�ѱ�ɾ����ֵ�����ֵǰ��*/
	{
		L->data[j - 1] = L->data[j];
	}

	L->length--;                 /*���ȼ���1*/
	return true;
}
/*����˳���ֵΪe��Ԫ�ص�һ�γ��ֵ�λ��*/
int LocateElem(SqList L, int e)
{
	int i;
	for (i = 0; i < L.length; i++)  /*��forѭ���ӵ�һ��λ�ÿ�ʼ��*/
	{
		if (L.data[i] == e)         /*����ҵ��˾ͷ��ر��ҵ���Ԫ�ص��±�+1*/
		{
			return i + 1;          /*��Ϊ�±��0��ʼ��,������Ҫ�ҳ��ֵ�λ������Ҫ+1*/
		}
	}
	return 0;                    /*û���ҵ��ͷ���0*/
}
/*���������Ա�*/
void ListPrint(const SqList* L) 
{
	printf("��debugInfo��:start print data...\n");
	int i = 0;
	while ( (i < L->length) && (L->data[i] != (int)NULL) ) /*ֻҪ����iС�����Ա�ĳ�����i��Ӧ�����ݲ�Ϊ�վ������Ԫ��*/
	{
		printf("%d\n", L->data[i]);
		i++;                             /*ÿ��ѭ��i����1*/
	}
	printf("�������Ա�ĳ���Ϊ��");
	printf("%d\n", L->length);             /*������Ա�ĳ���*/
	printf("��debugInfo��:end print data...\n");
}
