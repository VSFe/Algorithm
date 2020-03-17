/*
Problem: 플로이드
Tier: Gold 4
Detail: n(1 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.
모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 플로이드 워셜 알고리즘...
*/

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