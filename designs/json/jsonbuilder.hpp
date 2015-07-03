#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
	bool isleaf;
	map<string, struct node*> mapChild;	
	vector<string> vvals;
};
typedef struct node Node;

class JsonBuilder {
private:
	Node* m_root;
	void printJHelp(Node* node, string tab);

public:
	JsonBuilder();
	void insertExp(const string& exp);
	void printJson();
};
