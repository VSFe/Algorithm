/*
Problem: 시계 사진들
Tier: Gold 1
Detail: 상근이는 보통의 시계와는 다른 독특한 시계 사진 두장이 있습니다. 시계는 n개의 동일한 길이와 목적을 가진 시계 바늘들을 가지고 있습니다.
애석하게도 시계의 숫자들은 희미해져 각 시계 바늘들의 위치만 구분 할 수 있습니다.
우리의 상근이는 두 사진의 시계가 같은 시각을 나타낼 수 있는지 궁금해져 각 사진을 서로 다른 각도로 돌려보려고 합니다.
두 사진에 대한 묘사가 주어질 때, 두 사진의 시계가 같은 시각을 나타내는지 결정하세요.
Comment: 뭐가 나올지 모름... -> 360000 가지고 해싱 때려버리기?
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string T, P;
int b[360001], n, m, N;
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
    int tmp;
    cin >> N;
    for(int i = 0; i < 360000; i++) { T += '0'; P += '0'; }
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        T[tmp] = 1;
    }
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        P[tmp] = 1;
    } T += T;
    n = T.size(), m = P.size();
    KMPPreprocess();
    KMPSearch();
    if(KMPIndex.size()) cout << "possible";
    else cout << "impossible";
    return 0;
}