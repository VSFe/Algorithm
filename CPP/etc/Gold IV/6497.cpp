/*
Problem: 전력난 (6497)
Tier: Gold 4
Detail: 성진이는 한 도시의 시장인데 거지라서 전력난에 끙끙댄다. 그래서 모든 길마다 원래 켜져 있던 가로등 중 일부를 소등하기로 하였다.
길의 가로등을 켜 두면 하루에 길의 미터 수만큼 돈이 들어가는데, 일부를 소등하여 그만큼의 돈을 절약할 수 있다.
그러나 만약 어떤 두 집을 왕래할 때, 불이 켜져 있지 않은 길을 반드시 지나야 한다면 위험하다. 그래서 도시에 있는 모든 두 집 쌍에 대해, 불이 켜진 길만으로 서로를 왕래할 수 있어야 한다.
위 조건을 지키면서 절약할 수 있는 최대 액수를 구하시오.
Comment: 말은 길지만 결국 평범한 크루스컬 알고리즘...
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, dist;
    edge(int _u, int _v, int _dist) : u(_u), v(_v), dist(_dist) {}
};

int N, M, uf[200001];
vector<edge> Edges;

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
        int ans = 0, total = 0, cnt = 0;
        cin >> N >> M;
        if(N == 0) return 0;
        Edges.clear();
        for(int i = 0; i < N; i++) uf[i] = i;
        for(int i = 0; i < M; i++) {
            int u, v, dist; cin >> u >> v >> dist;
            total += dist;
            Edges.push_back({u, v, dist});
        }
        sort(Edges.begin(), Edges.end());
        for(int i = 0; i < Edges.size(); i++) {
            edge e = Edges[i];
            if(uf_find(e.u) == uf_find(e.v)) continue;
            ans += e.dist;
            cnt++;
            uf_union(e.u, e.v);
            if(cnt == N - 1) break;
        }
        cout << total - ans << '\n';
    }
}