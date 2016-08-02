#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
};
typedef struct node Node;

class Tree {
private:
	Node* _root;
	Node* search(const int data, Node* node);
	void insert(Node* node, Node* node);

public:
	Tree():_root(nullptr){};
	void insert(const int data);
	int distance(const int d1, const int d2);
};

Node* Tree::search(const int data, Node* node) {
	if(node->data == data)
		return node;

	search(data, node->lchild);
	search(data, node->rchild);
}

void Tree::insert(const int data) {
	Node* node = new Node;
	node->data = data;
	node->lchild = nullptr;
	node->rchild = nullptr;
	node->parent = nullptr;
	if(!_root) {
		_root = node;
		node->parent = nullptr;
	}
	else
		insert(_root, node);
}

bool Tree::insert(Node* tree, Node* node) {
	if(!tree->lchild) {
		tree->lchild = node;
		node->parent = tree;
		return true;
	}

	if(!tree->rchild) {
		tree->rchild = node;
		node->parent = tree;
		return true;
	}
	
	if(insert(tree->lchild, node)) return true;
	if(insert(tree->rchild, node))	return true;

	return false;
}
