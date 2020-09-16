/*
Problem: Strahler 순서
Tier: Gold 3
Detail: 지질학에서 하천계는 유향그래프로 나타낼 수 있다. 강은 간선으로 나타내며, 물이 흐르는 방향이 간선의 방향이 된다. 노드는 호수나 샘처럼 강이 시작하는 곳, 강이 합쳐지거나 나누어지는 곳, 바다와 만나는 곳이다.
네모 안의 숫자는 순서를 나타내고, 동그라미 안의 숫자는 노드 번호를 나타낸다. 하천계의 Strahler 순서는 다음과 같이 구할 수 있다.
    강의 근원인 노드의 순서는 1이다.
    나머지 노드는 그 노드로 들어오는 강의 순서 중 가장 큰 값을 i라고 했을 때, 들어오는 모든 강 중에서 Strahler 순서가 i인 강이 1개이면 순서는 i, 2개 이상이면 순서는 i+1이다.
하천계의 순서는 바다와 만나는 노드의 순서와 같다. 바다와 만나는 노드는 항상 1개이다. 하천계의 정보가 주어졌을 때, Strahler 순서를 구하는 프로그램을 작성하시오.
실제 강 중에서 Strahler 순서가 가장 큰 강은 아마존 강(12)이며, 미국에서 가장 큰 값을 갖는 강은 미시시피 강(10)이다. 노드 M은 항상 바다와 만나는 노드이다.
Comment: 진짜 그냥 위상정렬 (2).
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int _, N, M, order[1001], in[1001], max_cnt[1001];
vector<int> vec[1001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
    fill(order, order + 1001, 0);
    fill(in, in + 1001, 0);
    for(int i = 0; i < 1001; i++) vec[i].clear();
    cin >> _ >> N >> M;
    int u, v, MAX = 1;
    for(int i = 1; i <= M; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        in[v]++;
    }
    for(int i = 1; i <= N; i++) {
        if(!in[i]) {
            q.push(i);
            order[i] = 1;
        }
    }
    while(!q.empty()) {
        int tmp = q.front(); q.pop();
        for(int next : vec[tmp]) {
            if(order[next] < order[tmp]) {
                order[next] = order[tmp];
                max_cnt[next] = 1;
            }
            else if(order[next] == order[tmp]) max_cnt[next]++;
            if(--in[next] == 0) {
                if(max_cnt[next] > 1) order[next]++;
                q.push(next);
            }
        }
    }
    cout << _ << ' ' << order[N] << '\n';
}}