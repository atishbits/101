#include <stdio.h>
struct test
{
   char c;
/*
   unsigned int x;
   unsigned int y;
   unsigned int z;
   double d;
   void* r;
   int a[0];
   char b;
*/
};
int main()
{
   printf("%lu\n", sizeof(struct test));
   return 0;
}
