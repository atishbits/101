#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;

class LL {
private:
	Node* head;
	Node* tail;
	LL() {};

public:
	LL(int data) {
		head = tail = new Node;
		head->data = data;
		head->next = nullptr;
	}

	void insert(int data) {
		tail->next = new Node;
		tail->next->data = data;
		tail->next->next = nullptr;
		tail = tail->next;
	}

	Node* gethead() {return head;};

	void printList() {
		Node* curr = head;
		while(curr) {
			cout << curr->data << "->";
			curr = curr->next;
		}
		cout << "null";
	}
	
	//TODO need a destructor to destroy linkedlist

};

void getNextSum(Node*& tmpA, Node*& tmpB, int& sumA, int& sumB) {
	while(tmpA->data != tmpB->data) {
		if(tmpA->data < tmpB->data) {
			sumA += tmpA->data;
			tmpA = tmpA->next;
		}
		else {
			sumB += tmpB->data;
			tmpB = tmpB->next;
		}
		if(!tmpA) {
			//sum all remaining B items
			while(!tmpB) {
				sumB += tmpB->data;
				tmpB = tmpB->next;
			}
			return;
		}
		if(!tmpB) {
			//sum all remaining B items
			while(!tmpA) {
				sumA += tmpA->data;
				tmpA = tmpA->next;
			}
			return;
		}
	}
	sumA += tmpA->data;
	sumB += tmpB->data;
}

static void printMaxSumList(Node* A, Node* B) {
	Node *result, *tmpA, *tmpB, *prevA, *prevB;
	tmpA = A;
	tmpB = B;
	int sumA = 0;
	int sumB = 0;
	Node *prev;
	getNextSum(tmpA, tmpB, sumA, sumB);
	if(sumA>sumB) {
		result = A;
		prev = tmpA;
	}
	else {
		result = B;
		prev = tmpB;
	}
	while(1) {
		sumA = sumB = 0;
		tmpA = tmpA->next; tmpB = tmpB->next;
		prevA = tmpA; prevB = tmpB;
		getNextSum(tmpA, tmpB, sumA, sumB);
		if(sumA>sumB) { 
			prev->next = prevA;
			prev = tmpA;
		}
		else {
			prev->next = prevB;
			prev = tmpB;
		}
		if(!tmpA && !tmpB)
			break;
	}

	//now print result
	while(result) {
		cout << result->data << "->";
		result = result->next;
	}
}

int main() {
	LL A(1), B(0);
	vector<int> a {3,30,90,120,240,511};
	vector<int> b {3,12,32,90,125,240,249};
	for(auto &elem: a)
		A.insert(elem);
	for(auto &elem: b)
		B.insert(elem);
	
	A.printList();
	cout << endl;
	B.printList();
	cout << endl;

	printMaxSumList(A.gethead(), B.gethead());
}

