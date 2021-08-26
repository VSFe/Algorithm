#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct edge {
    int to, c, f; // 각각 목적지 위치, 용량, 유량
    edge *reverse; // 역방향 간선
    edge() : edge(-1, 0) {}
    edge(int to1, int c1): to(to1), c(c1), f(0), reverse(nullptr) {}

    int spare() { // 흘려보낼 수 있는 최대 양 확인
        return c - f;
    }

    void add_flow(int f1) { // 역방향 간선에 음수로 깜.
        f += f1;
        reverse->f -= f1;
    }
};

const int INF = 1e9;
int N;
vector<edge*> graph[61];

int get_idx (char c) {
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int doBFS() {
    int result = 0;
    int S = get_idx('A'), E = get_idx('Z');

    while (true) { // 흘릴 수 있을 때 까지 계속 흘릴 거임
        int prev[61]; // 이전에 어떤 정점을 방문했는가?
        edge* path[61]; // 그 정점을 방문하기 위해 어떤 간선을 사용했는가?

        memset(prev, -1, sizeof(prev)); // 초기화
        queue<int> q;
        q.push(S);

        while (q.size() && prev[E] == -1) {
            int node = q.front(); q.pop();

            for (auto next : graph[node]) {
                int idx = next->to;

                if (next->spare() > 0 && prev[idx] == -1) { // 흘릴 수 있다면
                    q.push(idx);
                    prev[idx] = node;
                    path[idx] = next;
                    if (idx == E) break;
                }
            }
        }

        if (prev[E] == -1) break;

        int flow = INF;
        for (int i = E; i != S; i = prev[i])
            flow = min(flow, path[i]->spare());
        for (int i = E; i != S; i = prev[i])
            path[i]->add_flow(flow);
        result += flow;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char u, v;
        int w;

        cin >> u >> v >> w;
        int x = get_idx(u), y = get_idx(v);

        edge *x1 = new edge(y, w); 
        edge *x2 = new edge(x, w); // 역방향 또한 용량은 동일해야 함.

        x1->reverse = x2;
        x2->reverse = x1;

        graph[x].push_back(x1);
        graph[y].push_back(x2);
    }

    cout << doBFS();
}