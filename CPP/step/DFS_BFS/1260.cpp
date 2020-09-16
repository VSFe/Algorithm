/*
Problem: DFS와 BFS (1260)
Tier: Silver 1
Detail: 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
정점 번호는 1번부터 N번까지이다.
Comment: DFS, BFS 구현해보는 문제니까 뭐... 딱히 어렵지는 않음.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> dfs_visited;
vector<int> bfs_visited;
vector<vector<int>> graph;
queue<int> bfs_queue;

int N, M, Y;

void dfs(int u) {
    dfs_visited[u] = 1;
    printf("%d ", u+1);
    int size = graph[u].size();
    for(int i = 0; i < size; i++) {
        int tmp = graph[u][i];
        if(dfs_visited[tmp] == 0) dfs(tmp);
    }
}

void bfs(int u) {
    bfs_visited[u] = 1;
    bfs_queue.push(u);
    while(!bfs_queue.empty()) {
        int t = bfs_queue.front(); bfs_queue.pop();
        printf("%d ", t+1);
        int size = graph[t].size();
        for(int i = 0; i < size; i++) {
            int tmp = graph[t][i];
            if(bfs_visited[tmp] == 0) {
                bfs_queue.push(tmp);
                bfs_visited[tmp] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &Y);
    bfs_visited = vector<int>(N, 0);
    dfs_visited = vector<int>(N, 0);
    graph.reserve(N);
    for(int i = 0; i < M; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1-1].push_back(tmp2-1);
        graph[tmp2-1].push_back(tmp1-1);
    }
    for(int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(Y-1);
    printf("\n");
    bfs(Y-1);
    return 0;
}
