#ifndef __DOUBLELL_HPP__
#define __DOUBLELL_HPP__

#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;

class DLL {
protected:
	Node* _head;
	Node* _tail;
	unsigned int _numElems;
	void deleteNode(Node* node);
	Node* searchNode(const int data);

public:
	DLL() {
		_head = nullptr;
		_tail = nullptr;
		_numElems = 0;
	}
	void addNode(const int data);
	void delNode(const int data);	//searches data and deletes the first node
									//containing data
	void printList();
	void printRev();
	unsigned int numElems() {
		return _numElems;
	}
};

void DLL::printList() { 
	Node* curr = _head;
	while(curr) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

void DLL::printRev() { 
	Node* curr = _tail;
	while(curr) {
		cout << curr->data << "<-";
		curr = curr->prev;
	}
	cout << "NULL" << endl;
}

void DLL::delNode(const int data) {
	Node* node = searchNode(data);
	if(node)
		deleteNode(node);
	else
		cout << "Node does not exist" << endl;
}

Node* DLL::searchNode(const int data) {
	Node* curr = _head;
	while(curr) {
		if(curr->data == data)
			return curr;
		curr = curr->next;
	}
	return curr;
}

void DLL::deleteNode(Node* node) {
	if(node->prev)
		node->prev->next = node->next;
	else
		_head = node->next;
	if(node->next)
		node->next->prev = node->prev;
	else
		_tail = node->prev;
	delete node;
	_numElems--;
}

void DLL::addNode(const int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	if(!_head) {
		_head = temp;
		_tail = temp;
		temp->prev = nullptr;
		_numElems++;
		return;
	}
	_tail->next = temp;
	temp->prev = _tail;
	_tail = temp;
	_numElems++;
}

#endif // __DOUBLELL_HPP__
