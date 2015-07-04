#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cassert>
using std::string;
using std::cout;
using std::endl;

bool isAnagram(const string& str1, const string& str2) {

	if(str1.size() != str2.size())
		return false;	

	std::unordered_map<char, int> mCharCount1;
	
	//record chars of str1 in map
	for(auto& chr:str1) {
		if(!mCharCount1.count(chr))
			mCharCount1[chr] = 1;
		else
			mCharCount1[chr] = mCharCount1[chr] + 1;
	}

	//test if same chars exist in str2
	for(auto& chr:str2) {
		if(!mCharCount1.count(chr))
			return false;
		else
			mCharCount1[chr] -= 1;
	}	

	//test if all counts are zero in map
	std::unordered_map<char, int>::iterator itr;
	for(itr = mCharCount1.begin(); itr != mCharCount1.end(); itr++) {
		if(itr->second != 0)
			return false;
	}

	//everything succeeded
	return true;
}

int main() {

	string str1 = "hello";
	string str2 = "llohe";
	string str3 = "lloo";
	string str4 = "llool";
	

	assert(isAnagram(str1, str2));
	assert(!isAnagram(str1, str3));
	assert(!isAnagram(str1, str4));
}
