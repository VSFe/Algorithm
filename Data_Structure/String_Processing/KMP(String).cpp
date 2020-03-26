#define MAX_N 1000001
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string T, P;
int b[MAX_N], n, m;
vector<int> KMPIndex;

void KMPPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void KMPSearch() {
    int i = 0, j = 0;
    while(i < n) {
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m) {
            KMPIndex.push_back(i - j);
            j = b[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, T, '\n');
    getline(cin, P, '\n');
    n = T.size(), m = P.size();
    KMPPreprocess();
    KMPSearch();
    cout << KMPIndex.size() << '\n';
    for(int i = 0; i < KMPIndex.size(); i++) cout << KMPIndex[i] + 1 << " ";
    return 0;
}

