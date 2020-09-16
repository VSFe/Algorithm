/*
Problem: 구간 합 구하기 4
Tier: Silver 3
Detail: 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
Comment: 구간 합 1차원 배열을 만들면 너무 쉽게 해결 됨.
*/

#include <iostream>
using namespace std;

int N, M, sum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        sum[i + 1] = sum[i] + tmp;
    }
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        cout << sum[y] - sum[x-1] << '\n';
    }
}
