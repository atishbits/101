/*
	Program that given the classic fizzbuzz sequence, prints what range of
	numbers the input sequence belongs to.  
	Below is a brute force implementation using recurrsion. We can optimize
	this since the pattern itself repeats and we need not try to match for every
	number in the sequence. 
*/
#include <iostream>
#include <vector>
using namespace std;
//variable num starts with 3 as default
//TODO: the input array of strings could be invalid!
void printPatternRange(const vector<string>& input, int num=3) {
  bool done = false;
  bool anymatch = false;	//did anything match so far
  int pos = 0;
  string curr;
  int start;
  while (!done) {
      if(num%3 == 0 && num%5 == 0)
          curr = "fizzbuzz";
      else if(num%3 == 0)
          curr = "fizz";
      else if(num%5 == 0)
          curr = "buzz";
	  else {
		num = num+1;
		if(num > 1000) {
			cout << "Invalid input!" << endl;
			break;
		}
		continue;
	  }
	  if(anymatch) {//we expect it to match
				   //else we need to recurr
		  if(curr.compare(input[pos]) != 0) { 
			  printPatternRange(input, num+1);
			  done = true;
		  }
		  else { //check end condition 
			  if(pos == input.size() - 1) {
				  done = true;
				  cout << "[" << start << "," << num << "]" << endl;
			  }
			  pos++;
		  }
	   }
	   else {
		   if(curr.compare(input[pos]) == 0) {
			   start = num;
			   pos++;
			   anymatch = true;
		   }
	   }
	   num = num+1;
	}
}

int main() {
	const vector<string> input = {"buzz", "fizz", "fizzbuzz"};
	printPatternRange(input);
}
