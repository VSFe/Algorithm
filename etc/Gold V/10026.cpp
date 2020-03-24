/*
Problem: 적록색약 (10026)
Tier: Gold 5
Detail: 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
예를 들어, 그림이 아래와 같은 경우에
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.
Comment: 단순한 Flood fill 응용 문제.
*/

#include <stdio.h>

int graph[100][100], alt_graph[100][100], visited[100][100], alt_visited[100][100];
int N, cnt = 0, alt_cnt = 0;

void dfs(int x, int y, bool is_normal, int num) {
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    if(is_normal) visited[x][y] = 1;
    else alt_visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == N) continue;
        if(is_normal) { if(visited[x + dx[i]][y + dy[i]] == 0 && graph[x + dx[i]][y + dy[i]] == num) dfs(x + dx[i], y + dy[i], is_normal, num); }
        else { if(alt_visited[x + dx[i]][y + dy[i]] == 0 && alt_graph[x + dx[i]][y + dy[i]] == num) dfs(x + dx[i], y + dy[i], is_normal, num); }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        getchar();
        for(int j = 0; j < N; j++) {
            char c; scanf("%c", &c);
            if(c == 'R') graph[i][j] = 1, alt_graph[i][j] = 1;
            else if(c == 'B') graph[i][j] = 2, alt_graph[i][j] = 2;
            else if(c == 'G') graph[i][j] = 3, alt_graph[i][j] = 1;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] == 0) { 
                dfs(i, j, true, graph[i][j]);
                cnt++;
            }
            if(alt_visited[i][j] == 0) { 
                dfs(i, j, false, alt_graph[i][j]);
                alt_cnt++;
            }
        }
    }
    printf("%d %d", cnt, alt_cnt);
}