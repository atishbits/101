#include <iostream>

bool isUniqueChars(std::string str)
{
	int checker = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		int val = str.at(i) - 'a';
		if((checker & (1<<val)) > 0)
		{
			std::cout << "returning false " << str.at(i)
				<< std::endl;
			return false;
		}
		checker |= (1<<val);
		std::cout << " value of checker " << checker
			<< " value of val " << val 
			<< " value of string " << str.at(i) << std::endl;
	}
	return true;
}

int main()
{
	std::cout << isUniqueChars("aba") << " was returned " << std::endl;
}
