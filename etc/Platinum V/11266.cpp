/*
Problem: 단절점 (11266)
Tier: Platinum 5
Detail: 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
Comment: 대체 순간이동을 왜 해??
암튼 이게 뒤로 가는 것도 존재하기 때문에... 넉넉하게 거리의 동생의 거리의 두배 정도 되는 크기로 배열을 만들자.
일차원 그래프를 BFS로 순회한다고 생각하면 될 것 같음.
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
vector<int> arti;
int cnt = 0;

int dfs(int v) {
    visited[v] = EXPLORED;
    st.push(v);
    dfs_low[v] = ++cnt;
    dfs_num[v] = cnt;
    int size = g[v].size();
    bool is_articulation = false;
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
        if(dfs_low[tmp] >= dfs_num[v]) is_articulation = true; 
    }
    if(is_articulation) arti.push_back(v);
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
    int size = arti.size();
    printf("%d\n", size);
    sort(arti.begin(), arti.end());
    for(int i = 0; i < size; i++) printf("%d ", arti[i] + 1);
    return 0;
}