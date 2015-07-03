/*
You are given a tree (a simple connected graph with no cycles). You have to
remove as many edges from the tree as possible to obtain a forest with the
condition that : Each connected component of the forest should contain an even
number of vertices.

To accomplish this, you will remove some edges from the tree. Find out the
number of removed edges.

https://www.hackerrank.com/challenges/even-tree
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

/*
	for(int i=0; i<v; i++) {
		cout << i << ":";
		for(int& ver:adjlist.at(i))
			cout << ver << ",";
		cout << endl; 
	}
*/
int countChild(int maxv, vector<vector<int>>& adjlist, std::vector<int>&
childnodes, int v) { 
	int totalChild = 0;

	if(adjlist.at(v).size() == 0) {
		childnodes[v] = 1;
	}
	else {
		for(int& ver:adjlist.at(v)) {
			totalChild += countChild(maxv, adjlist, childnodes, ver);
		}
		childnodes[v] = totalChild+1;
	}
	return childnodes[v];	
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int vertices, edges;
    vector<vector<int>> adjlist;
	std::vector<int> childnodes;

    cin >> vertices >> edges;

    for(int i =0; i<vertices; i++) {
		adjlist.push_back(vector<int>());
		childnodes.push_back(0);
	}

    for(int it=0; it < edges; it++) {
        int v1, v2;
        cin >> v1 >> v2;
		v1--; v2--;
		if(v1<v2)
			adjlist[v1].push_back(v2);
		else
			adjlist[v2].push_back(v1);
    }
    countChild(vertices, adjlist, childnodes, 0);
	int count = 0;
	for(int i=1; i<vertices; i++)
	{
		if(childnodes[i]%2 ==0)
			count++;
	}
	cout << count;
    return true;
}
