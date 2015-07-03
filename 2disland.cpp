#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSafe(int r, int c, vector<vector<bool>>& grid, vector<vector<bool>>& vvisited) {
	return (r>=0 && r<grid.size() &&
			c>=0 && c<grid.at(r).size() &&
			grid.at(r).at(c) && !vvisited.at(r).at(c));
}

int DFS(int r, int c, vector<vector<bool>>& grid, vector<vector<bool>>&
	vvisited, int count) {
	
	static int rowNbr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
	static int colNbr[] = {0, 0, -1, 1, -1, 1, -1, 1};
	
	vvisited.at(r).at(c) =  true;

	if(grid.at(r).at(c) == false)
		return 0;

	for(int k=0; k<8; k++) {
		if(isSafe(r+rowNbr[k], c+colNbr[k], grid, vvisited)) {
			count = DFS(r+rowNbr[k], c+colNbr[k], grid, vvisited, count);
		}		
	}
	return ++count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int rows, cols;
	int maxnodes = 0;
	cin >> rows;
	cin >> cols;
	vector<vector<bool>> grid;
	vector<vector<bool>> vvisited;
	for(int i=0; i<rows; i++) {
		grid.push_back(vector<bool>());
		vvisited.push_back(vector<bool>());
		for(int j=0; j<cols; j++) {
			bool input;
			cin >> input;
			grid.at(i).push_back(input);
			vvisited.at(i).push_back(false);
		}
	}
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(!vvisited.at(i).at(j)) {
				int count = DFS(i, j, grid, vvisited, 0);
				if(count > maxnodes)
					maxnodes = count;
			}
		}
	}
	cout << maxnodes;
	
    return 0;
}


