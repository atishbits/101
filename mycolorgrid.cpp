#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool leftOK(int r, int c, vector<vector<int>>& grid, int color) {
	if(c == 0) return true;
	if(grid.at(r).at(c-1) != color) return true;
	return false;
}

bool rightOK(int r, int c, vector<vector<int>>& grid, int color) {
	//cout << r << "," << c << endl;
	if(c == grid.at(0).size()-1) return true;
	if(grid.at(r).at(c+1) != color) return true;
	return false;
}

bool upOK(int r, int c, vector<vector<int>>& grid, int color) {
	if(r == 0) return true;
	if(grid.at(r-1).at(c) != color) return true;
	return false;
}

bool downOK(int r, int c, vector<vector<int>>& grid, int color) {
	if(r == grid.size()-1) return true;
	if(grid.at(r+1).at(c) != color) return true;
	return false;
}

bool isSafeColor(int r, int c, vector<vector<int>>& grid, int color) {
	if(c<0 || r<0 || r > (grid.size()-1))
		return false;
	return (leftOK(r, c, grid, color) && rightOK(r, c, grid, color) 
			&& upOK(r, c, grid, color) && downOK(r, c, grid, color));
}

void ways2color(int r, int c, vector<vector<int>>& grid, vector<int>&
	colors, int64_t& ways) 
{
	//found one coloring scheme
	if(r == (grid.size()-1) && c == (grid.at(r).size()-1)) {
		++ways;
		return;
	}

	for(int k=0; k<colors.size(); k++) {
		if(isSafeColor(r, c, grid, colors[k])) {
			grid.at(r).at(c) = colors[k];
			if((r+1) > 0 && (r+1) < (grid.size()))
				ways2color(++r, c, grid, colors, ways);
			if((c+1) > 0 && (c+1) < (grid.at(r).size()))
				ways2color(r, ++c, grid, colors, ways);
		}
	}
	grid.at(r).at(c) = -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int T, N, M, K;
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		vector<vector<int>> grid;
		for(int r=0;r<N; r++) {
			grid.push_back(vector<int>());
			for(int c=0; c<M; c++) {
				grid.at(r).push_back(-1);	//initialize grid with no colors
			}
		}
		vector<int> colors;
		for(int k=0; k<K; k++)
			colors.push_back(k);

		int64_t ways = 0;
		ways2color(0, 0, grid, colors, ways);
		cout << ways << endl;
	}
    return 0;
}
