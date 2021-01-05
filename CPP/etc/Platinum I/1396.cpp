/*
idea: 크루스컬로 MST를 형성하는 과정을 시뮬레이션 해보자.
특정 간선을 선택하면, 그 두 노드를 이어주는 새로운 노드를 만들어주고, 선택된 노드를 새로운 노드에 연결한다.
그리고 새로운 노드에 길이, 아래에 있는 Leaf 노드의 수를 저장한다.

MST를 생성하게 되면 결국 트리 구조니까, LCA를 구할 수 있게 될 것이다.
어차피 위에서 언급한 방식으로 만들게 되면 원래 노드들은 반드시 Leaf임이 보장되기 때문에, 자기 자신을 선택하지 않는 이상 LCA는 새로 생성된 노드 중 하나 일 것이다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, pair<int, int>> pp;

const int SIZE = 21;

int parent[19][SIZE]; // LCA 만들기 위한 Sparse Table
int depth[SIZE]; // LCA 만들기 위한 깊이 정보 저장
int uf_kruskal[SIZE]; // 크-루스컬
int dist[SIZE]; // LCA가 될 수 있는 후보들에 한해, 길이의 최댓값 저장
int count[SIZE]; // Leaf 노드의 수 저장
bool visited[SIZE];
vector<int> graph[SIZE];
int N, M, idx;

int uf_find(int x) {
    return uf_kruskal[x] == -1 ? x : uf_kruskal[x] = uf_find(uf_kruskal[x]);
}

void makeTable() { // Sparse Table 생성
    for(int i = 1; i < 19; i++) {
        for(int j = 1; j < SIZE; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

void travel(int idx) { // Sparse Table 생성하기 위해 Parent 정보와 Depth 정보 저장
    visited[idx] = 1;
    for(int next: graph[idx]) {
        if(visited[next]) continue;
        depth[next] = depth[idx] + 1;
        parent[0][next] = idx;
        travel(next);
    }
}

void findAnswer(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];

    for(int i = 0; diff; i++) {
        if(diff & 1) x = parent[i][x];
        diff >>= 1;
    }

    if(x != y) {
        for(int i = 18; i >= 0; i--) {
            if(parent[i][x] != parent[i][y]) {
                x = parent[i][x];
                y = parent[i][y];
            }  
        }
        x = parent[0][x];
    }

    cout << dist[x] << ' ' << count[x] << '\n';
}


void solve() {
    memset(depth, -1, sizeof(depth));
    for(int i = N + M; i > 0; i--) {
        if(!visited[i]) { // 방문하지 않은 점에 대해 방문
            depth[i] = 0;
            travel(i);
        }
    }
    makeTable();
    int Q; cin >> Q;
    for(int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        if(uf_find(x) != uf_find(y)) cout << "-1" << '\n';
        else findAnswer(x, y);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    idx = N + 1;
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    for(int i = 0; i < M; i++) {
        int x, y, len; cin >> x >> y >> len;
        pq.push({len, {x, y}});
    }

    memset(uf_kruskal, -1, sizeof(uf_kruskal));
    for(int i = 1; i <= N; i++) count[i] = 1;

    while(!pq.empty()) {
        pp tmp = pq.top(); pq.pop();
        int x = uf_find(tmp.second.first), y = uf_find(tmp.second.second);
        if(x == y) continue;
        dist[idx] = tmp.first;
        count[idx] = count[x] + count[y];
        graph[idx].push_back(x);
        graph[idx].push_back(y);
        uf_kruskal[x] = idx;
        uf_kruskal[y] = idx;
        idx++;
    }

    solve();
}