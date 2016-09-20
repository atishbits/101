#include <iostream>
#include <map>
using namespace std;

//DP
int main() {
    int N;
    cin >> N;
    int fibpp = 0;
    int fibp = 1;
    int result;
    for (int i = 2; i<=N; i++) {
        result = fibpp + fibp;
        fibpp = fibp;
        fibp = result;
    }
    if (N == 0 || N == 1)
        cout << N << endl;
    else
        cout << result << endl;
}
