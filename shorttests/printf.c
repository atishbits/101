#include <stdio.h>

void print()
{
	int i = 1;
	printf("%d %d %d", ++i, i, i++);
}


int main()
{
  print();
} 

/*
int main(int argc , char *argv[])
{
	//while(argc) {
		printf("%c\n",**++argv);
	//	argc -= 1;
	//}
}
*/
