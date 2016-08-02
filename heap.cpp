#include <iostream>
using namespace std;

const int maxElems = 1000;

struct Elem {
	int key;
	string data;
};

class Heap {
private:
	Elem _arr[maxElems];
	int _numElems;

public:
	Heap() {
		_numElems = 0;
	}
	void insert(int key, string data) {};
	int getMinKey() {
		if(_numElems)
			return _arr[0].key;
		else
			return -1;
	}
	string extractMin() {};
};

int main() {
	Heap H1;
	cout << H1.getMinKey() << endl;
}
