/*
Problem: 알파벳 (1987)
Tier: Gold 3
Detail: 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
Comment: DFS든 BFS든 일단 해보는데, 비트마스크를 쓰기에는 알파벳이 너무 많아서...
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int MAX = 0;
int R, C;
char dt[20][20];

void dfs(int x, int y, int visited[26], int cnt) {
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == R || y + dy[i] < 0 || y + dy[i] == C) continue;
        int tmp = dt[x + dx[i]][y + dy[i]] - 'A';
        if(visited[tmp] == 0) {
            cnt++;
            visited[tmp] = 1;
            dfs(x + dx[i], y + dy[i], visited, cnt);
            visited[tmp] = 0;
            cnt--;
        }
    }
    MAX = max(MAX, cnt);
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        scanf("%s", dt[i]);
    }
    int visited[26] = {0,};
    visited[dt[0][0] - 'A'] = 1;
    dfs(0, 0, visited, 1);
    printf("%d", MAX);
    return 0;
}