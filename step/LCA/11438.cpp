/*
Problem: LCA 2
Tier: Platinum 5
Detail: N(2 ≤ N ≤ 100,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.
두 노드의 쌍 M(1 ≤ M ≤ 100,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.
Comment: Sparse Table + Euler Tour on Tree
우선 맘대로 주어지기 때문에 트리화 시켜주고, 그 다음에 오일러 트리를 만들어 준 다음, 마지막으로 스파스 테이블까지 사용.
머가리 터지넼ㅋㅋㅋㅋㅋㅋㅋ
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[17][200002], euler_tour[200002], N, M;
vector<int> graph[100001], tree[100001];

void make_tree(int now, int prev) {
    for(auto next : graph[now]) {
        if(next ^ prev) {
            tree[now].push_back(next);
            make_tree(next, now);
        }
    }
}

int make_euler_tour(int now, int idx) {
    euler_tour[idx] = now;
    table[0][idx] = now;
    if(tree[idx].size()) {
        for(auto next : tree[idx]) {
            idx = make_euler_tour(next, idx + 1);
            euler_tour[idx] = now;
            table[0][idx] = now;
        }
    }
    return now + 1;
}

void make_sparse() {
    int node = N * 2 - 1; 
    for(int i = 1; i <= 16; i++) {
        for(int j = 1; j <= N; j++) {
            int x = table[i-1][j], y = table[i-1][j+1];
            table[i][j] = min(x, y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    make_tree(1, 0); make_euler_tour(1, 0); make_sparse();
    cin >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        
    }
}