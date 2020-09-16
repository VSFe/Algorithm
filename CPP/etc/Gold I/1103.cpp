/*
Problem: 게임 (1103)
Tier: Gold 1
Detail: 형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 재밌는 게임을 한다.
일단 보드의 가장 왼쪽 위에 동전을 하나 올려놓는다. 그다음에 다음과 같이 동전을 움직인다.
    동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
    위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
    동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.
만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 싶다.
보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램을 작성하시오.
Comment: SCC 구할 때 사용하는 방식을 조금만 활용하면 풀리는 DP 문제.
이런거 재밌당.
*/


#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1e9;

int N, M;
int dp[50][50];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char dt[50][50];

int cal_dp(int x, int y) {
    int &ret = dp[x][y];
    if(ret == -2) return INF;
    else if(ret != -1) return ret;

    ret = -2;
    int MAX = 0, size = dt[x][y] - '0';
    for(int i = 0; i < 4; i++) {
        int X = x + dx[i] * size, Y = y + dy[i] * size;
        if(X < 0 || X >= N || Y < 0 || Y >= M) continue;
        if(dt[X][Y] != 'H') MAX = max(MAX, cal_dp(X, Y) + 1);
    }

    return ret = MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++)
            cin >> dt[i][j];

    memset(dp, -1, sizeof(dp));
    int ans = cal_dp(0, 0);
    if(ans >= INF) cout << -1;
    else cout << ans + 1;
}