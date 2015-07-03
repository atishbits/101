#include <stdio.h>
#include <unistd.h>
int main () {
	if(fork()) 
		printf("MAGIC\n"); 
}
