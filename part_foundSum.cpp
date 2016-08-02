/* Given a character array which each position is filled with either a single
 * digit numbers or a comma,
 * Write a code to reply true if we find a set of three set of numbers separated
 * by a comma such that
 * X , Y, Z and Z = X + Y
 * e.g. array: 7 7 , 2 2 , 9 9 , 1 , 2 , 6 (returns true due to 77+22 = 99)
 */

#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int getNextNum(const vector<char>& vInput, int& pos) {

	vector<int> vNums;

	int num = vInput.at(pos) - int('0');

	vNums.push_back(num);

	if(num > 9 || num < 0)
		throw "Incorrect input";

	while(vInput.at(pos)!=',' || pos < vInput.size() - 1) {
		
	}
		
}

bool foundSum(const vector<char>& vInput) {
	if(!vInput.size())
		return false;

	int n1, n2, n3, pos;
	pos = 0;

	try {
		n1 = getNextNum(vInput, pos);
		n2 = getNextNum(vInput, pos);

		while(pos < vInput.size()-1) {
			n3 = getNextNum(vInput, pos);
			if(n1 + n2 == n3)
				return true;

			n1 = n2;
			n2 = n3;	
		}	
	} catch (const std::string& msg) {
		cout << "Exception throw during processing:" 
			<< msg << endl;
		return false;
	}

}

int main() {
	vector<char> vInput =
		{'7','7','7',',','1','2','3',',','6','6',',','2','2','8','8'};	

	if(foundSum(vInput)) 
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
