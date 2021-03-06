#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    vector<Node*> getPathTo(int value);
	Node* insert(int data, Node* node);
	void printTree(Node* node);
	Node* find(Node* node, int data);
	void printdfs(Node* node);

	void printRevTree(Node* node) const;
	void inorderSucc(const int data, Node* node);
	const int minVal(Node* node) const;
    void dfsPathUtil(Node* node, stack<Node*>& vPath, int value, bool& found);
	
public:
	BST();
    void dfsPath(int value);
	void insert(int data);
    Node * lca(int v1,int v2);
	void printTree();
	void printbfs();
	void printlevelwise();
	void printLeft();
	void printzigzag();
    bool isBST();
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

void BST::dfsPathUtil(Node* node, stack<Node*>& vPath, int value, bool& found) {
    if (!node || found) 
        return;
    vPath.push(node);
    if(node->data == value) {
        found = true;
        return;
    }
    dfsPathUtil(node->l, vPath, value, found);
    dfsPathUtil(node->r, vPath, value, found);
    if(!found) {
        vPath.pop();
    }
}
	
//function to print path to a node with some value in the tree
//assumes it is not a BST (just trying out DFS for tree)
void BST::dfsPath(int value) {
    stack<Node*> vPath;
    bool found = false;
    dfsPathUtil(root, vPath, value, found);
    if(found) {
        int len = vPath.size();
        cout << "Path to node" << endl;
        for(int i = 0; i<len; i++) {
            cout << vPath.top()->data << " ";
            vPath.pop();
        }
        cout << endl;
    }
}

vector<Node*> BST::getPathTo(int value) {
    vector<Node*> path;
    Node* current = root;
    while(1) {
        path.push_back(current);
        if(current && current->data == value)
            return path;
        else if(current && value < current->data) {
            current = current->l;
        }
        else if(current) {
            current = current->r;
        }
        else {
            cout << "node is NULL??" << endl;
            return path;
        }
    }
}

Node* BST::lca(int v1,int v2)
{
    vector<Node*> pathv1;
    vector<Node*> pathv2;
    pathv1 = getPathTo(v1);
    pathv2 = getPathTo(v2);
    int count = 0;
    while(pathv1[count] == pathv2[count]) {
        count++;
    }
    return pathv1[--count];
}

void BST::printzigzag() {
	vector<Node*> vfor;
	vector<Node*> vback;

	bool isvfor = true;

	vfor.push_back(root);

	while(vfor.size() || vback.size()) {
		if(isvfor) {
			for(auto& elem:vfor) {
				cout << elem->data << " ";
				if(elem->l)
					vback.push_back(elem->l);
				if(elem->r)
					vback.push_back(elem->r);
			}
			vfor.clear();
			isvfor = false;
		}
		else {
			int sz = vback.size() - 1;
			for(int i=sz; i >= 0; i--) {
				cout << vback.at(i)->data << " "; 
				Node* elem = vback.at(sz - i);
				if(elem->l)
					vfor.push_back(elem->l);
				if(elem->r)
					vfor.push_back(elem->r);
			}
			vback.clear();
			isvfor = true;
		}
		cout << endl;
	}
}

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

void BST::printlevelwise() {
    if (!root)
        return;
    queue<node*> level;
    level.push(root);
    node* temp;
    while(!level.empty()) {
        temp = level.front();
        cout << temp->data << " ";
        if(temp->l)
            level.push(temp->l);
        if(temp->r)
            level.push(temp->r);
        level.pop();
    }  
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
	tree.printTree();
	tree.printbfs();
    tree.dfsPath(705);
    //Node* node = tree.lca(200, 205);
    //cout << "LCA is "<< node->data << endl;
	//tree.printlevelwise();
	//cout << "print lefts " << endl;
	//tree.printLeft();

	//Node* n1 = tree.find(200);
	//Node* n2 = tree.find(7);
	//cout << "n1 " << n1->data << " n2 " << n2->data << endl;

	//tree.printdfs();

	//tree.printRevTree();
	//cout << endl;

	//tree.inorderSucc(1);

	//cout << "printing zigzag" << endl;
	//tree.printzigzag();

}
