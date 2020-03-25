/*
Problem: 1로 만들기 2 (12852)
Tier: Silver 1
Detail: 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
    X가 3으로 나누어 떨어지면, 3으로 나눈다.
    X가 2로 나누어 떨어지면, 2로 나눈다.
    1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
Comment: 그저 배열에 한줄만 추가해주면 된다...
*/

#define INF 10000000;
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000001][2];

int main() {
    int N;
    scanf("%d", &N);
    dp[1][0] = 0;
    dp[2][0] = 1, dp[2][1] = 1;
    dp[3][0] = 1, dp[3][1] = 1;
    for(int i = 4; i <= N; i++) {
        int num1 = dp[i-1][0];
        int num2 = (i % 3 == 0) ? dp[i/3][0] : INF;
        int num3 = (i % 2 == 0) ? dp[i/2][0] : INF;
        int MIN = min({num1, num2, num3});
        dp[i][0] = MIN + 1;
        if(MIN == num1) dp[i][1] = i-1;
        else if(MIN == num2) dp[i][1] = i/3;
        else dp[i][1] = i/2;
    }
    int IDX = dp[N][0];
    int way = N;
    printf("%d\n", IDX);
    for(int i = 0; i < IDX + 1; i++) {
        printf("%d ", way);
        way = dp[way][1];
    }
    return 0;
}