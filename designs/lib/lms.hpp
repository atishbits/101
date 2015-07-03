#include <iostream>
#include <vector>
using namespace std;

struct book {
	string _bookName;
	string _author;
	int _count;
	int _numIssued;
	vector<string> _issuedBy;
};
typedef struct book Book;

struct trieNode {
	vector<string> _alphabets;
	bool _isLeaf;
	vector<trieNode> _childNodes;
	Book _book;
};
typedef struct trieNode Node;

class BookTrie {
private:
	Node* _trie;

public: 
	void incrementCount(Book book);
	trieNode insertBook(Book book);
	const Book& searchBook(Book book);

};

class User {
private:
	string _username;
	//user knows only the book name
	map<string, bool> _userBooks;
	unsigned int _fine;

public: 
	User(string user):_username(user) {
		_fine = 0;
	};
	const vector<Book>& getUserBooks() {
		return _userBooks;
	}
	void setFine(unsigned int fine) {
		_fine = fine;
	}
	unsigned int getFine() {
		return _fine;
	}
};

class LibraryImpl {
private:
	map<string, User> _mUsers;
	map<string, trieNode> _mBooks;
	BookTrie _bookT;

public:
	LibraryImpl() {};
	~LibraryImpl() {};

	//returns new number of copies of the book
	unsigned int add(const string bookname, const string author);

	//return false if already issued #count number of books
	bool issue(const string bookname, const string author, 
		const string username);

	//returns the fine amount to be paid
	int returnBook(const string bookname, const string author);

	void addUser(const string username);
};

static LibraryImpl libInstance;
Library& Library::getInstance()
{
	return libInstance;
}
