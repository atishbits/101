#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct node {
	int data;
	struct node* l;
	struct node* r;
};
typedef struct node Node;

class BST {
private:
	Node* root;
	Node* insert(int data, Node* node);
	void printTree(Node* node);
	void printbfs(Node* node);
	void printlevelwise(Node* node);
	
public:
	BST();
	void insert(int data);
	void printTree();
	void printbfs();
	void printlevelwise();
};

BST::BST() {
	root = nullptr;
}

void BST::printlevelwise(Node* node) {
	queue<Node*> q;
	cout << "level wise start" << endl;
	
	int level = 0;
	int expected = 1;

	vector<int> vlnodes;

	q.push(node);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		expected--;
		if(temp) {
			vlnodes.push_back(temp->data);
			q.push(temp->l);
			q.push(temp->r);
		}

		if(!expected) {
			cout << "level " << level++ << endl;
			for(int& d:vlnodes)
				cout << d << " ";
			vlnodes.clear();
			expected = pow(2, level);	
			cout << endl;
		}
	}
	//print any left over nodes
	if(vlnodes.size()) {
		cout << "level " << level++ << endl;
		for(int& d:vlnodes)
			cout << d << " ";
		vlnodes.clear();
		cout << endl;

	}
	
}
void BST::printlevelwise() {
	printlevelwise(root);
}

void BST::printbfs(Node* node) {
	queue<Node*> q;
	cout << "bfs start" << endl;
	
	q.push(node);
	while(!q.empty()) {
		Node* temp = q.front();
		if(temp != nullptr)
		{
			cout << temp->data << " ";
			q.push(temp->l);
			q.push(temp->r);
		}
		q.pop();
	}
	
}
void BST::printbfs() {
	printbfs(root);
	cout << endl << "bfs done" << endl;
}
//prints inorder
void BST::printTree(Node* node) {
	if(node == nullptr)
	{
		return;
	}
	printTree(node->l);
	cout << node->data << endl;
	printTree(node->r);
}

void BST::printTree() {
	cout << "print inorder start" << endl;
	printTree(root);
	cout << "print inorder done" << endl;
	
}

Node* createNode(int data) {
	Node* newnode = new Node;
	newnode->data = data;
	newnode->l = nullptr;
	newnode->r = nullptr;
	return newnode;
}

Node* BST::insert(int data, Node* node) {

	if (node==nullptr) {
		node = createNode(data);
		return node;
	}

	if(data <= node->data)
		node->l= insert(data, node->l);
	else
		node->r = insert(data, node->r);
	
	return node;
}

void BST::insert(int data) {
	root = insert(data, root);
}

int main() {
	BST tree;
	tree.insert(6);
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(2);
	tree.insert(200);
	tree.printTree();
	tree.printbfs();
/*
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(600);
	tree.printTree();
	tree.printbfs();
	tree.printlevelwise();
*/	
	
}
