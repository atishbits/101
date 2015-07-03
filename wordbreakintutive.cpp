#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

bool isInDict(const string& str) {
	static const map<string, bool> dict = {{"shop", true},
											{"shopping", true},
											{"with", true},
											{"pingwithf", true},
											{"flipkart", true},
											{"kart", true},
											{"is", true},
											{"easy", true}};

	if(dict.count(str))
		return true;
	else 
		return false;

}

bool printProper(const string input, vector<bool>& trackW, int pos,
	stack<string>& out) {
	string temp;
	int count = 0;
	for(int i=pos; i<input.size(); i++) {
		temp = input.substr(pos, ++count);
		if(trackW.at(i) || isInDict(temp)) {
			trackW.at(i) = true;
			bool ret;
			if(i < input.size()-1)
				ret = printProper(input, trackW, i+1, out);
			else 
				ret = true;
			if(ret) {
				out.push(temp);
				return true;
			}
		}
	}
	return false;
}

int main() {
	string in = "shoppingwithflipkartiseasy";
	vector<bool> trackWords(in.size(), false);
	stack<string> out;
	bool res = printProper(in, trackWords, 0, out);

	if(res) {
		while(!out.empty()) {
			cout << out.top() << " ";
			out.pop();
		}
	}
	cout << endl;
}
