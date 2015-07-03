#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cassert>
using namespace std;
static const int notvisited = 0;
static const int visiting = 1;
static const int visited = 2;

void populateGraph(const vector<string>& input, 
	map<char, vector<char>>& adjMap) {
	for(int i=0; i<input.size()-1; i++) {
		string s1 = input[i];
		string s2 = input[i+1];
		int j = 0;
		int min = ::min(s1.size(), s2.size());
		while(j<min) {
			if(s1[j]!= s2[j]) {
				adjMap[s1[j]].push_back(s2[j]);
				break;
			}
			j++;
		}
	}
}

void printMap(const map<char, vector<char>>& adjMap) {
	for(auto it = adjMap.begin(); it != adjMap.end(); it++) {
		cout << it->first << ":";
		for(const char& elem:it->second)
			cout << elem << ",";
		cout << endl;
	}
}

void topoSortUtil(const map<char, vector<char>>& adjMap, map<char, int>& visitMap
	, stack<char>& grammar, const char vertex) {
	if(visitMap[vertex] == visiting) {
		cout << "Input is not a DAG! " << endl;
		assert(0);
	}

	visitMap[vertex] = visiting;
	if(adjMap.count(vertex))
		for(int i=0; i < adjMap.at(vertex).size(); i++) {
			char elem = adjMap.at(vertex).at(i);
			if(visitMap[elem] != visited)
				topoSortUtil(adjMap, visitMap, grammar, elem);	
		}	
	visitMap[vertex] = visited;
	grammar.push(vertex);
}

void topologicalSort(const map<char, vector<char>>& adjMap) {
	map<char, int> visitMap;

	for(auto it=adjMap.begin(); it!=adjMap.end(); it++)
		visitMap[it->first] = notvisited;

	stack<char> grammar;
	int vertex = 0;
	for(auto it=adjMap.begin(); it!=adjMap.end(); it++) {
		if(!visitMap[it->first])
			topoSortUtil(adjMap, visitMap, grammar, it->first);
		vertex++;
	}
	while(!grammar.empty()) {
		cout << grammar.top() << " ";
		grammar.pop();
	}
	cout << endl;
}

int main() {
	//vector<string> input = {"abc", "acd", "bcc", "bed", "bdc", "dab"};
	vector<string> input = {"caa", "aaa", "aab"};
	//vector<string> bad_input = {"abc", "acd", "bcc", "bed", "bdc", "dab", "abc"};
	map<char, vector<char>> adjMap;
	populateGraph(input, adjMap);
	printMap(adjMap);
	topologicalSort(adjMap);
}
