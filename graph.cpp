#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

class Graph {
private:
	int numV;
	vector<vector<int>> adjvec;
	void dfsUtil(int v, vector<bool>& vvisited);
	void bfsUtil(int v, vector<bool>& vvisited);
    bool isCyclicUtil(int v, vector<bool>& visited, int parent);
public:
	Graph(int V);
	void addEdge(int v1, int v2);
	void dfs(int startv);
    bool isTree();
	void dfs();
	void bfs();
};

Graph::Graph(int v) {
	numV = v;
	while(v--)
		adjvec.push_back(vector<int>());
}

void Graph::addEdge(int v1, int v2) {
	adjvec.at(v1).push_back(v2);
}

void Graph::dfsUtil(int v, vector<bool>& vvisited) {
	vvisited.at(v) = true;
	cout << v << " ";

	for(int& ver:adjvec.at(v)) {
		if(!vvisited.at(ver))
			dfsUtil(ver, vvisited);
	}
}

void Graph::dfs(int startv) {
	int v = numV;
	vector<bool> vvisited;

	while(v--)
		vvisited.push_back(false);

	assert(vvisited.size() == numV);

	dfsUtil(startv, vvisited);
}

//the cycle detection does not work for parallel edges (two edges connecting the same two nodes) XXX
bool Graph::isCyclicUtil(int v, vector<bool>& vvisited, int parent) {
	vvisited.at(v) = true;
    //cout << __func__ << "() Visited node:" << v << endl;

	for(int& ver:adjvec.at(v)) {
		if(!vvisited.at(ver)) {
			if(isCyclicUtil(ver, vvisited, v))
                return true;
        }
        else if (ver != v) {
            cout << "Detected cycle at node:" << ver << " parent:" << v << endl;
            return true;
        }
	}
    return false;
}

bool Graph::isTree() {
	int v = numV;
	vector<bool> vvisited;

	while(v--)
		vvisited.push_back(false);

	assert(vvisited.size() == numV);
	if(isCyclicUtil(0, vvisited, -1)) {
        cout << "Detected a cycle in the graph." << endl;
        return false;
    }

	for(int ver=0; ver<numV; ver++) {
		if(!vvisited.at(ver)) {
            cout << "The graph is not connected at node "<< ver << endl;
            return false;
        }
	}
    return true;
}

void Graph::dfs() {
	int v = numV;
	vector<bool> vvisited;

	while(v--)
		vvisited.push_back(false);

	for(int ver=0; ver<numV; ver++) {
		if(!vvisited.at(ver))
			dfsUtil(ver, vvisited);
	}
}

void Graph::bfsUtil(int startv, vector<bool>& vvisited) {
	vvisited.at(startv) = true;

	queue<int> q;	
	q.push(startv);
	
	//push and print all children
	//deque and push, print subsequent children

	while(!q.empty()) {
		int pv = q.front();
		cout << pv << " ";
		q.pop();
		for(int& ver:adjvec.at(pv)) {
			if(vvisited.at(ver))
				continue;
			vvisited.at(ver) = true;
			q.push(ver);
		}
	}
}

void Graph::bfs() {
	vector<bool> vvisited;
	int V = numV;
	while(V--) 
		vvisited.push_back(false);

	for(int ver=0; ver<numV; ver++) {
		if(!vvisited.at(ver))
			bfsUtil(ver, vvisited);
	}
	

}

int main() {
	// Create a graph
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(0, 6);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    //g.addEdge(7, 8);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs(2);
	cout << endl;
    g.dfs();
	cout << endl << "BFS " << endl;
	g.bfs();
	cout << endl;
    if (g.isTree())
        cout << "This graph can be converted to a tree" << endl;
    else
        cout << "This graph can not be converted to a tree" << endl;
 
    return 0;
}
