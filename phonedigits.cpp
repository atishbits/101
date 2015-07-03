/*
Given a keypad as shown in diagram, and a n digit number, list all words which
are possible by pressing these numbers.
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, string> hashTable = { {0,""}, {1,""},
								{2,"ABC"}, {3,"DEF"},
								{4,"GHI"}, {5,"JKL"},
								{6,"MNO"}, {7,"PQR"},
								{8,"STUV"}, {9,"WXYZ"}};


void printstrings(vector<int>& input, int pos, string str, int reqsize) {
	static int count = 0;
	if(str.size() == reqsize) {
		cout << ++count << ": " << str << endl;
		return;
	}

	string chars;

	while(1) {
		chars = hashTable[input[pos]];
		if(chars.empty()) {
			pos = pos+1;
			reqsize--;
		}
		else
			break;
	}
	string curr;

	for(int i=0;i<chars.size(); i++) {
		curr = str + chars[i];
		printstrings(input, pos+1, curr, reqsize);
	}
}

int main() {
	vector<int> input;
	int num, in;
	cin >> num;
	while(num--) {
		cin >> in;
		input.push_back(in);
	}

	printstrings(input, 0, "", input.size());
}
