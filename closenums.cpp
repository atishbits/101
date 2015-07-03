/*
Challenge 
Given a list of unsorted integers, A={a1,a2,…,aN}, can you find the pair of
elements that have the smallest absolute difference between them? If there are
multiple pairs, find them all.

https://www.hackerrank.com/challenges/closest-numbers
*/

#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//1 1 3
int main() {
    vector<int> invec;
    int nums;
    cin >> nums;
    while(nums--) {
        int n;
        cin >> n;
        invec.push_back(n);
    }
    sort(invec.begin(), invec.end());
    int min = INT_MAX;
    int prev, curr;
    prev = invec[0];
    vector<int> minpairs;
    
    for (int i=1; i<invec.size(); i++) {
       curr = invec[i];
       if(curr-prev < min) {
			min = curr-prev;
			minpairs.clear();
           minpairs.push_back(prev);
           minpairs.push_back(curr);
       }
       else if(curr-prev == min) {
           minpairs.push_back(prev);
           minpairs.push_back(curr);
       }
        prev = curr;
    }
    for(int& elem:minpairs)
        cout << elem << " ";
	cout << endl;
    return 0;
}
