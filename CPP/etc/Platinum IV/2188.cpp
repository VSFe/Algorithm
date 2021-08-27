/*
Problem: 축사배정 (2188)
Tier: Platinum 4
Comment: 네트워크 플로우 문제. (이분 매칭으로도 해결할 수 있음.)
기본적인 문제라 자세한 설명은 스킵.
*/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, c, f;
    edge *reverse;
    edge(int to1, int c1): to(to1), c(c1), f(0), reverse(nullptr) {}

    int spare() {
        return c - f;
    }

    void add_flow(int f1) {
        f += 1;
        reverse->f -= f1;
    }
};

const int INF = 1e9;
int N, M;
vector<edge*> graph[201];

int doBFS() {
    int result = 0;
    int S = 0, E = N + M + 1;

    while (true) {
        vector<int> prev(2 + N + M, -1);
        vector<edge*> path(2 + N + M);

        queue<int> q;
        q.push(S);

        while (q.size() && prev[E] == -1) {
            int node = q.front(); q.pop();

            for (auto next : graph[node]) {
                int idx = next->to;

                if (next->spare() > 0 && prev[idx] == -1) {
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

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int end; cin >> end;
            end = N + end;

            edge *e1 = new edge(end, 1);
            edge *e2 = new edge(i + 1, 0);

            e1->reverse = e2;
            e2->reverse = e1;

            graph[i + 1].push_back(e1);
            graph[end].push_back(e2);
        }
    }

    for (int i = 1; i <= N; i++) {
        edge *e1 = new edge(i, 1);
        edge *e2 = new edge(0, 0);

        e1->reverse = e2;
        e2->reverse = e1;

        graph[0].push_back(e1);
        graph[i].push_back(e2);
    }

    for (int i = N + 1; i <= N + M; i++) {
        edge *e1 = new edge(i, 0);
        edge *e2 = new edge(N + M + 1, 1);

        e1->reverse = e2;
        e2->reverse = e1;

        graph[N + M + 1].push_back(e1);
        graph[i].push_back(e2);
    }

    cout << doBFS();
}
