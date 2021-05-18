#include <stdio.h>
#include <time.h>
 
int main ()
{
  time_t seconds;
 
  seconds = time(NULL);
  printf("自 1970-01-01 起的小时数 = %ld\n", seconds/3600);
  printf("自 1970-01-01 起的分钟数 = %ld\n", seconds/60);
  printf("自 1970-01-01 起的秒数 = %ld\n", seconds);
  
  return(0);
}