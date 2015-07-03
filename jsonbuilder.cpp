#include "jsonbuilder.hpp"
#include <iterator>
#include <boost/algorithm/string.hpp>

JsonBuilder::JsonBuilder() {
	m_root = new Node;
	m_root->isleaf = false;
}

//a>b=1
void JsonBuilder::insertExp(const string& exp) {
	Node* curr = m_root;

	vector<string> vSplitGreaterThan;
	boost::split(vSplitGreaterThan, exp, boost::is_any_of(">"));

	for(string& elem:vSplitGreaterThan) {
		vector<string> vSplitEquals;
		boost::split(vSplitEquals, elem, boost::is_any_of("="));

		if(vSplitEquals.size() == 1)	//=> no '=' found
		{
			if(curr->mapChild.count(elem)) //entry exists in map
				curr = curr->mapChild[elem];
			else if(!curr->isleaf) {	//create new node with e
				Node* newnode = new Node;
				curr->mapChild[elem] = newnode;
				curr = curr->mapChild[elem];
				curr->isleaf = false;
			}
			else {
				cout << "invalid input " << exp << " when elem " 
					<< elem << endl;
				return;
			}
		}
		else { //we found '=' 
			assert(vSplitEquals.size() == 2);
			string e = vSplitEquals[0];
			string val = vSplitEquals[1];
			if(curr->mapChild.count(e)) {//entry exists in map
				curr = curr->mapChild[e];
				if(!curr->isleaf)
				{
					cout << "invalid input " << exp << endl;
					return;		//curr is not leaf!! => invalid
				}
				curr->vvals.push_back(val);
				//we should be done now so just return!
				return;
			}
			else if(curr->isleaf) {
				cout << "invalid exp " << exp << endl;
				return;
			}
			else {	//create new node with e
				cout << endl << "created new node for " << exp
					<< " where e = " << e << endl;
				Node* newnode = new Node;
				curr->mapChild[e] = newnode;
				curr = curr->mapChild[e];
				curr->isleaf = true;
				curr->vvals.push_back(val);
				//we are done now
				return;
			}
		}
	}
}

void JsonBuilder::printJHelp(Node* node, string tab) {

	if(node->isleaf) {
		cout << '[';
		for(string& val:node->vvals)
			cout << val << ",";
		cout << ']';
		return;
	}

	map<string, Node*>::iterator it;
	for(it=node->mapChild.begin(); it!=node->mapChild.end(); it++) {
		if(it->second->isleaf) {
			cout << tab << "'" <<it->first << "':"; 
			printJHelp(it->second, tab);
			cout << endl;
		}
		else {
			cout << tab << "'" <<it->first << "':{" << endl;
			printJHelp(it->second, tab+"\t");
			cout << tab << "}," << endl;
		}
	}
}

void JsonBuilder::printJson() {
	Node* curr = m_root;
	cout << "{" << endl;
	printJHelp(m_root, "\t");
	cout << "}" << endl;
}

int main() {
	JsonBuilder JB;
	cout << "Input number of strings ";
	int num;
	cin >> num;
	while(num--) {
		string in;
		cin >> in;
		JB.insertExp(in);
	}
	JB.printJson();
}
