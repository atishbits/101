#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static bool comp(string a, string b) {
	sort(a.begin(), a.end());
	cout << "sorted a: " << a << endl;
	sort(b.begin(), b.end());
	cout << "sorted b: " << b << endl;
	sort(b.begin(), b.end());
	return strcmp(a.c_str(), b.c_str());
}

int main() {

	std::string s1 = "abcd";
	std::string s2 = "azb";
	std::string s3 = "zh";

	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s3);
	strs.push_back(s2);
	sort(strs.begin(), strs.end());

	for(int i=0; i<strs.size(); i++)
		cout << strs[i] << endl;

}
