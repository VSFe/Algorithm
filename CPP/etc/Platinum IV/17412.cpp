/*
Problem: 도시 왕복하기 1 (17412)
Tier: Platinum 4
Comment: 간단한 네트워크 플로우 문제.
*/
#include <bits/stdc++.h>
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

vector<edge*> graph[401];
int N, P;
int INF = 1e9;

int doBFS() {
    int S = 1, E = 2;
    int result = 0;

    while(true) {
        queue<int> q;
        vector<int> prev(401, -1);
        vector<edge*> path(401);

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

    cin >> N >> P;

    for (int i = 0; i < P; i++) {
       int x, y;
       cin >> x >> y;

       edge* e1 = new edge(y, 1); 
       edge* e2 = new edge(x, 0);

       e1->reverse = e2;
       e2->reverse = e1;

       graph[x].push_back(e1);
       graph[y].push_back(e2);
    }

    cout << doBFS();
}