/*
Problem: 도시 왕복하기 1 (17412)
Tier: Platinum 4
Detail: 농부 존은 소 축사를 완성하였다. 축사 환경을 쾌적하게 유지하기 위해서, 존은 축사를 M개의 칸으로 구분하고, 한 칸에는 최대 한 마리의 소만 들어가게 계획했다.
첫 주에는 소를 임의 배정해서 축사를 운영했으나, 곧 문제가 발생하게 되었다. 바로 소가 자신이 희망하는 몇 개의 축사 외에는 들어가기를 거부하는 것이다.
농부 존을 도와 최대한 많은 수의 소가 축사에 들어갈 수 있도록 하는 프로그램을 작성하시오. 축사의 번호는 1부터 M까지 매겨져 있다.
Comment: 사실상 플로우 문제와 매우 유사. 각 축사의 용량을 1로 하면 됨.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 555;

struct Edge {
    int to, c, f;
    Edge *dual;
    Edge() : Edge(-1, 0) {}
    Edge(int to, int c) : to(to), c(c), f(0), dual(nullptr) {}
    int spare() { return c - f; }
    void addFlow(int num) {
        f += num;
        dual->f -= num;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin >> N >> M;
    vector<Edge*> adj[MAX];
    for(int i = 0; i < N; i++) {
        int u = i * 2, v = u + 1;
        Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        Edge *e1 = new Edge(b * 2, 1), *e2 = new Edge(a*2, 1);
        e1->dual = e2;
        e2->dual = e1;
        adj[a * 2 + 1].push_back(e1);
        adj[b * 2 + 1].push_back(e2);
        e1 = new Edge(b * 2, 1), e2 = new Edge(a*2, 1);
        e1->dual = e2;
        e2->dual = e1;
        adj[b * 2 + 1].push_back(e1);
        adj[a * 2].push_back(e2);
    }

    int total = 0, S = 1, E = 2;
	while(1) {
		int prev[MAX];
		Edge *path[MAX] = {0};
		fill(prev, prev + MAX, -1);
		queue<int> q;
		q.push(S);
		while(!q.empty() && prev[E] == -1) {
			int curr = q.front(); q.pop();
			for(Edge *e : adj[curr]) {
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
		
		int flow = MAX;
		for(int i = E; i != S; i = prev[i]) flow = min(flow, path[i]->spare());
		for(int i = E; i != S; i = prev[i]) path[i]->addFlow(flow);
		total += flow;
	}
	cout << total;
	return 0;
}
