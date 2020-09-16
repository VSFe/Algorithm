/*
Problem: 계단 수 (1562)
Tier: Gold 1
Detail: 45656이란 수를 보자. 이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
그럼, 오늘도 역시 세준이는 0부터 9까지 모든 한 자리수가 자리수로 등장하면서, 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N이면서 0에서 9가 모두 등장하는 계단 수가 총 몇 개 있는 지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
Comment: 비트마스크를 잘~~ 활용하는 방법.
쉬운 계단 수 (10844)와 접근 방식은 동일하지만, 비트마스크로 방문 여부까지 판단해야함.
사실 점화식은 만만하다.
*/

#define divisor 1000000000;
#include <stdio.h>

int dp[101][10][1024]; //비트마스크 순회를 위함.
int N;

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j != 0) {
                int tmp = j - 1;
                for(int k = 0; k < 1024; k++) {
                    if(dp[i-1][tmp][k] != 0) dp[i][j][k | (1 << j)] = (dp[i-1][tmp][k] + dp[i][j][k | (1 << j)]) % divisor; 
                }
            } if(j != 9) {
                int tmp = j + 1;
                for(int k = 0; k < 1024; k++) {
                    if(dp[i-1][tmp][k] != 0) dp[i][j][k | (1 << j)] = (dp[i-1][tmp][k] + dp[i][j][k | (1 << j)]) % divisor; 
                }
            }
        }
    }
    int result = 0;
    for(int i = 0; i < 10; i++) result = (result + dp[N][i][1023]) % divisor;
    printf("%d\n", result);
    return 0;
}
