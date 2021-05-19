/*冒泡排序算法*/
/*冒泡排序算法是做什么用的？*/
/*冒泡排序算法的优势是什么？*/
/*冒泡排序算法与其它排序算法相比有什么缺陷？*/
/*冒泡排序算法的算法核心思想是什么？*/
/*冒泡排序算法的应用场景一般在什么地方？*/
/*冒泡排序算法的局限性在什么地方?*/
/*冒泡排序算法的最佳适用场景是什么？*/
/*冒泡排序算法如何实现?*/
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
            if (data[j] > data[j+1]) {        // 相邻元素两两对比
                int temp = data[j+1];        // 元素交换
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
	clockEnd = clock();
	useClock = (double)(clockEnd - clockStart) / CLOCKS_PER_SEC;
	printf("clockEnd = %ld\n", clockEnd);
	printf("useClock = %lf秒\n", useClock);
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
   /* 初始化随机数发生器 */
   srand((unsigned) time(&t));
 
   /* 输出 0 到 50 之间的 5 个随机数 */
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

# define n 100 /* n 可根据需要定义,这里假定为100*/
void MatrixMultiply(int A[n][n], int B[n][n], int C[n][n])
{ /*右边列为各语句的频度*/
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
    for (i = 0; i < len - 1; i++) { /*选择排序次数*/
        minIndex = i;
        for (j = i + 1; j < len; j++) {	/*遍历无序区*/
            if (data[j] < data[minIndex]) {     /* 寻找最小的数 */
                minIndex = j;                 /* 将最小数的索引保存*/
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