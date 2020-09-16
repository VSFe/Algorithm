/*
Problem: 이항 계수와 쿼리 (13977)
Tier: Gold 1
Detail: M개의 자연수 N과 정수 K가 주어졌을 때 이항 계수 NCK를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.
Comment: 페르마의 소정리 응용문제.
*/


#include <iostream>
using namespace std;

long long fac[4000001];

const int DIV = 1e9+7;

long long solve(int x, int y) {
    if(y == 0) return 1;
    long long half = solve(x, y/2);
    long long tmp = (half * half) % DIV;
    if(y % 2) return (tmp * x) % DIV;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    fac[0] = 1, fac[1] = 1;
    for(int i = 2; i <= 4000000; i++) fac[i] = (fac[i - 1] * i) % DIV;
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        cout << (solve((fac[x - y] * fac[y]) % DIV, DIV - 2) * fac[x]) % DIV << '\n';
    }
}