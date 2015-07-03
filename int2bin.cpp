#include <iostream>
using std::cin;

int main()
{
	int input;
	cin >> input;
	std::string binary = "";
	while(input)
	{
		int r = input % 2;
		input >>= 1;
		binary = std::to_string(r) +  binary;
	}

	std::cout << binary << std::endl;
	return 0;
}
