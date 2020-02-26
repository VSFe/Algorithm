/*
Problem: 팩토리얼 0의 개수 (1676)
Tier: Silver 2
Detail: N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
Comment: 5나 10에서 0 숫자 하나 추가.
*/

#include <stdio.h>

int N;
int dp[501];

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i-1];
        int tmp = i;
        while(tmp % 5 == 0) {
            tmp /= 5;
            dp[i]++;
        }
    }
    printf("%d", dp[N]);
    return 0;
}