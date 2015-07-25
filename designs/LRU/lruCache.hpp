#include <iostream>
#include <map>
#include <mutex>
using namespace std;

struct Object {
	string _value;
};

struct Node {
	const Object* _val;
	string key;
	Node* _next;
	Node* _prev;
};

class LruCache {
private:
	unsigned int _cacheSize;
	unsigned int _numElems;
	Node* _head;
	Node* _tail;
	map<string, Node*> 	_hashMap;
	mutex _cacheLock;
	void insertInHash(string key, Node* val);
	void evictFromHead();
	void insertAtTail(Node* newnode);
	void moveToTail(Node* );
		
public:
	LruCache(unsigned int size) {
		_cacheSize = size;
		_numElems = 0;
		_head = nullptr;
		_tail = nullptr;
	}
	void put(const string key, const Object* value);
	const Object* get(const string key);
	bool exists(const string key);
	bool remove(const string key);

	//for testing
	void printCache();
};
