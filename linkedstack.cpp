#include <iostream>
using namespace std;

struct mynode {
	int data;
	struct mynode* next;
};
typedef struct mynode Node;

class Stack {
private:
	Node* top;

public:
	Stack();
	void push(int data);
	int pop();
	bool isEmpty();
};

Stack::Stack() {
	top = nullptr;
}

void Stack::push(int data) {
	Node* newnode = new Node;
	newnode->data = data;
	
	if(top == nullptr) {
		top = newnode;
		newnode->next = nullptr;
	}
	else {
		newnode->next = top;
		top = newnode;
	}	
}

int Stack::pop() {
	if(top == nullptr)
		return -1;
	
	int ret = top->data;
	Node* temp = top;
	top = top->next;
	delete temp;
	return ret;
}

bool Stack::isEmpty() {
	return top==nullptr;
}

int main() {
	Stack stack;
	int numelems;

	cin >> numelems;

	while(numelems--) {
		int input;
		cin >> input;
		stack.push(input);
	}
	while(!stack.isEmpty()) {
		cout << stack.pop() << endl;
	}
	cout << stack.pop() << endl;
	stack.push(14);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
}
