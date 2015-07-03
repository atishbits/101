#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void countMinDels(string input) {
    char prev = input[0];
    char curr;
    int count = 0;
    for(std::string::size_type i = 1; i < input.size(); ++i) {
        curr = input[i];
        if(curr == prev)
            count++;
    }
    cout << count << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int testnum;
    vector<string> inputs;
    for(int it=0; it<testnum; it++) {
        string in;
        cin >> in;
        inputs.push_back(in);
    }
    for(string& s: inputs)
        countMinDels(s);
    return 0;
}
