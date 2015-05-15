#include <iostream>
using namespace std;

struct myNode {
	int data;
	struct myNode* next;	
};

typedef struct myNode Node;

class Queue {
private:
	Node* m_front;
	Node* m_rear;
	
public:
	Queue();
	void enqueue(int data);
	int dequeue();
	bool isEmpty();
};

Queue::Queue() {
	m_front = NULL;
	m_rear = NULL;
}

void Queue::enqueue(int data) {

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	//queue is empty
	if(m_front == NULL && m_rear == NULL) {
		m_front = m_rear = newNode;
	}	
	else {
		m_rear->next = newNode;
		m_rear = newNode;
	}
	return;
}

int Queue::dequeue() {
	if(m_front == NULL && m_rear == NULL) {
		return -1;
	}
	
	int ret = m_front->data;

	//single element in queue
	if(m_front == m_rear) {
		delete m_front;
		m_front = m_rear = NULL;
		return ret;
	}

	Node* temp = m_front;
	m_front = m_front->next;
	delete temp;
	return ret;
}

bool Queue::isEmpty() {
	if(m_rear == NULL && m_front == NULL)
		return true;
	return false;
}

int main() {
	Queue Q;
	int numIns;
	cin >> numIns;
	while(numIns--) {
		int elem;
		cin >> elem;
		Q.enqueue(elem);
	}
	while(!Q.isEmpty()) {
		cout << Q.dequeue() << endl;
	}

	cout << Q.dequeue() << endl;
	Q.enqueue(3);
	cout << Q.dequeue() << endl;
	cout << Q.dequeue() << endl;
}
