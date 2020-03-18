/*
Problem: 미확인 도착지 (9370)
Tier: Gold 2
Detail: 가중치가 주어진 그래프가 있고 특정 간선을 지나갔다고 가정할 때,
특정 출발점에서 출발해 목적지까지 최단거리로 갔다고 하자. 이 때 주어진 목적지 후보 중 가능한 것들을 모두 고르시오.
Comment: 1504번의 응용.
*/

#define INF 50000001
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int T;

vector<int> djikstra(const vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        int len = p.first, y = p.second;
        int size = graph[y].size();
        for(int i = 0; i < size; i++) {
            pair<int, int> v = graph[y][i];
            if(dist[v.second] > dist[y] + v.first) {
                dist[v.second] = dist[y] + v.first;
                pq.push(make_pair(dist[v.second], v.second));
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        int n, m, t, s, g, h;
        scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
        vector<vector<pair<int, int>>> graph(n+1);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            graph[a].push_back(make_pair(c, b));
            graph[b].push_back(make_pair(c, a));
        }
        vector<int> dist_s = djikstra(graph, s);
        vector<int> dist_g = djikstra(graph, g);
        vector<int> dist_h = djikstra(graph, h);
        vector<int> candidate;
        for(int i = 0; i < t; i++) {
            int candi;
            scanf("%d", &candi);
            if(min(dist_s[g] + dist_g[h] + dist_h[candi], dist_s[h] + dist_h[g] + dist_g[candi]) == dist_s[candi]) candidate.push_back(candi);
        }
        sort(candidate.begin(), candidate.end());
        int size = candidate.size();
        for(int i = 0; i < size; i++) printf("%d ", candidate[i]);
        printf("\n");
    }
}