#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 41;
vector<pair<int, int>> graph[SIZE];
int N, M;
int parent[17][SIZE];
int dist[SIZE]; 
int depth[SIZE];

void Traversal(int node) {
    for(pair<int, int> p: graph[node]) {
        if(depth[p.first] == -1) {
            parent[0][p.first] = node;
            dist[p.first] = dist[node] + p.second;
            depth[p.first] = depth[node] + 1;
            Traversal(p.first);
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 17; i++)
        for(int j = 1; j < SIZE; j++)
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int solve(int x, int y) {
    int X = x, Y = y;
    if(depth[X] < depth[Y]) swap(X, Y);
    int diff = depth[X] - depth[Y];

    for(int i = 0; diff; i++) {
        if(diff & 1) X = parent[i][X];
        diff >>= 1;
    }

    if(X != Y) {
        for(int i = 16; i >= 0; i--) {
            if(parent[i][X] != parent[i][Y]) {
                X = parent[i][X];
                Y = parent[i][Y];
            }
        }

        X = parent[0][X];
    }

    return dist[x] + dist[y] - 2 * dist[X];
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
        int x, y; cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
}