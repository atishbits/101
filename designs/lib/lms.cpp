#include <lms.hpp>

unsigned int LibraryImpl::add(const string bookname, const string author) {
	string bookid = bookname+author;
	if(_mBooks.count(bookid)) {
		_mBooks[bookid].incrementCount();
		return;
	}	

	//need to insert book in the trie 
	//and update the map

	Book book;
	book._bookName = bookname;
	book._author = author;
	book._count = 1;
	book._numIssued = 0;

	_mBooks[bookid] = _bookT.insertBook(book);
}

bool LibraryImpl::issue(const string bookname, 
	const string author, const string username) {
	if(_mUsers.count(username)) {
		User tmpUser = _mUsers[username];
		if(tmpUser)
	}		
	else
		return false;
}
