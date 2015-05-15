#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
	char data;
	vector<struct node*> child;
};
typedef struct node Node;

void printandpopulate(map<int,vector<Node*>>& lmap, int level, int i) {
	cout << lmap[level].at(i)->data << " ";
	for(int j=0;j<lmap[level].at(i)->child.size(); j++) {
		lmap[level+1].
			push_back(lmap[level].at(i)->child[j]);
	}

}

void printzigzag(Node* node) {
	bool rev = true;
	int level = 0;
	map<int, vector<Node*>> lmap;
	lmap[level].push_back(node);
	while(1) {
		if(rev) {
			for(int i=lmap[level].size()-1; i>=0; i--)
				printandpopulate(lmap, level, i);
		}
		else {
			for(int i=0; i<lmap[level].size(); i++)
				printandpopulate(lmap, level, i);
		}

		if(!lmap[level+1].size())
			break;

		rev = !rev;
		level++;
		cout << endl;
	}
	cout << endl;
}

void printtree(Node* node) {
	if(node)
		cout << node->data << endl;
	else
		return;

	if(!node->child.size()) {
		return;
	}

	for(Node*& ch:node->child) {
		printtree(ch);
	}

}

int main() {
	Node* root = new Node;
	root->data = 'A';
	int i=3;
	char d = 'B';
	while(i--) {
		Node* newnode = new Node;
		newnode->data = d++;
		root->child.push_back(newnode);
	} 
	for(int i=0; i<root->child.size(); i++) {
		int j = 3;
		while(j--) {
			Node* newnode = new Node;
			newnode->data = d++;
			root->child[i]->child.push_back(newnode);
		}
	}
	printtree(root);
	cout << "printing zigzag" << endl;
	printzigzag(root);

}
