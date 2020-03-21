/*
Problem: 2*n 타일링 2
Tier: Silver 3
Detail: 2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
Comment: 너무 쉬운 DP. DP[i] = DP[i-1] + 2 * DP[i-2]
*/

#include <stdio.h>

int dp[1001];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }
    printf("%d", dp[n]);
    return 0;
}