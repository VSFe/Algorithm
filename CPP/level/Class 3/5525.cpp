/*
Problem: IOIOI
Tier: Silver 2
Detail: N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
    P1 IOI
    P2 IOIOI
    P3 IOIOIOI
    PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.
Comment: IOI 찾으라는거 아님? -> 단순한 1차원 DP! 근데 귀찮아서 KMP로 품 ㅋㅋㅋㅋㅋㅋㅋ
*/

#define MAX_N 1000001
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string T, P;
int b[MAX_N], n, m, N, M;
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
    cin >> N >> M >> T;
    P = "IOI";
    for(int i = 2; i <= N; i++) P += "OI";
    n = T.size(), m = P.size();
    KMPPreprocess();
    KMPSearch();
    cout << KMPIndex.size();
    return 0;
}

