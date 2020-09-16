/*
Problem: 도시 분할 계획 (1647)
Tier: Gold 4
Detail: 동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다. 그러다가 평화로운 마을에 가게 되었는데, 그곳에서는 알 수 없는 일이 벌어지고 있었다.
마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져 있다. 길은 어느 방향으로든지 다닐 수 있는 편리한 길이다. 그리고 각 길마다 길을 유지하는데 드는 유지비가 있다.
마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다. 마을이 너무 커서 혼자서는 관리할 수 없기 때문이다.
마을을 분할할 때는 각 분리된 마을 안에 집들이 서로 연결되도록 분할해야 한다. 각 분리된 마을 안에 있는 임의의 두 집 사이에 경로가 항상 존재해야 한다는 뜻이다. 마을에는 집이 하나 이상 있어야 한다.
그렇게 마을의 이장은 계획을 세우다가 마을 안에 길이 너무 많다는 생각을 하게 되었다. 일단 분리된 두 마을 사이에 있는 길들은 필요가 없으므로 없앨 수 있다.
그리고 각 분리된 마을 안에서도 임의의 두 집 사이에 경로가 항상 존재하게 하면서 길을 더 없앨 수 있다. 마을의 이장은 위 조건을 만족하도록 길들을 모두 없애고 나머지 길의 유지비의 합을 최소로 하고 싶다.
이것을 구하는 프로그램을 작성하시오.
Comment: MST -> 모든 선이 단절선임.
끊게 된다면 컴포넌트가 두개로 분리 -> 따라서 MST를 만들고 거기에서 가장 가중치가 큰 간선 하나만 더 빼버리면 게임 끝.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, dist;
    edge() : edge(-1, -1, 0) {}
    edge(int _u, int _v, int _dist) : u(_u), v(_v), dist(_dist) {}
    bool operator <(const edge& e) const { return dist < e.dist; }
};

int N, M, ans = 0, cnt = 0, uf[100001];
edge Edges[1000001];

int uf_find(int x) {
    return (uf[x] == -1) ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int p_x = uf_find(x), p_y = uf_find(y);
    if(p_x == p_y) return false;
    uf[p_y] = p_x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int u, v, dist;
    cin >> N >> M;
    if(N == 0) return 0;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> dist;
        Edges[i] = edge(u, v, dist);
    }
    sort(Edges, Edges + M);
    fill(uf, uf + N + 1, -1);
    for(int i = 0; ; i++) {
        if(uf_union(Edges[i].u, Edges[i].v)) {
            ans += Edges[i].dist;
            if(++cnt == N - 2) break;
        }
    }
    cout << ans;
}