#include <iostream>
using namespace std;

void swapping(string& in, int i, int j) {
	char temp = in.at(i);
	in.at(i) = in.at(j);
	in.at(j) = temp;
}

void printperms(string input, int i) {
	if(i==input.size())
		cout << input << " ";
	else {
		for(int j=i; j<input.size(); j++) {
			swapping(input, i, j);
			printperms(input, i+1);
			swapping(input, j, i);
		}
	}

}

int main() {
	string input;
	cin >> input;
	printperms(input, 0);
}
