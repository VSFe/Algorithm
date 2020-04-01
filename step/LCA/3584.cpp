/*
Problem: 가장 가까운 공통 조상 (3584)
Tier: Gold 4
Detail: 루트가 있는 트리(rooted tree)가 주어지고, 그 트리 상의 두 정점이 주어질 때 그들의 가장 가까운 공통 조상(Nearest Common Anscestor)은 다음과 같이 정의됩니다.
    두 노드의 가장 가까운 공통 조상은, 두 노드를 모두 자손으로 가지면서 깊이가 가장 깊은(즉 두 노드에 가장 가까운) 노드를 말합니다.
예를 들어  15와 11를 모두 자손으로 갖는 노드는 4와 8이 있지만, 그 중 깊이가 가장 깊은(15와 11에 가장 가까운) 노드는 4 이므로 가장 가까운 공통 조상은 4가 됩니다.
루트가 있는 트리가 주어지고, 두 노드가 주어질 때 그 두 노드의 가장 가까운 공통 조상을 찾는 프로그램을 작성하세요
Comment: 효율적인 방법이 있긴 하지만 일단은 가볍게 일반적인 알고리즘으로 해보자.
트리를 반대로 집어넣어서 순회를 때리고, 다른 노드로 순회하면서 이전에 방문했던 노드에 도착하면 바로 리턴하고 종료.
문제에서 A가 B의 부모라는 말이 나왔기 때문에 따로 트리화 시키지는 않음.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int visited[], vector<int> tree[]) {
    if(visited[x]) {
        cout << x << '\n';
        return;
    }
    visited[x] = 1;
    if(tree[x].size()) dfs(tree[x][0], visited, tree);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int N, test_x, test_y, visited[10001] = {0};
        vector<int> tree[10001];
        cin >> N;
        for(int i = 0; i < N-1; i++) {
            int x, y;
            cin >> x >> y;
            tree[y].push_back(x);
        }
        cin >> test_x >> test_y;
        dfs(test_x, visited, tree); dfs(test_y, visited, tree);
    }
    return 0;
}