/*
Problem: 트리 (1068)
Tier: Silver 1
Detail: 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
트리가 주어졌을 때, 노드 중 하나를 제거할 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.
Comment: 특정 노드가 삭제되면, 자식들도 더 이상 루트가 아니라는 점을 간과하면 안되는 문제.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int tree[51], N, M, cnt = 0, root;
vector<int> graph[51];

void dfs(int n) {
    bool is_travel = false;
    for(auto next : graph[n]) {
        if(next == M) continue;
        is_travel = true;
        dfs(next);
    }
    if(!is_travel) cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(a == -1) {
            root = i;
            continue;
        }
        graph[a].push_back(i);
    }
    cin >> M;
    if(M != root) dfs(root);
    cout << cnt;
}

