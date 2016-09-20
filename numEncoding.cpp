#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.
*/

int countDecoding(string& digits, int n)
{
    vector<int> count;
    count.push_back(1);
    count.push_back(1);
 
    for (int i = 2; i <= n; i++)
    {
        count.push_back(0);
 
        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (digits[i-1] > '0')
            count[i] = count[i-1];
 
        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if (digits[i-2] < '2' || (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}

int countRec(string& input, int length) {
    static int steps = 0;
    steps ++;
    cout << steps << endl;
    int num = 0; 

    if(length == 0 || length == 1)
        return 1;

    if (input[length - 1] > '0') {
        num = countRec(input, length - 1);
    }

    if(input[length - 2] <= '2' || (input[length-2] == '2' && input[length-1] < '7')) {
        num += countRec(input, length-2);
    } 
    return num;
}

int main() {
    string input = "1211132311";
    int num = countDecoding(input, input.size());
    //int num = countRec(input, input.size());
    cout << "Result:"<< num << endl;
}
