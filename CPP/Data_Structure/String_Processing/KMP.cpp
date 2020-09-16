#define MAX_N 1000001
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

char T[MAX_N], P[MAX_N];
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
    scanf("%[^\n]s", T); getchar();
    scanf("%[^\n]s", P);
    n = strlen(T), m = strlen(P);
    KMPPreprocess();
    KMPSearch();
    printf("%d\n", KMPIndex.size());
    for(int i = 0; i < KMPIndex.size(); i++) printf("%d ", KMPIndex[i] + 1);
    return 0;
}