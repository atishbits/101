#include <iostream>
using namespace std;
int main() {
    int count=1, rem=1; 
    int n = 3333336573;
    while(rem)
    {
     rem= (rem*10+1)%n; count++;
    } 
    while(count--){ cout<<"1";}
}
