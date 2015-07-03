#include "doubleLL.hpp"

int main() {
	DLL list;
	list.addNode(6);
	list.addNode(10);
	list.addNode(98);

	//test add elems
	cout << "Num elems " << list.numElems() << endl;
	list.printList();
	list.printRev();

	//test del elem 
	list.delNode(10);
	cout << "Num elems " << list.numElems() << endl;
	list.printList();


	list.delNode(10);
	cout << "Num elems " << list.numElems() << endl;
	list.printList();



	list.delNode(98);
	cout << "Num elems " << list.numElems() << endl;
	list.printList();


	list.delNode(6);
	cout << "Num elems " << list.numElems() << endl;
	list.printList();
}

