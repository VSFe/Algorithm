/*
Problem: Strongly Connected Component (2150)
Tier: Platinum 5
Detail:  방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오. 방향 그래프의 SCC는 우선 정점의 최대 부분집합이며,
그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.
Comment: 배운걸 이렇게 써먹네
이미 SCC를 형성한 구간에 간섭 안하게 하는게 중요했던 문제...
이걸 빼먹어서 이렇게 고생을 했다고?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
vector<vector<int>> SCC;
int dfs_num[10001], dfs_low[10001], cnt = 1;
bool finished[10001];
stack<int> st;

void dfs(int idx, int prev) {
    dfs_num[idx] = dfs_low[idx] = cnt++;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) dfs(next, idx);
        if(!finished[next]) dfs_low[idx] = min(dfs_low[idx], dfs_low[next]);
    }
    if(dfs_num[idx] == dfs_low[idx]) {
        vector<int> vec;
        while(1) {
            int t = st.top();
            finished[t] = 1;
            vec.push_back(t);
            st.pop();
            if(t == idx) break;
        } 
        sort(vec.begin(), vec.end());
        SCC.push_back(vec);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int V, E; cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i < V; i++) {
        if(!dfs_num[i]) dfs(i, 0);
    }
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << '\n';
    for(int i = 0; i < SCC.size(); i++) {
        for(int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << ' ';
        cout << -1 << '\n';
    }
    return 0;
}