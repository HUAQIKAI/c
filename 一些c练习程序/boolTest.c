#include <stdio.h>

typedef int cBool;

#define cTrue 1
#define cFalse 0

int main()
{
	cBool sex;
	scanf("%d", &sex);
	if (sex == cTrue)
	{
		printf("man\n");
	}
	else if(sex == cFalse)
	{
		printf("woman\n");
	}
	else
	{
		printf("error\n");
	}
	return 0;
}