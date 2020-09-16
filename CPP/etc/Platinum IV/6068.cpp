#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 52;
const int INF = 1e9;

struct edge {
    int to, c, f;
    edge *dual;
    edge() : edge(-1, 0) {}
    edge(int _to, int _c) : to(_to), c(_c), f(0), dual(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int f1) {
        f += f1;
        dual-> f -= f1;
    }
};

inline int CtoI (char c) {
    if(c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    vector<edge*> graph[MAX_V];
    cin >> N;
    for(int i = 0; i < N; i++) {
        char u, v; int w;
        cin >> u >> v >> w;
        u = CtoI(u); v = CtoI(v);
        edge *e1 = new edge(v, w), *e2 = new edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }

    int total = 0, S = CtoI('A'), E = CtoI('Z');
    while(true) {
        int prev[MAX_V];
        edge *path[MAX_V] = {0};
        fill(prev, prev + MAX_V, -1);
        queue<int> q;
        q.push(S);
        while(!q.empty() && prev[E] == -1) {
            int curr = q.front();
            q.pop();
            for(edge *e : graph[curr]) {
                int next = e->to;
                if(e->spare() > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = curr;
                    path[next] = e;
                    if(next == E) break;
                }
            }
        }
        if(prev[E] == -1) break;

        int flow = INF;
        for(int i = E; i != S; i = prev[i]) flow = min(flow, path[i]->spare());
        for(int i = E; i != S; i = prev[i]) path[i]->addFlow(flow);
        total += flow;
    }
    cout << total;
}