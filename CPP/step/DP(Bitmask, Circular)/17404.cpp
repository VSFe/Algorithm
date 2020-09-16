/*
Problem: RGB거리 2 (17404)
Tier: Gold 4
Detail: RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
    1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
    N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
    i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
Comment: 원형이니까...
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000][3];
int data[1000][3];
int N;
int MIN = 10000000;
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        data[i][0] = a, data[i][1] = b, data[i][2] = c;
    }
    for(int i = 1; i <= 3; i++) {
        int div = 5 % i;
        for(int j = 0; j < 3; j++) {
            if(j == div) dp[0][j] = data[0][j];
            else dp[0][j] = MIN;
        }
        for(int k = 1; k < N; k++) {
            dp[k][0] = min(dp[k-1][1], dp[k-1][2]) + data[k][0];
            dp[k][1] = min(dp[k-1][0], dp[k-1][2]) + data[k][1];
            dp[k][2] = min(dp[k-1][0], dp[k-1][1]) + data[k][2];
        }
        for(int k = 0; k < 3; k++) {
            if(k == div) continue;
            MIN = min(dp[N-1][k], MIN);
        }
    }
    printf("%d", MIN);
    return 0;   
}