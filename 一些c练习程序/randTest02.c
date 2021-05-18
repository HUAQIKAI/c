#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
   int i, n;
   time_t t;
   printf("RAND_MAX = %lu\n", RAND_MAX);
   n = 15;
   
   /* 初始化随机数发生器 */
   srand((unsigned) time(&t));
 
   /* 输出 0 到 49 之间的 5 个随机数 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
  return(0);
}