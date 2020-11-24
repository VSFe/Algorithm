#include <bits/stdc++.h>
using namespace std;

struct node {
    int to, dist;
    bool enable;
};

vector<node> graph[100001];
typedef long long ll;

int N, M, C, A, B;
const ll INF = 1e14;

bool get_dijkstra(ll target) {
    for(int i = 0; i < N; i++) {
        for(auto next: graph[i]) {
            if(next.dist > target) {
                next.enable = false;      // 수정이 왜 안됨???
                cout << "ㅁㄴㅇㄹ" << '\n';
                cout << next.enable << '\n';             
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(auto next: graph[i]) {
            cout << next.enable << '\n';
        }
    }

    vector<ll> dist = vector<ll>(N+1, INF);
    priority_queue<pair<ll, int>> pq;

    dist[A - 1] = 0;
    pq.push({0, A - 1});

    while(!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        if(p.first > dist[p.second]) continue;
        
        for(auto node: graph[p.second]) {
            if(!node.enable) continue;
            if(dist[p.second] + node.dist < dist[node.to]) {
                dist[node.to] = dist[p.second] + node.dist;
                pq.push({dist[node.to], node.dist});
            }
        }
    }

    if(dist[B - 1] <= C) return true;
    return false;
}

void recover() {
    for(int i = 0; i < N; i++) {
        for(auto node: graph[i])
            node.enable = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> A >> B >> C;

    for(int i = 0; i < M; i++) {
        int x, y, len;
        cin >> x >> y >> len;
        graph[x - 1].push_back({y - 1, len, 1});
        graph[y - 1].push_back({x - 1, len, 1});
    }

    ll left = 0, right = 2;
    ll mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(get_dijkstra(mid)) right = mid;
        else left = mid + 1;

        recover();
    }

    cout << mid;
}