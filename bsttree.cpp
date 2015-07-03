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
	Node* find(Node* node, int data);
	void printdfs(Node* node);

	void printRevTree(Node* node) const;
	void inorderSucc(const int data, Node* node);
	const int minVal(Node* node) const;
	
public:
	BST();
	void insert(int data);
	void printTree();
	void printbfs();
	void printlevelwise();
	void printLeft();
	Node* find(int data) {
		Node* node = find(root, data);
		return node;
	}
	void printdfs() {
		printdfs(root);
	}

	void printRevTree() {
		printRevTree(root);
	}

	void inorderSucc(const int data) {
		//1. find the node	
		Node* node = find(data);

		if(!node) { 
			cout << "Node not found" << endl;
			return;
		}

		inorderSucc(data, node);

	}

};

const int BST::minVal(Node* node) const {
	int min = INT_MAX;

	if(!node)
		return min;

	while(node) {
		if(node->data < min)
			min = node->data;
		node = node->l;	
	}
	return min;
}

void BST::inorderSucc(const int data, Node* node) {
	if(node->r) {
		cout << "Succ: " << minVal(node->r) << endl;
		return;
	}

	Node* curr = root;
	Node* succ = nullptr;

	while(curr) {
		if(curr->data > data) {
			succ = curr;
			curr = curr->l;
		}
		else if(curr->data < data) {
			curr = curr->r;
		}
		else
			break;
	}

	if(succ)
		cout << "Succ: " << succ->data << endl;
	else
		cout << "No succ found" << endl;
}
void BST::printRevTree(Node* node) const {
	if(!node)
		return;

	printRevTree(node->r);
	cout << node->data << " ";
	printRevTree(node->l);
}

void BST::printdfs(Node* node) {
	if(!node)
		return;
	
	cout << node->data << endl;

	printdfs(node->l);
	printdfs(node->r);
}

Node* BST::find(Node* node, int data) {
	Node* ret;

	if (!node)
		return nullptr;

	if(data == node->data)
		return node;

	if(data > node->data)
		ret = find(node->r, data);
	else 
		ret = find(node->l, data);

	return ret;
}

BST::BST() {
	root = nullptr;
}

void BST::printlevelwise() {
	Node* node = root;
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

void BST::printLeft() {
	if(!root)
		return;
	vector<vector<Node*>> vlevels;
	int level=0;
	vlevels.push_back(vector<Node*>());
	vlevels[level].push_back(root);
	while(1) {
		int count = 0;
		for(Node*& node: vlevels[level]) {
			vlevels.push_back(vector<Node*>());
			//print the left most node at this level
			if(!node)
				break;
			if(!count) {
				cout << node->data << endl;
			}
			if(node->l)
				vlevels[level+1].push_back(node->l);
			if(node->r)
				vlevels[level+1].push_back(node->r);
			count++;
		}
		if(!vlevels[level+1].size())
			break;
		vlevels[level].clear();		//previous level not required
		level++;
	}
}

void BST::printbfs() {
	queue<Node*> q;
	cout << "bfs start" << endl;
	
	q.push(root);
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
	cout << "bfs done" << endl;
	
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
	tree.insert(205);
	tree.insert(505);
	tree.insert(705);
	//tree.printTree();
	//tree.printbfs();
	tree.printlevelwise();
	//cout << "print lefts " << endl;
	//tree.printLeft();

	Node* n1 = tree.find(200);
	Node* n2 = tree.find(7);
	cout << "n1 " << n1->data << " n2 " << n2->data << endl;

	//tree.printdfs();

	tree.printRevTree();
	cout << endl;

	tree.inorderSucc(1);

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
