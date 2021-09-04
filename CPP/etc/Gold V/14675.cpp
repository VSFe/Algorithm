#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100001;

vector<int> graph[SIZE];
vector<int> tree[SIZE];

int visited[SIZE];
int N, M;

void dfs(int node) {
    visited[node] = 1;

    for (int next : graph[node]) {
        if (!visited[next]) dfs(next);
        else tree[next].push_back(node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        if (x == 2) cout << "yes\n";
        else {
            if ((y == 1 && tree[y].size() > 1 ) || (y != 1 && tree[y].size())) cout << "yes\n";
            else cout << "no\n"; 
        }
    }
}

