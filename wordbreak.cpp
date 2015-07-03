/*
Given an input string and a dictionary of words, find out if the input string
can be segmented into a space-separated sequence of dictionary words.
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isDict(string str) {
	static const map<string, bool> dict = {{"i", true}, 
											{"like", true},
											{"am", true},
											{"hello", true}, 
											{"world", true}};

	if(dict.count(str))
		return true;
	else
		return false;
}

bool isWordBreak(string str) {
	//create a 2-d NxN vector, N is len of str
	vector<vector<bool> > table;

	//initialize the table
	for(int i=0; i<str.size(); i++) {
		table.push_back(vector<bool>());
		for(int j=0; j<str.size(); j++) {
			if(i==j)
				table[i].push_back(isDict(str.substr(i,j-i+1)));
			else
				table[i].push_back(false);
		}
	}

	int len = 1;
	int j;
	while(len<=str.size()) {
		for(int i=0; i<str.size(); i++) {
			j = i + len;

			if(isDict(str.substr(i,j-i+1))) 
				table[i][j] = true;
			else {
				int k = i;

				while(k<=j) {
					if(table[i][k] && table[k+1][j]) {
						table[i][j] = true;
						break;
					}
					table[i][j] = false;
					k++;
				}
			}
		}
		len++;
	}
	return table[0][str.size()-1];
}

//ex: iamlike
//ex: amilucy
int main() {
	string input;
	cin >> input;
	cout << isWordBreak(input) << endl;
}
