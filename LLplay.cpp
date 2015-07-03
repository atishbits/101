#include "doubleLL.hpp"

class DllSorted: public DLL {
public:
	void insertNode(const int data, const int delta);
	//insert sorted node
	void addNode(const int data);
};


void DllSorted::addNode(const int data) {
	//if list is empty simply add node
	if(!_head) {
		DLL::addNode(data);
		return;
	}

	Node* curr = _head;
	while(curr->next && data > curr->data) {
		curr = curr->next;
	}

	if(data < curr->data) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = curr;
		temp->prev = curr->prev;

		if(curr->prev)
			curr->prev->next = temp;
		else
			_head = temp;
		curr->prev = temp;
		return;
	}	

	//node needs to be inserted at tail
	DLL::addNode(data);
	
}

void DllSorted::insertNode(const int data, const int delta) {
	Node* node = searchNode(data);
	if(!node) {
		cout << "No such node" << endl;
		return;
	}				

	deleteNode(node);
	addNode(data-delta);
}

int main() {
	DllSorted list;
	list.addNode(5);
	list.addNode(35);
	list.addNode(25);

	list.printList();
	list.printRev();

	list.insertNode(25, 23);
	list.printList();
	list.printRev();
}
