#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 17;

int dist[40020];
int depth[40020];
int parent[40020][MAX];
vector<pair<int, int>> graph[40020];

void dfs(int i) {
    for(pair<int, int> node: graph[i]) {
        if(depth[node.first] == -1) {
            parent[node.first][0] = i;
            depth[node.first] = depth[i] + 1;
            dist[node.first] = dist[i] + node.second;
            dfs(node.first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N;

    for(int i = 1; i < N; i++) {
        int x, y, len; cin >> x >> y >> len;
        x--, y--;
        graph[x].push_back({y, len});
        graph[y].push_back({x, len});
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[0] = 0;
    dfs(0);

    int size = MAX - 1;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < N; j++) {
            if(parent[j][i] != 1) parent[j][i + 1] = parent[parent[j][i]][i];
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        int X = x, Y = y;

        if(depth[x] < depth[y]) swap(x, y);
        int diff = depth[x] - depth[y];

        for(int i = 0; diff; i++) {
            if(diff % 2) x = parent[x][i];
            diff /= 2;
        }

        if(x != y) {
            for(int i = MAX - 1; i >= 0; i--) {
                if(parent[x][i] != -1 && parent[x][i] != parent[y][i]) {
                    x = parent[x][i];
                    y = parent[y][i];
                }
            }
            x = parent[x][0];
        }

        int answer = dist[X] + dist[Y] - 2 * dist[x];
        cout << answer << '\n';
    }
}