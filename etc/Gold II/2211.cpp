/*
Problem: 네트워크 복구 (2211)
Tier: Gold 2
Detail: N(1 ≤ N ≤ 1,000)개의 컴퓨터로 구성된 네트워크가 있다. 이들 중 몇 개의 컴퓨터들은 서로 네트워크 연결이 되어 있어 서로 다른 두 컴퓨터 간 통신이 가능하도록 되어 있다.
통신을 할 때에는 서로 직접 연결되어 있는 회선을 이용할 수도 있으며, 회선과 다른 컴퓨터를 거쳐서 통신을 할 수도 있다.
각 컴퓨터들과 회선은 그 성능이 차이가 날 수 있다. 따라서 각각의 직접 연결되어 있는 회선을 이용해서 통신을 하는데 걸리는 시간이 서로 다를 수 있다.
심지어는 직접 연결되어 있는 회선이 오히려 더 느려서, 다른 컴퓨터를 통해서 통신을 하는 것이 더 유리할 수도 있다.
직접 연결되어 있는 회선을 사용할 경우에는 그 회선을 이용해서 통신을 하는 데 드는 시간만큼이 들게 된다.
여러 개의 회선을 거치는 경우에는 각 회선을 이용해서 통신을 하는 데 드는 시간의 합만큼의 시간이 걸리게 된다.
어느 날, 해커가 네트워크에 침입하였다. 네트워크의 관리자는 우선 모든 회선과 컴퓨터를 차단한 후, 해커의 공격을 막을 수 있었다.
관리자는 컴퓨터에 보안 시스템을 설치하려 하였는데, 버전 문제로 보안 시스템을 한 대의 슈퍼컴퓨터에만 설치할 수 있었다.
한 컴퓨터가 공격을 받게 되면, 네트워크를 통해 슈퍼컴퓨터에 이 사실이 전달이 되고, 그러면 슈퍼컴퓨터에서는 네트워크를 이용해서 보안 패킷을 전송하는 방식을 사용하기로 하였다.
준비를 마친 뒤, 관리자는 다시 네트워크를 복구하기로 하였다. 이때, 다음의 조건들이 만족되어야 한다.

    해커가 다시 공격을 할 우려가 있기 때문에, 최소 개수의 회선만을 복구해야 한다. 물론, 그렇다면 아무 회선도 복구하지 않으면 되겠지만, 이럴 경우 네트워크의 사용에 지장이 생기게 된다.
    따라서 네트워크를 복구한 후에 서로 다른 두 컴퓨터 간에 통신이 가능하도록 복구해야 한다.

    네트워크를 복구해서 통신이 가능하도록 만드는 것도 중요하지만, 해커에게 공격을 받았을 때 보안 패킷을 전송하는 데 걸리는 시간도 중요한 문제가 된다.
    따라서 슈퍼컴퓨터가 다른 컴퓨터들과 통신하는데 걸리는 최소 시간이, 원래의 네트워크에서 통신하는데 걸리는 최소 시간보다 커져서는 안 된다.
원래의 네트워크에 대한 정보가 주어졌을 때, 위의 조건을 만족하면서 네트워크를 복구하는 방법을 알아내는 프로그램을 작성하시오.
Comment: 국어 문제. MST 같지만 결과적으로는 다익스트라다.
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1000000;

struct edge {
    int from, to, dist;
    edge() {}
    edge(int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}
};

struct compare {
    bool operator() (const edge &a, const edge &b) {
        return a.dist > b.dist;
    }    
};

int N, K, distAndPrev[1001][2];
vector<edge> graph[1001];

void solve() {
    priority_queue<edge, vector<edge>, compare> pq;
    pq.push({1, 1, 0});
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        for(edge next : graph[e.to]) {
            if(distAndPrev[next.to][0] > distAndPrev[next.from][0] + next.dist) {
                distAndPrev[next.to][0] = distAndPrev[next.from][0] + next.dist;
                distAndPrev[next.to][1] = next.from;
                pq.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
    }
    for(int i = 2; i < 1001; i++) distAndPrev[i][0] = INF;
    solve();
    cout << N - 1 << '\n';
    for(int i = 2; i <= N; i++) cout << i << ' ' << distAndPrev[i][1] << '\n';
}