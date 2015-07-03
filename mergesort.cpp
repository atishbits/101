#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& vnum, int l, int m, int h) {
	vector<int> tmp;	//hold sorted values between l and h
	int low = l;
	int mid = m;
	bool who = false;

	while(1) {
		if(vnum[low] > vnum[mid+1]) {
			tmp.push_back(vnum[mid+1]);
			mid++;
		}
		else {
			tmp.push_back(vnum[low]);
			low++;
		}
		if(mid==h) {
			who  = true;
			break;
		}
		else if(low == m+1) {
			who = false;
			break;
		}
	}
	if(who)	{	//copy elems from 1st half to array
		while(low!=m+1) {
			tmp.push_back(vnum[low++]);
		}	
	}
	else {
		while(mid!=h) {
			tmp.push_back(vnum[mid++]);
		}
	}

	//copy tmp between l and h to vnum
	for(int i = 0; i 
}

void mergesort(vector<int>& vnum, int l, int h) {
	if(l >= h)
		return;
	int mid = (l+h)/2;
	mergesort(vnum, l, mid);
	mergesort(vnum, mid+1, h);
	merge(vnum, l, mid, h);
}

int main() {
	int T;
	vector<int> vnum;
	cin >> T;
	while(T--) {
		int num;
		cin >> num;
		vnum.push_back(num);
	}
	mergesort(vnum, 0, (vnum.size()-1));

	for(int& elem:vnum)
		cout << elem << " ";
	cout << endl;
}
