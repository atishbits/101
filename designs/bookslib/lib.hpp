#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct book {
	string _bname;
	string _username;
	unsigned int _count;
};
typedef struct book Book;

struct node {
	vector<string> _chars;
	book _isLeaf;
	vector<struct node> _children;
	Book* _book;
};
typedef struct node Node;

class User {
public:
	string _name;
	map<Book, > _mUserBooks;
	unsigned int _fine;

private:
	User(string name):_name(name);
	void addBook(Book book) {
		_mUserBooks[book] = true;	
	}
	void removeBook(Book book) { 
		_mUserBooks[book] = false;
	}

};

class Library {
private:
	Node* _trie;

public:
	
	
};
