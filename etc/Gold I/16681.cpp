/*
Problem: 등산
Tier: Gold 1
Detail: 주환이는 요즘 등산에 빠졌다. 주환이는 등산을 위해 지도를 가지고 있는데, 그 지도에는 각 지점의 높이와 갈 수 있는 다른 지점까지의 거리가 표시되어 있다.
주환이는 아침에 집에서 출발하여 등산을 갔다가, 오후 수업을 듣기 위해 고려대학교로 돌아와야 한다.
    주환이는 지도의 임의의 지점을 골라, 그 지점을 목표로 정한다. 집 또는 고려대학교는 목표로 선택할 수 없다.
    주환이가 집에서 정한 목표에 도달할 때 까지는 항상 높이가 증가하는 방향으로만 이동해야 한다.
    주환이가 정한 목표에 도달한 후, 고려대학교로 갈 때에는 항상 높이가 감소하는 방향으로만 이동해야 한다.
    주환이는 거리 1을 움직일 때 마다 D 의 체력이 소모된다.
    주환이는 정한 목표에 도달하면 높이 1당 E 의 성취감을 얻는다. 즉 높이가 h인 목표에 도달하면 hE의 성취감을 얻는다.
주환이는 이 등산의 가치를 (얻은 성취감) - (소모한 체력) 으로 계산하기로 하였다. 주환이를 위해 가치가 가장 높은 등산 경로를 선택해주자.
Comment: 다익스트라에 조건 하나만 넣어주면 되는거였다...
실수가 너무 많았고... PQ를 사용하는 이유를 배운 기분.
*/

#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const ll INF = 1e12;

struct edge {
    ll dist;
    int u;
    edge() {}
    edge(ll dist, int u) : dist(dist), u(u) {}
};

bool operator <(edge a, edge b) {
    return a.dist > b.dist;
}

vector<edge> graph[101];
ll height[101], dist_home[101], dist_yonsei[101], MAX = -INF;
int N, M, D, E;
priority_queue<edge> pq;
bool is_way = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> D >> E;
    for(int i = 1; i <= N; i++) cin >> height[i];
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    for(int i = 2; i <= N; i++) dist_home[i] = INF;
    for(int i = 1; i < N; i++) dist_yonsei[i] = INF;
    pq.push({0, 1});
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if(e.dist > dist_home[e.u]) continue;
        for(auto next : graph[e.u]) {
            if(height[e.u] >= height[next.u]) continue;
            if(dist_home[e.u] + next.dist < dist_home[next.u]) {
                dist_home[next.u] = dist_home[e.u] + next.dist;
                pq.push({dist_home[next.u], next.u});
            }
        }
    }
    pq.push({0, N});
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if(e.dist > dist_yonsei[e.u]) continue;
        for(auto next : graph[e.u]) {
            if(height[e.u] >= height[next.u]) continue;
            if(dist_yonsei[e.u] + next.dist < dist_yonsei[next.u]) {
                dist_yonsei[next.u] = dist_yonsei[e.u] + next.dist;
                pq.push({dist_yonsei[next.u], next.u});
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dist_home[i] == INF || dist_yonsei[i] == INF) continue;
        is_way = true;
        ll sum = dist_home[i] + dist_yonsei[i];
        ll tmp = (ll)(height[i]) * E - sum * D;
        MAX = max(MAX, tmp);
    }
    if(!is_way) cout << "Impossible";
    else cout << MAX;
}
