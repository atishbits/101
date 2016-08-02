#include<iostream>
#include<map>
using namespace std;

static const string src = "rod-src";
static const string dest = "rod-dest";
static const string aux = "rod-aux";
static const int disks = 2;

void toh(int dId, string s, string d, std::map<string, int>& rodMap) {
	if(dId && rodMap[s] && rodMap[d] < disks) {
		cout << "Moved " << dId << " from " << s << " to " 
			<< d << endl;
		rodMap[s] = rodMap[s] - 1;
		rodMap[d] = rodMap[d] + 1;
	}
	else 
		return;

	toh(dId-1, s, dest, rodMap);
	toh(dId-1, aux, dest, rodMap);
}

int main() {
	std::map<string, int> rodMap;
	rodMap[src] = disks;
	rodMap[dest] = 0;
	rodMap[aux] = 0;
	toh(disks, src, aux, rodMap);
}
