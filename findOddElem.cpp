/* Given an array where every element occurs three times, except one element
 * which occurs only once. Find the element that occurs once.
 */

#include <iostream>
using namespace std;

int main() {
	int arr[] = {1, 12, 1, 3, 1, 3, 3};			
	int lenArr = sizeof(arr)/sizeof(int);
	map<int, int> mapBitSum;
	for(int j=0; j<sizeof(int); j++) {
		mapBitSum[j] = 0;
	}
	for (int i=0; i<lenArr; i++) {
		for(int j=0; j<sizeof(int); j++) {
			if(isBitSet(arr[i], j))
				mapBitSum[j] += 1;	
		}
	}
}
