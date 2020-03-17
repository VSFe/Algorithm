/*
Problem: 최단경로
Tier: Gold 5
Detail: 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.
단, 모든 간선의 가중치는 10 이하의 자연수이다.
Comment: 다익스트라...
*/

#define INF 10000000
#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, S;
vector<int> dist;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    scanf("%d %d %d", &V, &E, &S);
    dist = vector<int>(V+1, INF);
    graph.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
    }
    dist[S] = 0;
    pq.push(make_pair(0, S));
    while(!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        if(p.first > dist[p.second]) continue;
        int size = graph[p.second].size();
        for(int i = 0; i < size; i++) {
            pair<int, int> v = graph[p.second][i];
            if(dist[p.second] + v.first< dist[v.second]) {
                dist[v.second] = dist[p.second] + v.first;
                pq.push(make_pair(dist[v.second], v.second));
            }
        }
    }
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
    return 0;
}