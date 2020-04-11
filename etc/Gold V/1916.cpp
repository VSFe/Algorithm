/*
Problem: 최소비용 구하기
Tier: Gold 5
Detail: N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.
Comment: 다익스트라...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
    int dist, node;
    edge() {}
    edge(int a, int b) : dist(a), node(b) {}
};

bool operator <(edge a, edge b) {
    return a.dist > b.dist;
} 

vector<edge> graph[1001];
int dist[1001], N, M;
priority_queue<edge> pq;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({z, y});
    }
    int start, end; cin >> start >> end;
    for(int i = 1; i <= N; i++) dist[i] = INF;
    dist[start] = 0; 
    pq.push({0, start});
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if(e.dist > dist[e.node]) continue;
        for(auto next : graph[e.node]) {
            if(dist[e.node] + next.dist < dist[next.node]) {
                dist[next.node] = dist[e.node] + next.dist;
                pq.push({dist[next.node], next.node});
            }
        }
    }
    cout << dist[end];
}