#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void locateM(vector<string>& grid, int& row, int& col) {
    for(int r=0; r<grid.size(); r++) {
        for(int c=0; c<grid.at(r).size(); c++) {
            if(grid.at(r).at(c) == 'M') {
                row = r; col = c; break;
            }
        }
    }
}

int countSafeDir(int r, int c, vector<string>& grid, vector<vector<bool>>&
vvisit) 
{
	//cout << __func__ << " called for " << r << "," << c << endl;
	int dir = 0;
	int rowNbr[] = {-1, 1, 0, 0};
	int colNbr[] = {0,  0, 1, -1};
	for(int k=0; k<4; k++) {
		int R = r + rowNbr[k];
		int C = c + colNbr[k];
		if((R>=0) && (R<grid.size()) && 
			(C>=0) && (C<grid.at(R).size()) && 
			(grid.at(R).at(C)!='X') && !vvisit.at(R).at(C))
		{
			dir++;
			//cout << "dir " << R << "," << C << " possible "
			//	<< " dirs count = " << dir << endl;
		}
	}
	return dir;
}

bool isSafe(int r, int c, vector<string>& grid, vector<vector<bool>>& vvisit) 
{
	//cout << "isSafe " << r << "," << c << endl;
	return((r>=0) && (r<grid.size()) && 
			(c>=0) && (c<grid.at(r).size()) && 
			(grid.at(r).at(c)!='X') && !vvisit.at(r).at(c));
}
int DFS(int r, int c, vector<string>& grid, vector<vector<bool>>& vvisit, int
count, bool done) 
{
	//static int count = 0;
	//static bool done = false;
	static int rowNbr[] = {-1, 1, 0, 0};
	static int colNbr[] = {0,  0, 1, -1};

	vvisit.at(r).at(c) = true;

	if(grid.at(r).at(c) == '*')
	{
		//cout << "done " << r << "," << c << endl;
		//cout << "count = " << count << endl;
		done = true;
		return count;
	}
	int ret = countSafeDir(r, c, grid, vvisit);
	if(ret >=2) {
		count++;
		//cout << count << " dirs " << ret << endl;
	}
	//recur for all neighbours
	for(int k=0; k<4; k++) {
		if(done)
			break;
		if(isSafe(r + rowNbr[k], c + colNbr[k], grid, vvisit))
		{
			count = DFS(r + rowNbr[k], c + colNbr[k], grid, vvisit, count,
done);
		}
	}
	return count;
}

int main() 
{
    int T, N, M, K;
    cin >> T;
    vector<string> grid;
	vector<vector<bool>> vvisit;
	for(int tests=0; tests<T; tests++) {
		cin >> N >> M;
		for (int it=0; it<N; it++) {
			string input;
			cin >> input;
			grid.push_back(input);
			vvisit.push_back(vector<bool>());
			for(int col=0; col<M; col++)
				vvisit.at(it).push_back(false);
		}
		cin >> K;
		int i, j;
		locateM(grid, i, j);
		//cout << "located M at " << i << "," << j << endl;

		int count = DFS(i, j, grid, vvisit, 0, false);
		//cout << count << endl;
		if(count == K)
			cout << "Impressed" << endl;
		else
			cout << "Oops!" << endl;
		//re-initialize for next test case
		grid.clear();
		for(int it=0; it<N; it++)
			vvisit.at(it).clear();
		vvisit.clear();
	}
    return 0;
}
