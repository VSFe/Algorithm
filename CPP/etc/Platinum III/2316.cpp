/*
Problem: 도시 왕복하기 2
Tier: Platinum 3
Comment: 네트워크 플로우 모델링 문제 (정점 분할 포함)
간선 연결이 골 때리면 그냥 다 연결하면 된다가 오늘의 교훈
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, c, f;
    edge* reverse;
    edge(int to, int c): to(to), c(c), f(0), reverse(nullptr) {}

    int spare() {
        return c - f;
    }

    void add_flow(int x) {
        f += x;
        reverse->f -= x;
    }
};


int N, M;
int INF = 1e9;
const int SIZE = 1001;
vector<edge*> graph[SIZE];

int doBFS(int S, int E) {
    int result = 0;

    while(true) {
        queue<int> q;
        vector<int> prev(SIZE, -1);
        vector<edge*> path(SIZE);

        q.push(S);
        prev[S] = S;

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

    for (int i = 1; i <= N; i++) {
        int u = i, v = 400 + i;

        edge *e1 = new edge(v, 1);
        edge *e2 = new edge(u, 0);

        e1->reverse = e2;
        e2->reverse = e1;

        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        int out_x = x + 400, out_y = y + 400;

        graph[out_x].push_back(new edge(y, 1));
        graph[y].push_back(new edge(out_x, 0));
        graph[out_x].back()->reverse = graph[y].back();
        graph[y].back()->reverse = graph[out_x].back();

        graph[out_y].push_back(new edge(x, 1));
        graph[x].push_back(new edge(out_y, 0));
        graph[out_y].back()->reverse = graph[x].back();
        graph[x].back()->reverse = graph[out_y].back();
    }

    cout << doBFS(401, 2);
}