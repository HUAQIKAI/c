/*ð�������㷨*/
/*ð�������㷨����ʲô�õģ�*/
/*ð�������㷨��������ʲô��*/
/*ð�������㷨�����������㷨�����ʲôȱ�ݣ�*/
/*ð�������㷨���㷨����˼����ʲô��*/
/*ð�������㷨��Ӧ�ó���һ����ʲô�ط���*/
/*ð�������㷨�ľ�������ʲô�ط�?*/
/*ð�������㷨��������ó�����ʲô��*/
/*ð�������㷨���ʵ��?*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int data[], size_t len)
{
	printf("bubbleSort--start.\n");
	printf("dataLen = %d\n", len);
	int i, j;
	clock_t clockStart, clockEnd;
	double useClock;
	clockStart = clock();
	printf("clockStart = %ld\n", clockStart);
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (data[j] > data[j+1]) {        // ����Ԫ�������Ա�
                int temp = data[j+1];        // Ԫ�ؽ���
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
	clockEnd = clock();
	useClock = (double)(clockEnd - clockStart) / CLOCKS_PER_SEC;
	printf("clockEnd = %ld\n", clockEnd);
	printf("useClock = %lf��\n", useClock);
	printf("bubbleSort--end.\n");
}

void printData(int data[], size_t len)
{
	int i;
	printf("debugInfo:line = %d|sizeof(data) = %d\n", __LINE__, sizeof(data));
	printf("debugInfo:line = %d|sizeof(int) = %d\n", __LINE__, sizeof(int));
	for (i = 0; i < len; ++i)
	{
		printf("(%d)", data[i]);
		if(((i + 1) % 5) == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

void initData(int data[], size_t len)
{
   int i, n;
   time_t t;
   
   n = 5;
   n = len;
   /* ��ʼ������������� */
   srand((unsigned) time(&t));
 
   /* ��� 0 �� 50 ֮��� 5 ������� */
   for( i = 0 ; i < n ; i++ ) {
      /*printf("%d\n", rand() % 50);*/
	  data[i] = rand() % 10000;
   }
}
#define yibai       100
#define yiqian      1000
#define yiwan       10000
#define shiwan      100000
#define yibaiwan    1000000
#define yiqianwan   10000000
#define yiyi        100000000

# define n 100 /* n �ɸ�����Ҫ����,����ٶ�Ϊ100*/
void MatrixMultiply(int A[n][n], int B[n][n], int C[n][n])
{ /*�ұ���Ϊ������Ƶ��*/
    int i, j, k;
    for(i=0; i<n; i++) {  /*n+1*/
        for (j=0; j<n; j++) { /*n*(n+1)*/
          C[i][j] = 0; /*n2*/
          for (k=0; k<n; k++) {  /*n2*(n+1)*/
            C[i][j] = C[i][j] + A[i][k] * B[k][j];  /*n3*/
          }
        }
    }
}

void selectionSort(int data[], size_t len) {

    int minIndex, temp;
	int i, j;
    for (i = 0; i < len - 1; i++) { /*ѡ���������*/
        minIndex = i;
        for (j = i + 1; j < len; j++) {	/*����������*/
            if (data[j] < data[minIndex]) {     /* Ѱ����С���� */
                minIndex = j;                 /* ����С������������*/
            }
        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
}



int main()
{
	int data[shiwan];
	size_t dataLen = sizeof(data) / sizeof(int);
	printf("debugInfo:line = %d|sizeof(data) = %d\n", __LINE__, sizeof(data));
	printf("debugInfo:line = %d|sizeof(int) = %d\n", __LINE__, sizeof(int));
	printf("debugInfo:line = %d|dataLen = %d\n", __LINE__, dataLen);
	initData(data, dataLen);
/*	printData(data, dataLen);*/
	bubbleSort(data, dataLen);
/*	printData(data, dataLen);*/

	return 0;
}