/*
Problem: 트리 (4803)
Tier: Gold 4
Detail: 그래프는 정점과 간선으로 이루어져 있다. 두 정점 사이에 경로가 있다면, 두 정점은 연결되어 있다고 한다.
연결 요소는 모든 정점이 서로 연결되어 있는 정점의 부분집합이다. 그래프는 하나 또는 그 이상의 연결 요소로 이루어져 있다.
트리는 사이클이 없는 연결 요소이다. 트리에는 여러 성질이 있다. 예를 들어, 트리는 정점이 n개, 간선이 n-1개 있다. 또, 임의의 두 정점에 대해서 경로가 유일하다.
그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 작성하시오.
Comment: 그래프를 트리 구조로 바꾸고, 순회를 돌려주면 된다...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int tree[501], N, M, cnt = 0, tc = 1;
vector<int> graph[501];

bool dfs(int n) {
    bool is_tree = true;
    for(auto next : graph[n]) {
        if(tree[next]) {
            if(tree[n] != next) is_tree = false;
        }
        else {
            tree[next] = n;
            is_tree &= dfs(next);            
        }
    }
    return is_tree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cnt = 0;
        memset(tree, 0, sizeof(tree));
        for(int i = 0; i < 501; i++) graph[i].clear();
        for(int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i<= N; i++) {
            if(!tree[i]) {
                tree[i] = -1;
                if(dfs(i)) cnt++;
            }
        }
        cout << "Case " << tc << ": ";
        if(cnt == 0) cout << "No trees." << '\n';
        else if(cnt == 1) cout << "There is one tree." << '\n';
        else cout << "A forest of " << cnt << " trees." << '\n';
        tc++;
    }
}
