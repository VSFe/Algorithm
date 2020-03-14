#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void travel(int x, int y, const int graph[][50], int visited[][50]) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == N) continue;
        if(graph[x+dx[i]][y+dy[i]] == 1 && visited[x+dx[i]][y+dy[i]] == 0) {
            travel(x + dx[i], y + dy[i], graph, visited);
        }
    }

}

int main() {
    scanf("%d", &N); 
    for(int i = 0; i < N; i++) {
        int graph[50][50] = {0, };
        int visited[50][50]  = {0, };
        int x, y, k;
        int cnt = 0;
        scanf("%d %d %d", &x, &y, &k);
        for(int i = 0; i < k; i++) {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            graph[tmp1][tmp2] = 1;
        }
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(graph[i][j] == 1 && visited[i][j] == 0) {
                    cnt++;
                    travel(i, j, graph, visited);
                }  
            }
        }
        printf("%d\n", cnt);
    }    
}