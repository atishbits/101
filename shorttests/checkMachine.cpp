#include <iostream>
using namespace std;

int main() {

	int i = 10;
	int* iptr = &i;

	cout << sizeof(iptr) << " " << sizeof(i) << endl;
}
