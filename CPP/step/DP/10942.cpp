/*
Problem: 팰린드롬? (10942)
Tier: Gold 2
Detail: 먼저, 홍준이는 자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.
각 질문은 두 정수 S와 E로 나타낼 수 있으며, S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보며, 명우는 각 질문에 대해 팰린드롬이다 또는 아니다를 말해야 한다.
예를 들어, 홍준이가 칠판에 적은 수가 1, 2, 1, 3, 1, 2, 1라고 하자.
    S = 1, E = 3인 경우 1, 2, 1은 팰린드롬이다.
    S = 2, E = 5인 경우 2, 1, 3, 1은 팰린드롬이 아니다.
    S = 3, E = 3인 경우 1은 팰린드롬이다.
    S = 5, E = 7인 경우 1, 2, 1은 팰린드롬이다.
자연수 N개와 질문 M개가 모두 주어졌을 때, 명우의 대답을 구하는 프로그램을 작성하시오.
Comment: isPal[i][j] = True if isPal[i+1][j-1] = True and data[i] = data[j]
*/

#include <stdio.h>

int N, M;
int dp[2001][2001];
int data[2001];

int cal_pan(int s, int e) {
    if(dp[s][e] != 0) return dp[s][e];
    while(true) {
        if(dp[s+1][e-1] != 0) {
            if(dp[s+1][e-1] == 1 && data[s] == data[e]) return dp[s][e] = 1;
            else return dp[s][e] = -1;
        } else cal_pan(s+1, e-1);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &data[i]);
    for(int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }
    for(int i = 0; i < N-1; i++) {
        if(data[i+1] != data[i+2]) dp[i+1][i+2] = -1;
        else dp[i+1][i+2] = 1;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int tmp1, tmp2, result;
        scanf("%d %d", &tmp1, &tmp2);
        result = cal_pan(tmp1, tmp2);
        if(result == 1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}