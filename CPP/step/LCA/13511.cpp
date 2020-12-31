#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 100001;

int N, M;
int depth[SIZE];
long long dist[SIZE];
int parent[17][SIZE];
vector<pair<int, int>> graph[SIZE];

void Traversal(int node) {
    for(pair<int, int> p : graph[node]) {
        if(depth[p.first] == -1) {
            depth[p.first] = depth[node] + 1;
            dist[p.first] = p.second + dist[node];
            parent[0][p.first] = node;
            Traversal(p.first);
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 17; i++) {
        for(int j = 1; j < SIZE; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

int GetLCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    for(int i = 0; diff; i++) {
        if(diff & 1) a = parent[i][a];
        diff >>= 1;
    }

    if(a != b) {
        for(int i = 15; i >= 0; i--) {
            if(parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        a = parent[0][a];
    }

    return a;
}

long long solve(int x, int y) {
    int lca = GetLCA(x, y);
    return dist[x] + dist[y] - 2 * dist[lca];
}

int solve(int x, int y, int number) {
    int lca = GetLCA(x, y);
    int left = depth[x] - depth[lca];
    number--;
    if(left >= number) {
        for(int i = 0; number; i++) {
            if(number & 1) x = parent[i][x];
            number >>= 1;
        }
        return x;
    } else {
        number = depth[x] + depth[y] - 2 * depth[lca] - number;
        for(int i = 0; number; i++) {
            if(number & 1) y = parent[i][y];
            number >>= 1;
        }
        return y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y, d; cin >> x >> y >> d;
        graph[x].push_back({y, d});
        graph[y].push_back({x, d});
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    Traversal(1);
    MakeTable();
    cin >> M;

    for(int i = 0; i < M; i++) {
        int Q; cin >> Q;
        if(Q == 1) {
            int x, y;
            cin >> x >> y;
            cout << solve(x, y) << '\n';
        } else {
            int x, y, num;
            cin >> x >> y >> num;
            cout << solve(x, y, num) << '\n';
        }
    }
}