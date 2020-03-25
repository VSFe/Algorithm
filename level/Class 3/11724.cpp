/*
Problem: 연결 요소의 개수
Tier: Silver 3
Detail: 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
Comment: DFS...
*/

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int V, E, result = 0;

void dfs(int x) {
    visited[x] = 1;
    for(int i = 0; i < graph[x].size(); i++) {
        if(visited[graph[x][i]] == 0) dfs(graph[x][i]);
    }
}

int main() {
    scanf("%d %d", &V, &E);
    visited.assign(V+1, 0);
    graph.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y); graph[y].push_back(x);
    }
    for(int i = 1; i <= V; i++) {
        if(visited[i] == 0) {
            result++;
            dfs(i);
        }
    }
    printf("%d", result);
    return 0;
}