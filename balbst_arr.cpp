/*
Given a sorted integer array. Convert it to a balanced BST
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	struct Node* r;
	struct Node* l;
};

class BalBST {
private:
	Node* _root;
	void makeBalBST(const vector<int>& vSorted, int start, int end, Node*& node);

	Node* createNode(const int data) const {
		Node* temp = new Node;
		temp->data = data; 
		temp->l = temp-> r = nullptr;
		return temp;
	}

	bool isBSTUtil(Node* node, int min, int max);

public:
	BalBST() {
		_root = nullptr;
	};
	void makeBalBST(const vector<int>& vSorted) {
		makeBalBST(vSorted, 0, vSorted.size()-1, _root);
	}

	void printBST() const;

	bool isBST() {
	  return(isBSTUtil(_root, INT_MIN, INT_MAX));
	}
	
};

/*
 Returns true if the given tree is a BST and its
 values are >= min and <= max.
*/
bool BalBST::isBSTUtil(Node* node, int min, int max) {
  if (node==NULL) return(true);
  // false if this node violates the min/max constraint
  if (node->data<min || node->data>max) return(false);
  // otherwise check the subtrees recursively,
  // tightening the min or max constraint
  return (
    isBSTUtil(node->l, min, node->data) &&
    isBSTUtil(node->r, node->data+1, max)
  );
}


void BalBST::printBST() const {
	vector<Node*> vCurrNodes;
	vector<Node*> vNextNodes;

	if(!_root)
		return;
	
	Node* curr = _root;

	vCurrNodes.push_back(curr);

	do {
		for(Node* &node:vCurrNodes) {
			cout << node->data << " ";
			if(node->l)
				vNextNodes.push_back(node->l);
			if(node->r)
				vNextNodes.push_back(node->r);
		}
		cout << endl;
		vCurrNodes.clear();
		vCurrNodes = vNextNodes;
		vNextNodes.clear();
	}while(!vCurrNodes.empty());
}

void BalBST::makeBalBST(const vector<int>& vSorted, int start, int end,
Node*& node) {
	if(vSorted.empty() || end < start)
		return;

	int mid = (start + end)/2; 
	Node* temp = createNode(vSorted.at(mid));	
	node = temp;

	if(start == end)
		return;

	if(start < mid)
		makeBalBST(vSorted, start, mid-1, node->l);

	makeBalBST(vSorted, mid+1, end, node->r);
}

int main() {
	vector<int> vSorted = {4, 11, 29, 64, 1008, 1100, 1390, 4900, 6100};
	BalBST bbst;
	bbst.makeBalBST(vSorted);
	bbst.printBST();
	cout << bbst.isBST() << endl;
}
