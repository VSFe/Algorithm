/*
Problem: 구간 합 구하기 5(11660)
Tier: Silver 1
Detail: 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오.
(x, y)는 x행 y열을 의미한다.
Comment: 스포일러 당한 것 같은데 ㅎㅎ.....
그거랑 별개로 바텀업으로 채울 경우, 굳이 케이스를 여러개로 나누는 뻘짓 보다는 담는 공간의 크기를 늘려서
모든 경우에 대응할 수 있도록 만드는게 훨씬 낫다...
*/

#include <stdio.h>

int data[1025][1025];
int dp[1025][1025];
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < N+1; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    dp[1][1] = data[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + data[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        int s_x, s_y, e_x, e_y;
        scanf("%d %d %d %d", &s_x, &s_y, &e_x, &e_y);
        printf("%d\n", dp[e_x][e_y] - dp[s_x-1][e_y] - dp[e_x][s_y-1] + dp[s_x-1][s_y-1]);
    }
   return 0;
} 