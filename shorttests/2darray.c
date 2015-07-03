#include <stdio.h>
#include <stdlib.h>

int main() {
int N = 3;
int M = 3;
int *x[N];
x=(int(*)[N])malloc(M*sizeof(*x));
printf("%d %d",sizeof(x),sizeof(*x));
}
