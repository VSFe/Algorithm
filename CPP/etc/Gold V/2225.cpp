/*
Problem: 합분해 (2225)
Tier: Gold 5
Detail: 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.
Comment: 정수 K개 - 정수 K개 이하라는거 (0이 포함되어 있으니까.)
일단 DP 연습이니 DP로 해보자.
결론: 끝에 붙이던 하자... 괜히 전체 경우를 고려하는 경우는 문제를 더 어렵게 만드는 것.
*/

#include <stdio.h>
using namespace std;

int dp[201][201];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= K; i++) {
        for(int j = 0; j <= N; j++) {
            long long int sum = 0;
            for(int k = 0; k <= j; k++) {
                sum += dp[i-1][k] % 1000000000;
            }
            dp[i][j] = sum % 1000000000;
        }
    }
    printf("%d", dp[K][N]);
    return 0;
}