#include <stdio.h>
#include <time.h>
 
int main ()
{
   time_t curtime;
 
   time(&curtime);
 
   printf("��ǰʱ�� = %s", ctime(&curtime));
 
   return(0);
}
