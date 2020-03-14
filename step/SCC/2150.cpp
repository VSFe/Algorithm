/*
Problem: Strongly Connected Component (2150)
Tier: Platinum 5
Detail:  방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오. 방향 그래프의 SCC는 우선 정점의 최대 부분집합이며,
그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.
Comment: 배운걸 이렇게 써먹네
*/
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int V, E;
vector<vector<int>> g;
vector<int> visited;
vector<int> dfs_low;
vector<int> dfs_num;
stack<int> st;
map<int, vector<int>> scc;
int cnt = 0;

int dfs(int v) {
    visited[v] = EXPLORED;
    st.push(v);
    dfs_low[v] = ++cnt;
    dfs_num[v] = cnt;
    int size = g[v].size();
    for(int i = 0; i < size; i++) {
        int tmp = g[v][i];
        switch (visited[tmp])
        {
        case UNVISITED:
            dfs_low[v] = min(dfs_low[v], dfs(tmp));
            break;

        case VISITED:
            break;

        case EXPLORED:
        dfs_low[v] = min(dfs_low[v], dfs_num[tmp]);
            break;
        }
    }
    if(dfs_low[v] == dfs_num[v]) {
        vector<int> vec;
        while(st.top() != v) {
            int t = st.top();
            st.pop();
            vec.push_back(t);
        }
        st.pop();
        vec.push_back(v);
        visited[v] = VISITED;
        sort(vec.begin(), vec.end());
        scc.insert(make_pair(vec[0], vec));
    }
    return dfs_low[v];
}

int main() {
    scanf("%d %d", &V, &E);
    g.reserve(V);
    visited = vector<int>(V, 0);
    dfs_low = vector<int>(V, 0);
    dfs_num = vector<int>(V, 0);
    for(int i = 0; i < E; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        g[tmp1-1].push_back(tmp2-1);
    }
    for(int i = 0; i < V; i++) {
        if(visited[i] == UNVISITED) dfs(i);
    }
    printf("%d\n", int(scc.size()));
    for(map<int, vector<int>>::const_iterator i = scc.begin(); i != scc.end(); i++) {
        int size = i->second.size(); 
        for(int j = 0; j < size; j++) {
            printf("%d ", i->second[j]+1);
        }
        printf("-1\n");
    }
    return 0;
}