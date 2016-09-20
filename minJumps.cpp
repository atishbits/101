#include <iostream>
#include <vector>
using namespace std;

/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9.
*/

void getMinJumps(vector<int>& arr) {
    vector<int> steps;
    vector<int> route;
    steps.push_back(0);
    route.push_back(0);
    int tmp_steps = 0;
    for (int i=1; i<arr.size(); i++) {
        steps.push_back(INT_MAX);
        route.push_back(-1);
        for(int j=0; j<i; j++) {
            if(arr[j]+j >= i) 
                tmp_steps = steps[j] + 1;
            else //unreachable
                continue;
            if (tmp_steps < steps[i]) {
                steps[i] = tmp_steps;
                route[i] = j;
            }
        }
    }
    cout << "Min number of jumps to reach end are:" << steps[arr.size()-1] << endl;
    int length = arr.size();
    cout << "Route:" << arr[length-1] << "->";
    int curr = length - 1;
    while(true) {
        cout << arr[route[curr]];
        curr = route[curr];
        if (curr == 0)
            break;
        cout << "<-";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, 6, 1, 0, 9};
    getMinJumps(arr);
}
