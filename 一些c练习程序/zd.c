#include <stdio.h>
  int main (void)
  {  int i;
     size_t uzs = 1;
     ssize_t zs = -1;
     size_t test = 0xffffffffffffffff;
     ssize_t stest = 0x8000000000000000;
    for ( i= 0; i<5 ;i++, uzs <<= 16,zs <<= 16 )
    {
       printf ("uzs %%zu:%zu\n", uzs);
       printf ("uzs %%zd:%zd\n", uzs);
       printf ("uzs %%x:0x%lx\n", uzs);
       printf ("zs %%ld:%ld\n", zs);
       printf ("zs %%zu:%zu\n", zs);
       printf ("zs %%zd:%zd\n", zs);
       printf ("zs %%x:0x%lx\n", zs);
       printf("\n");
    }
	
	printf("test is %d\n", test);
	printf("test is %ld\n", test);
	printf("test is %zd\n", test);
	printf("test is %u\n", test);
	printf("test is %lu\n", test);
	printf("test is %zu\n", test);
	
	
	printf("stest is %d\n", stest);
	printf("stest is %ld\n", stest);
	printf("stest is %zd\n", stest);
	printf("stest is %u\n", stest);
	printf("stest is %lu\n", stest);
	printf("stest is %zu\n", stest);
    return 0;
}
