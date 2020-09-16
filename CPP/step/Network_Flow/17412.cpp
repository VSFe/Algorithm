/*
Problem: 도시 왕복하기 1 (17412)
Tier: Platinum 5
Detail: N개의 도시가 P개의 단방향 길로 연결되어 있다. 이석원은 1번 도시와 2번 도시 사이를 가며 워해머를 한다.
성실한 이석원은 1번에서 2번으로 가는 서로 다른 경로를 최대한 많이 찾으려고 하는데, 이때 한 경로에 포함된 길이 다른 경로에 포함되면 안된다.
입력에는 1번 도시와 2번 도시를 연결하는 길은 없다. 도시의 번호는 1번부터 N번까지이다.
Comment: 우선순위 큐를 한개만 쓸 필요는 없잖아?
최대0와 최소 사이에는 가운데라는걸 생각했어야 했다...
pq_min: 최소힙. 루트 값이 최솟값을 담고 있다. → 최대힙 보다 큰 값을 가져야겠다.
pq_max: 최대힙. 루트 값이 최댓값을 담고 있다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 30000;
const int INF = 1000000;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int to, int c) : to(to), c(c), f(0), dual(nullptr) {}
	int spare() { return c - f; }
	void addFlow(int f_num) {
		f += f_num;
		dual->f -= f_num;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, P; cin >> N >> P;
	vector<Edge*> adj[N + 1];
	for(int i = 0; i < P; i++) {
		int u, v;
		cin >> u >> v;
		Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
		e1->dual = e2; e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
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
		
		int flow = INF;
		for(int i = E; i != S; i = prev[i]) flow = min(flow, path[i]->spare());
		for(int i = E; i != S; i = prev[i]) path[i]->addFlow(flow);
		total += flow;
	}
	cout << total;
	return 0;
}