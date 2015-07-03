#include <iostream>
#include <string>
#include <algorithm>

static bool comparator(const char& lhs, const char& rhs) {
	return lhs>rhs;
}

using namespace std;
int main() {
	string unsorted = "bhggjkifelmnz";
	cout << unsorted << endl;
	string sorted = unsorted;
	sort(sorted.begin(), sorted.end(), comparator);
	cout << sorted << endl;
	return 0;
}
