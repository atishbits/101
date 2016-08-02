#include <iostream>
#include <vector>
using namespace std;

/*
http://www.geeksforgeeks.org/print-unique-rows/
Given a binary matrix, print all unique rows of the given matrix.
*/

struct BinTrieNode {
	bool val;
	struct BinTrieNode* zero;
	struct BinTrieNode* one;
};

bool BINTrie::insertWord(vector<bool>& boolWord) {
	bool newInsert = true;

	//empty Trie case
	if(_root == nullptr) {
		_root = new BinTrieNode();
		_root->zero = nullptr;
		_root->one = nullptr;
	}

	//now traverse the try and keep inserting bits when necessary
	BinTrieNode* current = _root;

	for(auto bit:boolWord) {
		if(bit) {
			if(!current->one) {
				createNode(current, bit);
				newInsert = true;
			}
			continue;
		}
		else {
			if(!current->zero) {
				createNode(current, bit);
				newInsert = true;
			}
			continue;
		}
	}
}

class BINTrie {
private:
	BinTrieNode* _root;
	void createNode(bool val, BinTrieNode* node);

public:
	Trie() {
		_root = nullptr;
	}
	bool insertWord(vector<bool>& boolWord);	//returns false if word exists
};

int main() {

}
