#include <iostream>
#include <vector>
using namespace std;

/*
Input: array of integers
return any one element of the array such that the element is equal to or
greater than both it's neighbours
*/

void printPeak(vector<int>& testin, int start, int end) {
	int mid = (start + end)/2;
	//corner element
	if(mid == 0) {
		if(testin[mid] >= testin[mid+1]) {
			cout << "Peak elem:" << testin[mid] << endl;
			return;
		}
	}
	//corner element
	else if(mid == testin.size()-1) {
		if(testin[mid] >= testin[mid-1]) {
			cout << "Peak elem:" << testin[mid] << endl;
			return;
		}
	}
	else {
		if(testin[mid] >= testin[mid-1] && testin[mid] >= testin[mid+1]) {
			cout << "Peak elem:" << testin[mid] << endl;
			return;
		}
	}

	if(mid-1 >= 0 && testin[mid] < testin[mid-1]) {
		//go left
		printPeak(testin, 0, mid-1);
	}
	else if(mid+1 < testin.size())  {
		//go right
		printPeak(testin, mid+1, testin.size() - 1);
	}
	else {
		//this should never happen
		cout << "some issue?" << endl;
	}
}

int main() {
	int myints[] = {2,58, 99, 16};
	std::vector<int> test (myints, myints + sizeof(myints) / sizeof(int) );

	if(test.size() == 1) {
		cout << "Peak elem:" << test[0] << endl;
		return 0;
	}
	printPeak(test, 0, test.size()-1);
	return 0;
}
