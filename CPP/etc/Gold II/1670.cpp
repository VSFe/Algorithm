/*
Problem: 정상 회담 2
Tier: Gold 2
Detail: 여러 개의 소국가로 나뉘어져 있었던 A국을 다시 하나의 국가로 합치기 위해 각 소국가의 대표 N명이 원탁에 모였다.
각 대표는 미리 원탁의 자리를 배정받았다. 회의를 시작하기 전에 일단 서로 악수를 하려고 한다. 각 대표는 한 사람과만 악수할수 있고, 모든 악수는 동시에 일어난다. 이때, 어떤 사람의 팔도 교차하지 않았을 때 완벽하게 악수했다고 한다.
N이 주어지면 완벽하게 악수하는 경우의 수를 구하는 프로그램을 작성하시오.
Comment: 카탈란 수
수가 작아서 그냥 곱셈으로 풀어버리면 된다.
*/

#include <stdio.h>
typedef long long ll;
ll dp[10002];
const ll divide = 987654321;
int main() {
    int n;
    scanf("%d", &n);
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= n; i+=2) {
        for (int j = 0; j <= i-2; j += 2) {
            dp[i] += dp[j] * dp[i - j - 2];
            dp[i] %= divide;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}