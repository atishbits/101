// Program to detect if sign of input numbers is different
#include <iostream>

int main() {
	int in1 = 10;
	int in2 = 10;
	int inXor = in1 ^ in2;
	std::cout << (inXor > (sizeof(int)-1)) << std::endl;
}
