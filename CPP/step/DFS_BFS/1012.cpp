/*
Problem: 유기농 배추 (1012)
Tier: Silver 1
Detail: 차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다.
농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다.
이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)
한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다.
배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.
Comment: Flood fill 문제... 어렵지 않습니다 오호홍
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int graph[50][50];
int visited[50][50];
int T, N, M, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] == N || x + dx[i] < 0 || y + dy[i] == M || y + dy[i] < 0) continue;
        if(graph[x + dx[i]][y + dy[i]] == 1 && visited[x + dx[i]][y + dy[i]] == 0) dfs(x + dx[i], y + dy[i]); 
    }
}

int main() {
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        int cnt = 0;
        scanf("%d %d %d", &N, &M, &C);
        for(int i = 0; i < C; i++) {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            graph[tmp1][tmp2] = 1;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] == 1 && visited[i][j] == 0){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                graph[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
    return 0;
}