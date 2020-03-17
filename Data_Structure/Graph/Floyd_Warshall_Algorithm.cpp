#define INF 10000001
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;

int main() {
    scanf("%d %d", &N, &M);
    dist = vector<vector<int>>(N+1, vector<int>(N+1, INF));
    for(int i = 1; i <= N; i++) dist[i][i] = 0;
    graph.reserve(N+1);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
        dist[a][b] = min(dist[a][b], c);
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k]) dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            printf("%d ", (dist[i][j] == INF) ? 0 : dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}