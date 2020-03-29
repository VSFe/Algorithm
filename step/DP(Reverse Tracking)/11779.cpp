/*
Problem: 최소비용 구하기 2
Tier: Gold 3
Detail: n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라.
항상 시작점에서 도착점으로의 경로가 존재한다.
Comment: 다익스트라 진행하면서 경로만 메모이제이션 해주면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 100000000;
vector<vector<pair<int, int>>> edges;
int dist[1001], visited[1001];
int V, E;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start, int end) {
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        int prev_len = p.first, prev_idx = p.second;
        for(int i = 0; i < edges[prev_idx].size(); i++) {
            int v = edges[prev_idx][i].first;
            if(dist[v] > dist[prev_idx] + edges[prev_idx][i].second) {
                dist[v] = dist[prev_idx] + edges[prev_idx][i].second;
                visited[v]= prev_idx;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    int cnt = 0, tmp = end;
    vector<int> path;
    while(tmp != start) {
        cnt++;
        path.push_back(tmp);
        tmp = visited[tmp];
    }
    cout << dist[end] << '\n' << cnt + 1 << '\n' << start << ' ';
    for(int i = 1; i <= path.size(); i++) cout << *(path.end() - i) << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for(int i = 0; i < 1001; i++) dist[i] = INF;
    edges.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int u, v, price;
        cin >> u >> v >> price;
        edges[u].push_back(make_pair(v, price));
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
    return 0;
}