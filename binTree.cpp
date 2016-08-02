#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

class Tree {
private:
	Node* _root;

public:
	Tree() {
		_root = nullptr;
	}
	void insert(int data);
	void printTree();
	void sumTree();
};

void Tree::insert(int data) {
	if(!_root) {
		_root = new Node;
		_root->left = nullptr;	
		_root->right = nullptr;	
	}
}

int main() {
	Tree newTree;
	newTree.insert(5);
	newTree.insert(-2);
	newTree.insert(6);
	newTree.insert(18);
	newTree.insert(22);

	newTree.printTree();
	
	newTree.sumTree();
	newTree.printTree();
}
