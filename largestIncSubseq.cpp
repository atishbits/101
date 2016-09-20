//g++ --std=c++11 largestIncSubseq.cpp

#include <iostream>
#include <vector>
using namespace std;

/*The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

Assumption: only strictly increasing subsequence
*/


int LIS(vector<int>& input) {
    vector<int> counts;
    vector<int> path;
    int length = input.size();
    path.push_back(0);
    //every inividual number forms an increasing sequence of length 1
    counts.push_back(1);
    for(int i=1; i<length; i++) {
        counts.push_back(1);
        path.push_back(0);
        for(int j=0; j<i; j++) {
            if(input[j] < input[i] and (counts[j]+1) > (counts[i])) {
                counts[i] = counts[j] + 1;
                path[i] = j;
            }
            else {
                path[i] = i;
            }
        }
    }
    cout << "Printing elements of counts" << endl;
    for (int i=0; i<length; i++) {
        cout << counts[i] << " ";
    }
    cout << endl;
    cout << "Printing elements of path" << endl;
    for (int i=0; i<length; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    cout << "Printing elements of LIS" << endl;
    int num = length - 1;
    cout << input[num];
    while(true) {
        if(num == path[num])
            break;
        cout << " <- ";    
        num = path[num];
        cout << input[num];
    }
    cout << endl;
    return counts[length - 1];
    
}

int main() {
    vector<int> input{10, 22, -1, 0, 6, 2, 3};
    cout << "Printing elements of input" << endl;
    for (int i=0; i< input.size(); i++) 
        cout << input[i] << " ";
    cout << endl;
    //vector<int> input{ 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    int count = LIS(input);
    cout << count << endl;
}
