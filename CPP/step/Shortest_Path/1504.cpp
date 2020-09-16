/*
Problem: 특정한 최단경로
Tier: Gold 4
Detail: 방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다.
또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.
세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라.
1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.
Comment: 다익스트라를 1이 시작점일 때, A가 시작점일 때, B가 시작점일 때 각각 세번 돌려서
return MIN(dist_1[A] + dist_A[B] + dist_B[N], dist_1[B] + dist_B[A] + dist_A[N]) 을 돌리면 될 것 같음.
*/

#define INF 200000000
#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, A, B;
vector<int> dist_1, dist_A, dist_B;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijsktra(vector<int> &dist, int start) {
    dist[start] = 0;
    pq.push(make_pair(0, start));
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
}

int main() {
    scanf("%d %d", &V, &E);
    dist_1 = vector<int>(V+1, INF);
    dist_A = vector<int>(V+1, INF);
    dist_B = vector<int>(V+1, INF);
    graph.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }
    scanf("%d %d", &A, &B);
    dijsktra(dist_1, 1);
    dijsktra(dist_A, A);
    dijsktra(dist_B, B);
    int MIN = min(dist_1[A] + dist_A[B] + dist_B[V], dist_1[B] + dist_B[A] + dist_A[V]);
    if(MIN > INF) printf("-1");
    else printf("%d", min(dist_1[A] + dist_A[B] + dist_B[V], dist_1[B] + dist_B[A] + dist_A[V]));
    return 0;
}