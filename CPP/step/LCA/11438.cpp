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
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 18;

int N, M;
int parent[100000][SIZE];
int depth[100000];
vector<int> graph[100000];

void dfs(int x) {
    for(int next : graph[x]) {
        if(depth[next] == -1) {
            parent[next][0] = x;
            depth[next] = depth[x] + 1;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(parent, -1, sizeof(parent));
    fill(depth, depth + N, -1);
    depth[0] = 0;
    dfs(0);

    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = 0; j < N; j++) {
            if(parent[j][i] != -1)
                parent[j][i + 1] = parent[parent[j][i]][i];
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        if(depth[x] < depth[y]) swap(x, y);
        int diff = depth[x] - depth[y];

        for(int i = 0; diff; i++) {
            if(diff % 2) x = parent[x][i];
            diff /= 2;
        }

        if(x != y) {
            for(int i = SIZE - 1; i >= 0; i--) {
                if(parent[x][i] != -1 && parent[x][i] != parent[y][i]) {
                    x = parent[x][i];
                    y = parent[y][i];
                }
            }
            x = parent[x][0];
        }

        cout << x + 1 << '\n';
    }

}