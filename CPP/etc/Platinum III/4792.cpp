/*
Problem: 레드 블루 스패닝 트리
Tier: Platinum 3
Detail: 무방향, 무가중치, 연결 그래프가 주어진다. 그래프의 각 간선은 빨간색 또는 파란색으로 색칠되어져 있다.
이 그래프의 스패닝 트리 중 파란색 간선이 정확히 k개인 것이 있는지 없는지 알아내는 프로그램을 작성하시오.
Comment: 탐욕적으로 접근하면, 스패닝 트리에서의 최대 블루 간선과 최소 블루 간선 사이에만 들어 있으면 된다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, dist;
    edge(int _u, int _v, int _dist) : u(_u), v(_v), dist(_dist) {}
};

vector<edge> Edges;
int N, M, K, uf[1001];

int uf_find(int x) {
    return (uf[x] == x) ? x : uf[x] = uf_find(uf[x]);
}

void uf_union(int x, int y) {
    int p_x = uf_find(x), p_y = uf_find(y);
    uf[p_y] = p_x;
}

bool operator < (const edge &a, const edge &b) {
    if(a.dist == b.dist) {
        return a.u < b.u;
    }
    return a.dist < b.dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true) {
        cin >> N >> M >> K;
        if(N == 0) return 0;
        int ans1 = 0, ans2 = 0;
        Edges.clear();
        for(int i = 1; i <= N; i++) uf[i] = i;
        for(int i = 0; i < M; i++) {
            char c; int u, v; cin >> c >> u >> v;
            if(c == 'B') Edges.push_back({u, v, 1});
            else Edges.push_back({u, v, 10});
        }
        sort(Edges.begin(), Edges.end());
        for(int i = 0; i < Edges.size(); i++) {
            int u = Edges[i].u, v = Edges[i].v, dist = Edges[i].dist;
            if(uf_find(u) == uf_find(v)) continue;
            if(dist == 1) ans1++;
            uf_union(u, v);
        }
        for(int i = 0; i < Edges.size(); i++) {
            if(Edges[i].dist == 1) Edges[i].dist = 10;
            else Edges[i].dist = 1;
        }
        for(int i = 1; i <= N; i++) uf[i] = i;
        for(int i = Edges.size() - 1; i >= 0; i--) {
            int u = Edges[i].u, v = Edges[i].v, dist = Edges[i].dist;
            if(uf_find(u) == uf_find(v)) continue;
            if(dist == 10) ans2++;
            uf_union(u, v);
        }
        if(ans1 > ans2) {
            if(ans2 <= K && ans1 >= K) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            if(ans1 <= K && ans2 >= K) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}