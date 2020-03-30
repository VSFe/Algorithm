/*
Problem: 트리와 쿼리 (15681)
Tier: Gold 5
Detail: 간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
    정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
Comment: 방문 여부로 부모 자식을 구분할 수도 있겠네... 우선은 이걸로
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> tree;

int dfs(int x, int cnt) {
    visited[x] = 1;
    int result = 1;
    for(int i = 0; i < tree[x].size(); i++) {
        if(visited[tree[x][i]]) continue;
        result += dfs(tree[x][i], cnt);
    }
    visited[x] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, R, Q;
    cin >> N >> R >> Q;
    visited.reserve(N+1);
    tree.reserve(N+1);
    for(int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(R, 1);
    for(int i = 0; i < Q; i++) {
        int num; cin >> num;
        cout << visited[num] << '\n';
    }
    return 0;
}