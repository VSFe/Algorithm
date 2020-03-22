/*
Problem: 운동 (1956)
Tier: Gold 4
Detail: 도로의 정보가 주어졌을 때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램을 작성하시오.
두 마을을 왕복하는 경우도 사이클에 포함됨에 주의한다.
Comment: 플로이드 워셜 사용 + O(N^2) 전체 탐색
*/

#define INF 10000001
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;
int MIN = INF;

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
            if(dist[i][j] == 0 || dist[i][j] == 0) continue;
            MIN = min(MIN, dist[i][j] + dist[j][i]);
        }
    }
    printf("%d", (MIN == INF) ? -1 : MIN);
    return 0;
}