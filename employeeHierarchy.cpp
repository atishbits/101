/*
Maintain an employee hierarchy with attributes. Print complete hierarchy of given employee.
Find top 10 employees on the basis of salary ,at any instant of time . Perform CRUD operations on the hierarchy.
*/

#include <iostream>
#include <map>
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct employee {
	string _name;
	int _salary;
	employee(string name, int sal):_name(name), _salary(sal) {};
};
typedef struct employee Employee;

struct node {
	int salary;
	struct node* l;
	struct node* r;
};
typedef struct node Node;

class EmpInfo {
private:
	Node* _root;
	std::map<string, Node*> _empMap;
	void insertInBST(Node* node, Node* newnode);

public:
	EmpInfo();
	void insert(const Employee emp);
	const void display(const string& name);
	bool update(const string& name, const Employee newinfo);
	bool del(const string& name);
	const void displayTop10();
};

EmpInfo::EmpInfo() {
	_root = nullptr;
}

void EmpInfo::insertInBST(Node* node, Node* newnode) {
	if(newnode->salary < node->salary)
	{
		if(node->l)
			insertInBST(node->l, newnode);
		else
			node->l = newnode;
	}
	else {
		if(node->r)
			insertInBST(node->r, newnode);
		else
			node->r = newnode;
	}

}

void EmpInfo::insert(const Employee emp) {
	Node* newnode = new Node;
	newnode->salary = emp.salary;
	newnode->l = nullptr;
	newnode->r = nullptr;
	_empMap[emp.name] = newnode;
	if(_root == nullptr) {
		_root = newnode;		
		return;
	}

	insertInBST(_root, newnode);
}

const void EmpInfo::display(const string& name) {
	cout << name << " " << _empMap[name]->salary << endl;
}

bool EmpInfo::update(const string& name, const Employee newinfo) {
	//update involves deletion from BST and then re-insertion with new 
	//value
	del(name);
	insert(newinfo);
}

bool EmpInfo::del(const string& name) {
	//1. delete the node from tree
	//2. remove the name from element as well
	//alternatively, we can simply mark the emp as deleted ;)

}
const void EmpInfo::displayTop10() {

}

int main() {
	string inOpt, empname, newname;
	int sal;

	EmpInfo empI;

	while(1) {
		cout << "Options: i:insert, di:display, u:update,"
			<< " d:del, d10:displayTop10" << endl;
	
		cin >> inOpt;

		if(inOpt.compare("i") == 0) {
			cout << "Enter employee name ";
			cin >> empname;
			cout << "Enter salary";
			cin >> sal;
		
			empI.insert(Employee(empname, sal));
		}
		else if(inOpt.compare("di") == 0) {
			cout << "Enter employee name ";
			cin >> empname;
		
			empI.display(empname);
		}
		else if(inOpt.compare("u") == 0) {
			cout << "Enter employee name ";
			cin >> empname;
			cout << "Enter new name ";
			cin >> newname;
			cout << "Enter salary";
			cin >> sal;
		
			empI.update(empname, Employee(newname, sal));
		}
		else if(inOpt.compare("d") == 0) {
			cout << "Enter employee name ";
			cin >> empname;
		
			empI.del(empname);
		}
		else if(inOpt.compare("d10") == 0) {
			empI.displayTop10();
		}
	}
}
