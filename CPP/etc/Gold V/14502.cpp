/*
Problem: 연구소 (14502)
Tier: Gold 5
Detail: 인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 
일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.
2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.
연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.
Comment: 가장 많은 케이스는 62C3 * O(V + E) ~~ 120만회라 브루트포스로 뚫을 수 있을 것 같음.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[8][8], visited[8][8];
int N, M, cnt;
int MAX = -1;

void dfs(int graph[8][8], int visited[8][8], int &cnt, int x, int y) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
        if(graph[x + dx[i]][y + dy[i]] == 0) {
            graph[x + dx[i]][y + dy[i]] = 2;
            cnt--;
            dfs(graph, visited, cnt, x + dx[i], y + dy[i]);
        }
    }
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cnt = N * M - 3;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if(graph[i][j] != 0) cnt--;
        }
    }
    for(int i = 0; i < N * M - 2; i++) {
        for(int j = i+1; j < N * M - 1; j++) {
            for(int k = j+1; k < N * M; k++) {
                int i_x = i / M, i_y = i % M, j_x = j / M, j_y = j % M, k_x = k / M, k_y = k % M;
                if(!(graph[i_x][i_y] == 0 && graph[j_x][j_y] == 0 && graph[k_x][k_y] == 0)) continue;
                int graph_tmp[8][8], visited_tmp[8][8] = {{0,}}, cnt_tmp = cnt;
                for(int tmp_x = 0; tmp_x < 8; tmp_x++) {
                    for(int tmp_y = 0; tmp_y < 8; tmp_y++) {
                        graph_tmp[tmp_x][tmp_y] = graph[tmp_x][tmp_y];
                    }
                }
                graph_tmp[i_x][i_y] = 1, graph_tmp[j_x][j_y] = 1, graph_tmp[k_x][k_y] = 1;
                for(int x = 0; x < N; x++) {
                    for(int y = 0; y < M; y++) {
                        if(graph[x][y] == 2 && visited[x][y] == 0) dfs(graph_tmp, visited_tmp, cnt_tmp, x, y);
                    }
                }
                MAX = max(MAX, cnt_tmp);
            }
        }
    }
    printf("%d", MAX);
    return 0;
}