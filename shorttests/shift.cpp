#include <iostream>
extern "C"{
#include <unistd.h>
};
using namespace std;

int main() {
	int a = 7;
	cout << (a >> 1) << endl;
	if(fork()) 
		printf("MAGIC\n"); 
}
