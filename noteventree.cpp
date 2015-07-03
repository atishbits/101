#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
void findDelEdg(int v, int e, std::map<int, std::vector<int>>& adjmap) {
    bool done = false;
    while(!done) {
        
    }
}
*/
int countAllChild(vector <int> *v , int *childrens , int offset)
{
    int totalSize = 0;
    if(v[offset].size() == 0)
        childrens[offset] = 1;
    else if(0 == childrens[offset])
    {
        for(int i = 0; i < v[offset].size() ; i++)
        {
            totalSize += countAllChild(v,childrens,v[offset][i]);
        }
    }
    childrens[offset] = totalSize + 1;
    return childrens[offset];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int vertices, edges;
    int returnValue = 0;
    cin >> vertices >> edges;
    //std::map<int, std::vector<int>> adjmap;
    vector<int> childVec[vertices];
    int childs[vertices];
    for(int i =0; i<vertices; i++)
        childs[i] = 0;
    for(int it=0; it < vertices; it++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        childVec[v2].push_back(v1);
        /*
        if(adjmap.count(s)==0) {
            adjmap[s] = std::vector<int>({d});
        }
        else
            adjmap[s] = adjmap[s].push_back(d);
        */
    }
    //findDelEdg(vertices, edges, adjmap);
    countAllChild(childVec, childs, 0);
    for(int i = 1; i < vertices; i++)
    {
        if((childs[i])%2 == 0)
        {
            returnValue++;
        }
    }
 
    cout<<returnValue<<endl;
    return true;
}
