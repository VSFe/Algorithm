/*
Problem: 골롱 수열
Tier: Gold 2
Detail: Golomb 수열이란 모든 k에 대해 k가 수열상에서 f(k)번 등장하는 단조증가 수열이다. 단조증가 수열이란 k값이 증가함에 따라 f(k)값이 감소하지 않는 수열을 말한다. 여기서 k와 f(k)는 모두 자연수이다.
골롱 수열은 유일하게 결정될 수밖에 없다. 잘 생각해 보시길 ..
n이 주어졌을 때 f(n)을 구하는 프로그램을 작성하시오.
Comment:
G(1) = 1
G(n+1) = 1 + G(n + 1 - G(G(n)))
그냥 DP로 풀기엔 범위가 너무 큰데...
*/

#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

map<ll, ll> visited;

int main() {
    int N; cin >> N;
    if(N == 1) {
        cout << 1; return 0;
    }
    ll sum = 0;
    visited[1] = 1;
    sum += visited[1];

    for(ll i = 2; i <= N; i++) {
        visited[i] = 1 + visited[i - visited[visited[i - 1]]];
        sum += visited[i];
        if(sum >= N) {
            cout << i;
            return 0;
        }
    }
}