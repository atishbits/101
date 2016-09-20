#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LargeNumbers {
    private:
        vector<int> num1;
        vector<int> num2;
        int to_int(vector<int>& num);
    public:
        LargeNumbers(string& n1, string& n2);
        string add();
        int actualSum();
};

int LargeNumbers::to_int(vector<int>& num) {
    int len = num.size();
    int number = 0;
    for (int i=0; i<len; i++) {
        number = number*10 + num[i]; 
    }
    cout << "Number is" << number << endl;
    return number;
}

int LargeNumbers::actualSum() {
    return to_int(num1) + to_int(num2);
}

LargeNumbers::LargeNumbers(string& n1, string& n2) {
    int length = n1.size();
    int digit;
    cout << "Num1:" << endl;
    for(int i=0; i<length; i++) {
        digit = char(n1[i]) - char('0');
        num1.push_back(digit);
        cout << digit;
    }
    cout << endl << "Num2:" << endl;
    length = n2.size();
    for(int i=0; i<length; i++) {
        digit = char(n2[i]) - char('0');
        num2.push_back(digit);
        cout << digit;
    }
    cout << endl;
}

string LargeNumbers::add() {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result;
    int sum = 0;
    int carry = 0;
    while(len1 and len2) {
        sum = num1[len1-1] + num2[len2-1] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        len1--; len2--;
    }
    if(len1) {
        while(len1) {
            sum = carry + num1[len1-1];
            carry = sum/10;
            result.push_back(sum);
            len1--;
        }
    }
    else if(len2) {
        while(len2) {
            sum = carry + num2[len2-1];
            carry = sum/10;
            result.push_back(sum);
            len2--;
        }

    }
    if(carry)
        result.push_back(carry);
    string res = "";
    int length = result.size();
    for (int i=length-1; i>=0; i--) {
        cout << result[i];
        //res += to_string(result[i]);
    }
    return res;
}

int main() {
    string n1 = "8888889";
    string n2 = "111";
    LargeNumbers LN(n1, n2);
    cout << n1 << "+" << n2 << "=" << LN.add() << endl;
    cout << "Actual sum:" << endl;
    cout << LN.actualSum() << endl;
}
