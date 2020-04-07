/*
Problem: 최대 유량 (6086)
Tier: Platinum 4
Detail: 

농사꾼 존은 소들이 충분한 물을 마시길 원했다. 그래서 농장에서 우물에서 외양간을 잇는 N개의 배수관의 지도를 만들기로 했다.
존은 아주 다양한 크기의 배수관들이 완전히 우연한 방법으로 연결돼있음을 알았다. 존은 파이프를 통과하는 유량을 계산하고 싶다.

두개의 배수관이 한줄로 연결 돼 있을 때 두 관의 유량 중 최솟값으로 흐르게 된다. 예를 들어 용량이 5인 파이프가 용량이 3인 파이프와 연결되면 한개의 용량 3짜리 파이프가 된다.
  +---5---+---3---+    ->    +---3---+
게다가, 병렬로 연결돼 있는 배수관들은 각 용량의 합만큼의 물을 보낼 수 있다.
    +---5---+
 ---+       +---    ->    +---8---+
    +---3---+
마지막으로, 어떤 것에도 연결돼 있지 않은 파이프는 물을 흐르게 하지 못하므로 제거된다.
    +---5---+
 ---+               ->    +---3---+
    +---3---+--
이로 인해 복잡하게 연결된 모든 배수관들은 한개의 최대 유량을 갖는 배수관으로 만들어진다. 주어진 파이프들의 맵으로부터 우물(A)와 외양간(Z) 사이의 유량을 결정하라.
각 노드의 이름은 알파벳으로 지어져 있다.
                 +-----------6-----------+
        A+---3---+B                      +Z
                 +---3---+---5---+---4---+
                         C       D
파이프 BC와 CD는 합쳐질 수 있다.
                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----3-----+-----4-----+
                             D
그러면 BD와 DZ 역시 합쳐질 수 있다.
                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----------3-----------+
병렬 연결된 BZ 역시 합쳐진다.
                 B
        A+---3---+---9---+Z
그러면 AB와 BZ 역시 합쳐질 수 있고 용량 3인 배수관 하나가 만들어진다.
        A+---3---+Z
한 파이프들의 집합을 읽고. 두개의 끝점을 가진 파이프로 만들어놓은 뒤 A부터 Z까지 흐르는 최대 유량을 계산하라. 모든 파이프들은 위의 규칙을 적용시켜 줄일 수 있다.
i번째 파이프는 두개의 다른 노드 ai와 bi와 연결돼 있고 Fi (1 ≤ Fi ≤ 1,000)만큼의 유량을 갖는다. 알파벳은 같지만, 대소문자가 다르면 다른 문자이다. 파이프는 양방향으로 흐를 수 있다.
Comment: 아주 평범한 네트워크 플로우 문제.
코드 짜면서 고생 좀 한듯 ㅋㅋ;;;
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 55;
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

inline int CtoI(char c) {
	if( c <= 'Z') return c - 'A';
	return c - 'a' +26;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<Edge*> adj[MAX];
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		char u, v;
		int w;
		cin >> u >> v >> w;
		u = CtoI(u), v = CtoI(v);
		Edge *e1 = new Edge(v, w), *e2 = new Edge(u, w);
		e1->dual = e2; e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	
	int total = 0, S = CtoI('A'), E = CtoI('Z');
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