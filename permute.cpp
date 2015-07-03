#include <iostream>

void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
 * This function takes three parameters
 * string a
 * start index of string i
 * end index of string n
*/
void permute(char* str, int start, int end)
{
	int j;
	if(start == end)
		printf("%s\n", str);
	else
	{
		for (j = start; j <= end; j++)
		{
			swap((str+start), (str+j));
			permute(str, start+1, end);
			swap((str+start), (str+j)); //backtrack
		}
	}
}

int main()
{
	char str[] = "ABC";
	permute(str, 0, 2);
}
