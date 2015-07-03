#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int64_t r, c, valr, valc;
    cin >> r >> c;
    if(r%2 !=0) {
        valr = (r/2)*10;
    }
    else
        valr = (r/2)*10 - 9;
    valc = (c-1)*2;
    cout << valr+valc << endl;
    return 0;
}
