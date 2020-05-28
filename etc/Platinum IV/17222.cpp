/*
Problem: 위스키 거래 (17222)
Tier: Platinum 4
Detail: 주은이와 명진이는 사적으로 위스키를 거래하는 사이이다. 주은이는 돈도 많고 위스키를 무척 좋아해서 위스키를 가능한 한 많이 사고 싶어하고, 명진이는 위스키가 넘쳐나서 위스키를 가능한 한 많이 팔고 싶다
 하지만 주은이 자신의 사회적 평판과 품위 때문에, 한 번에 너무 많은 양의 위스키를 직거래하는 것을 꺼려 한다.
 그래서 주은이는 자신의 친구를 총동원하고 명진이에게도 은밀하게 부탁하여 사설 유통망을 구축해내기로 했다. 유통망의 구조는 다음과 같다.
    주은이가 명진이에게 위스키를 주문한다.
    명진이는 가능한 한 많은 위스키를 적절하게 분배하여 명진이의 친구들에게 발송한다.
    명진이의 친구들은 자신의 연락망을 토대로 유통망 안에서 위스키를 주고받을 수 있다. 이들 중 몇몇은 주은이의 친구들과 연락할 수 있지만, 주은이와 직접 연락할 수는 없다.
    명진이의 친구들에게서 위스키를 전달받은 주은이의 친구들은 모든 위스키를 주은이에게 전달한다.
명진이는 위스키를 무한하게 보낼 수 있고, 주은이 역시 친구들로부터 받을 수 있는 위스키의 양에 제한이 없다. 하지만 명진이와 주은이의 친구들도 각자의 사회적 평판을 걱정하기 때문에 각각 한 명에게서 전달받을 수 있는 양이 정해져 있다.
 예를 들어 A가 한 번에 최대 5병의 위스키를 받을 수 있다면, A는 3명의 친구들로부터 위스키를 5병씩 전달받아서 주은이에게 총 15병을 전달할 수 있지만, 1명의 친구로부터 6병을 전달받지는 못한다.
각 친구들이 한 명에게서 최대 몇 병의 위스키를 전달받을 수 있는지, 명진이의 친구들이 누구에게 연락할 수 있는지에 대한 정보가 주어졌을 때, 주은이가 한 번에 최대 몇 병의 위스키를 받을 수 있을지를 구하여라.
Comment: 스스로 풀어낸 첫 네트워크 유량 문제.
모델링이 쉬운 문제지만, 함정이 있다는걸 잘 생각하고 풀자.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAX = 1e7;
const int MAX_V = 202;

struct edge {
    int to, c, f;
    edge *dual;
    edge() : edge(-1, 0) {}
    edge(int _to, int _c) : to(_to), c(_c), f(0), dual(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int n) {
        f += n;
    }
};

int N, M;
vector<int> capa;
vector<int> connection[101];
vector<edge*> graph[202];

void solve() {
    int size = N + M + 1;
    for(int i = N + 1; i < size; i++) {
        int tmp = capa[i];
        edge *e1 = new edge(i, tmp), *e2 = new edge(size, 0);
        e1->dual = e2;
        e2->dual = e1;
        graph[size].push_back(e1);
        graph[i].push_back(e2);
    }
    for(int i = 0; i < M; i++) {
        for(int next : connection[i]) {
            int tmp = capa[next];
            edge *e1 = new edge(next, tmp), *e2 = new edge(N + 1 + i, 0);
            e1->dual = e2;
            e2->dual = e1;
            graph[N + 1 + i].push_back(e1);
            graph[next].push_back(e2);
        }
    }
    for(int i = 0; i < N; i++) {
        edge *e1 = new edge(0, MAX), *e2 = new edge(i + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        graph[i + 1].push_back(e1);
        graph[0].push_back(e2);
    }

    int total = 0, S = N + M + 1, E = 0;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int size = N + M + 1;
    capa.reserve(size);
    for(int i = 1; i < size; i++) {
        cin >> capa[i];
    }
    for(int i = 0; i < M; i++) {
        int size; cin >> size;
        for(int j = 0; j < size; j++) {
            int tmp; cin >> tmp;
            connection[i].push_back(tmp);
        }
    }
    solve();
}