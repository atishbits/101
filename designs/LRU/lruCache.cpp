#include "lruCache.hpp"

void LruCache::printCache() {
	Node* curr = _head;
	while(curr) {
		cout << "key:" << curr->key 
			<< "value:" << curr->_val->_value << endl;
		curr = curr->_next;
	}
}

void LruCache::insertInHash(string key, Node* val) {
	//TODO what if there are duplicate keys?
	_hashMap[key] = val;
}

void LruCache::evictFromHead() {
	Node* temp = _head;
	_head = _head->_next;
	_head->_prev = nullptr;
	_hashMap.erase(temp->key);
	delete temp;
}

void LruCache::insertAtTail(Node* newnode) {
	_tail->_next = newnode;
	newnode->_prev = _tail;
	newnode->_next = nullptr;
	_tail = newnode;
}

void LruCache::put(const string key, const Object* value) {
	lock_guard<mutex> guard(_cacheLock);
	Node* newnode = new Node;
	newnode->_val = value;
	newnode->key = key;
	if(!_numElems) { //empty cache
		_head = newnode;
		_tail = newnode;
		newnode->_next = newnode->_prev = nullptr;
		insertInHash(key, newnode);
		_numElems++;
	}		
	else if(_numElems == _cacheSize) { //cache FULL
		//evict from head
		evictFromHead();
		insertAtTail(newnode);
		insertInHash(key, newnode);
	}
	else {
		//insert at tail
		insertAtTail(newnode);
		insertInHash(key, newnode);
		_numElems++;
	}
}

bool LruCache::exists(const string key) {
	lock_guard<mutex> guard(_cacheLock);
	return _hashMap.count(key);
}

void LruCache::moveToTail(Node* temp) {
	if(temp->_next == nullptr)
		return; //already at tail
	
	if(temp->_prev == nullptr) {
		//update head
		_head = temp->_next;
		temp->_next->_prev = temp->_prev;
		insertAtTail(temp);
		return;
	}	

	temp->_prev->_next = temp->_next;
	temp->_next->_prev = temp->_prev;
	insertAtTail(temp);
}

const Object* LruCache::get(const string key) {
	lock_guard<mutex> guard(_cacheLock);

	if(!_hashMap.count(key))
		return nullptr;	

	//move node to tail
	Node* temp = _hashMap[key];
	moveToTail(temp);


	return temp->_val;
}

bool LruCache::remove(const string key) {
	lock_guard<mutex> guard(_cacheLock);
	if(!_hashMap.count(key))
		return false;	
	
	Node* temp = _hashMap[key];
	_numElems--;
	
	_hashMap.erase(key);

	if(temp->_next == nullptr && temp->_prev==nullptr) {
		delete temp;
		_head = _tail = nullptr;
		return true;
	}

	if(temp->_next == nullptr) {
		//update tail
		temp->_prev->_next = nullptr;
		_tail = temp->_prev;
		delete temp;
		return true;
	}
	
	if(temp->_prev == nullptr) {
		//update head
		_head = temp->_next;
		temp->_next->_prev = nullptr;
		delete temp;
		return true;
	}	

	temp->_prev->_next = temp->_next;
	temp->_next->_prev = temp->_prev;
	delete temp;
	return true;
}

int main() {
	LruCache* cache = new LruCache(5);

	//test1: inserting 5 elements
	cout << "test1: inserting 5 elements" << endl;
	for(int i=0; i<5; i++) {
		string key = to_string(i);
		string str = "hello"+to_string(i); 
		Object* value = new Object;
		value->_value = str;
		cache->put(key, value);
	}
	cache->printCache();

	
	//test2: get key "0" and check if LRU order is updated
	string key = "0";
	cout << endl << "test2: get key 0 and check if LRU order is updated" << endl;
	cache->get(key);
	cache->printCache();

	
	//test3: insert another element to cause eviction
	key = "5";
	string str = "hello5";
	Object* value = new Object;
	value->_value = str;
	cache->put(key, value);
	cout << endl << "test3: insert another element to cause eviction" << endl;
	cache->printCache();

	//test4: remove an element 
	key = "5";
	cache->remove(key);
	cout << endl << "test4: remove an element" << endl;
	cache->printCache();
}


