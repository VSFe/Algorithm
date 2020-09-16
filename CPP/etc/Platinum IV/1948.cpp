/*
Problem: 여행 계획 세우기
Tier: Platinum 4
Detail: 평소 일로 바쁘던 태희는 휴가를 통해 여행을 다녀오기로 하였다. 우선 태희는 사전 조사를 통해서 여행하려는 도시를 N(1≤N≤10,000)개 선택하였다.
태희는 비행기를 이용하면 충분히 여행할 수 있을거라 생각했지만, 짐을 꾸리던 중 비행기가 모든 도시들 사이를 다니는 것은 아님을 알게 되었다.
태희는 다시 비행로에 대해 조사를 하였고, 총 M(1≤M≤100,000)개의 비행로가 존재함을 알게 되었다. 각각의 비행로는 한 방향으로의 서비스만을 제공한다.
태희는 S(1≤S≤N)번 도시에서 시작해서 T(1≤T≤N)번 도시에서 여행을 끝내기로 하였다. 그리고 태희는 도시와 항공로에 대한 정보를 바탕으로 여행 계획을 세우기로 하였다.
도시와 비행로에 대한 정보가 주어졌을 때, S번 도시에서 T번 도시로 여행을 할 때 최대로 방문할 수 있는 도시의 개수를 구하는 프로그램을 작성하시오.
각각의 도시는 여행 중에 몇 번이든 방문할 수 있으며, 같은 항공로를 여러 번 이용할 수도 있다. 물론 같은 도시를 여러 번 방문하는 경우는 한 번만 생각하기로 한다.
Comment: SCC를 만듦. 그렇게 되면 DAG가 생기는데, 위상정렬을 돌리되, 중간에 나올수도 있으므로 SCC 컴포넌트의 가중치를 임의로 조정.
조정한 값에 맞춰서 DP 진행하면 완료.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, S, T, cnt = 0, scc_cnt = 0;
int dfs_num[10001], dfs_low[10001], scc_num[10001], scc_size[10001], scc_in[10001], ans[10001];
vector<int> graph[10001], scc_graph[10001];
stack<int> st;
queue<int> q;

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
            scc_size[scc_cnt]++;
            st.pop();
            if(t == idx) break;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> S >> T;
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
        for(int next : graph[i]) {
            if(scc_num[i] != scc_num[next]) {
                scc_graph[scc_num[i]].push_back(scc_num[next]);
                scc_in[scc_num[next]]++;
            }
        }
    }
    ans[scc_num[S]] = scc_size[scc_num[S]];
    for(int i = 1; i <= scc_cnt; i++) {
        if(!scc_in[i]) {
            q.push(i);
        }
    }
    if(scc_num[S] == scc_num[T]) {
        cout << scc_size[scc_num[S]];
        return 0;
    }
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(int next : scc_graph[t]) {
            if(ans[t]) ans[next] = max(ans[next], ans[t] + scc_size[next]);
            if(!(--scc_in[next])) q.push(next);
        }
    }
    if(!ans[scc_num[T]]) cout << 0;
    else cout << ans[scc_num[T]];
}