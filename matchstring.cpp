/*
Given a large string "text" and a smaller string "pattern". Find the minimum size window
in the string a which contains all the characters of the string pattern.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void getPatMap(unordered_map<char, int>& patMap, const string& pat) {
	for(const char& c:pat) {
		if(patMap.count(c)==0)
			patMap[c] = 1;
		else
			patMap[c] = patMap[c]+1;
	}
}

int main() {
	string text, pat;

	text = "abcladegfgedabclgdg";
	pat = "ggldb";
	unordered_map<char, int> patMap;
	getPatMap(patMap, pat);
}
