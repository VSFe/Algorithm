/*
Problem: Four Squares (17626)
Tier: Silver 5
Detail: 자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램을 작성하시오.
Commant: 흠... 실버 5는 아닌데
브루트포스 + dp
*/

#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[50001];
int N;

int main() {
    scanf("%d", &N);
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= N; i++) {
        int tmp = sqrt(i);
        int MIN = 5;
        for(int j = 1; j <= tmp; j++) {
            MIN = min(MIN, dp[i - j * j]);
        }
        dp[i] = MIN + 1;
    }
    printf("%d", dp[N]);
}