#include <iostream>
#include <vector>
using namespace std;
void patternStartEnd(const vector<string>& input, int i=3) {
  bool done = false;
  bool anymatch = false;
  int pos = 0;
  string curr;
  int start;
  while (!done) {
      if(i%3 == 0 && i%5 == 0) {
          curr = "fizzbuzz";
          //TODO: the if/else block below should be bundled into a single bool
          //needrecurr(..) function
          if(anymatch) {//we expect it to match
                       //else we need to recurr
              if(curr.compare(input[pos]) != 0) {
                  patternStartEnd(input, i+1);
                  done = true;
              }
              else { //check end condition 
                  if(pos == input.size() - 1) {
                      done = true;
                      cout << "[" << start << "," << i << "]" << endl;
                  }
                  pos++;
              }
           }
           else {
               if(curr.compare(input[pos]) == 0) {
                   start = i;
                   pos++;
                   anymatch = true;
               }
           }
                   
      }
      else if(i%3 == 0) {
          curr = "fizz";
          if(anymatch) {//we expect it to match
                       //else we need to recurr
              if(curr.compare(input[pos]) != 0) {
                  patternStartEnd(input, i+1);
                  done = true;   
              }
              else { //check end condition 
                  if(pos == input.size() - 1) {
                      done = true;
                      cout << "[" << start << "," << i << "]" << endl;
                  }
                  pos++;
              }
           }
           else {
               if(curr.compare(input[pos]) == 0) {
                   start = i;
                   pos++;
                   anymatch = true;
               }
           }
      }
      else if(i%5 == 0) {
          curr = "buzz";
          if(anymatch) {//we expect it to match
                       //else we need to recurr
              if(curr.compare(input[pos]) != 0) {
                  patternStartEnd(input, i+1);
                  done = true;
              }
              else { //check end condition 
                  if(pos == input.size() - 1) {
                      done = true;
                      cout << "[" << start << "," << i << "]" << endl;
                  }
                  pos++;
              }
           }
           else {
               if(curr.compare(input[pos]) == 0) {
                   start = i;
                   pos++;
                   anymatch = true;
               }
           }
      }
      i = i+1;
  }  
}
int main() {
    const vector<string> input = {"buzz", "fizz", "fizzbuzz"};
    //const vector<string> input = {"fizz", "buzz", "fizz", "fizzbuzz"};
    patternStartEnd(input);
}
