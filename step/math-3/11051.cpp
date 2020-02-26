/*
Problem: 이항 계수 2 (11051)
Tier: Silver 1
Detail: 자연수 과 정수 가 주어졌을 때 이항 계수 를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.
Comment: nCk = n!(n-k)! * k!
하키스틱 공식 (파스칼의 삼각형에서 도출) 이용해서 품.
*/

#include <stdio.h>

int N, K;
int dp[1001][1001];

int sum(int s, int e) {
    int tmp = 0;
    for(int i = 0; i <= e; i++) tmp += dp[s+i-1][i];
    return tmp;
}

int main () {
    scanf("%d %d", &N, &K);
    for(int i = 0; i <= K; i++) dp[i][i] = 1;
    int N_s = 0;
    while(N_s != N - K) {
        N_s++;
        for(int i = 0; i <= K; i++) dp[i+N_s][i] = sum(N_s, i) % 10007;
    }
    if(N!= K) dp[N][K] = sum(N-K, K) % 10007;
    printf("%d", dp[N][K]);
    return 0;
}