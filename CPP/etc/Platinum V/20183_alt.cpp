#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int, ll>> graph[100001];

int N, M, C, A, B;
const ll INF = 1e14 + 1;

bool get_dijkstra(ll target) {
    vector<ll> dist = vector<ll>(N+1, C + 1);
    priority_queue<pair<ll, int>> pq;

    dist[A - 1] = 0;
    pq.push({0, A - 1});

    while(!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        if(p.first > dist[p.second]) continue;
        
        for(auto node: graph[p.second]) {
            if(node.second > target) continue;
            if(dist[p.second] + node.second < dist[node.first]) {
                dist[node.first] = dist[p.second] + node.second;
                pq.push({dist[node.first], node.first});
            }
        }
    }

    if(dist[B - 1] <= C) return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> A >> B >> C;

    for(int i = 0; i < M; i++) {
        int x, y;
        ll len;
        cin >> x >> y >> len;

        graph[x - 1].push_back({y - 1, len});
        graph[y - 1].push_back({x - 1, len});
    }

    ll left = 0, right = INF;
    ll mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(get_dijkstra(mid)) right = mid;
        else left = mid + 1;
    }

    if(right == INF) cout << -1;
    else cout << right;
}