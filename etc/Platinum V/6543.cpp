/*
Problem: 그래프의 싱크 (6543)
Tier: Platinum 5
Detail: 방향 그래프 G = (V, E)가 주여져 있다. 임의의 노드 u, v ∈ V에 대해서 u에서 v로 E에 포함된 간선만을 이용해 갈 수 있는 경로가 있으면 u→v로 표현한다.
만약 어떤 노드 v ∈ V가 자신으로부터 도달할 수 있는 모든 노드로부터 돌아오는 경로가 있다면, 즉 다음 조건을 만족한다면 노드 v ∈ V를 싱크라고 부른다.
    조건: ∀w ∈ V, (v→w) ⇒ (w→v)
또한, 그래프 G의 싱크를 모아놓은 집합을 bottom(G)로 표현한다.
    bottom(G) = {v ∈ V: ∀w ∈ V, (v→w) ⇒ (w→v)}
주어진 그래프 G=(V, E)의 bottom(G)를 구하시오.
Comment: 각각의 노드가 SCC 내부에만 존재하고, 다른 SCC로 나가지 않는 경우에 한해 해당 문제가 해결됨.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, cnt = 0, scc_cnt = 0;
int dfs_num[5001], scc_num[5001], ans[5001];
vector<int> graph[5001], scc[5001];
stack<int> st;

void find_scc(int idx) {
    int dfn = dfs_num[idx] = ++cnt;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) find_scc(next);
        if(!scc_num[next]) dfs_num[idx] = min(dfs_num[idx], dfs_num[next]);
    }
    if(dfs_num[idx] == dfn) {
        scc_cnt++;
        while(1) {
            int t = st.top();
            scc_num[t] = scc_cnt;
            scc[scc_cnt].push_back(t);
            st.pop();
            if(t == idx) break;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true) {
    cin >> N;
    if(!N) return 0;
    cin >> M;
    for(int i = 0; i < 5001; i++) {
        graph[i].clear();
        scc[i].clear();
    }
    cnt = 0, scc_cnt = 0;
    fill(dfs_num, dfs_num + 5001, 0);
    fill(scc_num, scc_num + 5001, 0);
    fill(ans, ans+5001, 0);
    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        if(!dfs_num[i]) find_scc(i);
    }
    for(int i = 1; i <= N; i++) {
        bool is_sink = true;
        for(int next : graph[i]) {
            if(scc_num[next] != scc_num[i]) {
                for(int j = 0; j < scc[scc_num[i]].size(); j++) ans[scc[scc_num[i]][j]] = 1;
                break;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(!ans[i]) cout << i << ' ';
    }
    cout << '\n';
    }
}