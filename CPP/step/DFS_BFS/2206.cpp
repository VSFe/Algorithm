/*
Problem: 벽 부수고 이동하기
Tier: Gold 4
Detail: N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데,
이때 시작하는 칸과 끝나는 칸도 포함해서 센다. 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.
맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
Comment: visited 와 queue에 들어가는 간선의 구조:
<x좌표, <y좌표, 벽을 뚫었는지에 대한 여부>>
*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, pair<int, int>>> q;
int graph[1000][1000];
int visited[1000][1000][2];
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) { for(int j = 0; j < M; j++) scanf("%1d", &graph[i][j]); }
    visited[0][0][0] = 1;
    q.push(make_pair(0, make_pair(0, 0)));
    while(!q.empty()) {
        pair<int, pair<int, int>> p = q.front(); q.pop();
        int x = p.first, y = p.second.first, z = p.second.second;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
            if(graph[x + dx[i]][y + dy[i]] == 0) {
                if(visited[x + dx[i]][y + dy[i]][z] == 0) {
                    q.push(make_pair(x + dx[i], make_pair(y + dy[i], z)));
                    visited[x + dx[i]][y + dy[i]][z] =  visited[x][y][z] + 1;
                }
            } else if(z == 0 && visited[x + dx[i]][y + dy[i]][1] == 0) {
                q.push(make_pair(x + dx[i], make_pair(y + dy[i], 1)));
                visited[x + dx[i]][y + dy[i]][1] =  visited[x][y][z] + 1;
            }
        }
    }
    int MIN = min(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    int MAX = max(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    if(MAX == 0) printf("-1");
    else if(MIN == 0) printf("%d", MAX);
    else printf("%d", MIN);
    return 0;
}