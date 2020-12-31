/*
Problem: 도로 네트워크 (3176)
Tier: Platinum IV
Detail: N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 도로 네트워크가 있다. 
모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있고, 각 도로의 길이는 입력으로 주어진다.
총 K개의 도시 쌍이 주어진다. 이때, 두 도시를 연결하는 경로 상에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구하는 프로그램을 작성하시오.
Comment: 구간 최댓값과 구간 최솟값을 담는 Sparse Table을 두개 만들어주고, LCA를 찾는 과정에서 함께 갱신함.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 100001;
int N, K;
int depth[SIZE];
int minimum[17][SIZE];
int maximum[17][SIZE];
int parent[17][SIZE];
vector<pair<int, int>> graph[SIZE];

void Traversal(int node) {
    for(pair<int, int> p: graph[node]) {
        if(depth[p.first] == -1) {
            depth[p.first] = depth[node] + 1;
            parent[0][p.first] = node;
            minimum[0][p.first] = p.second;
            maximum[0][p.first] = p.second;
            Traversal(p.first);
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 17; i++) {
        for(int j = 1; j < SIZE; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
            minimum[i][j] = min(minimum[i - 1][j], minimum[i - 1][parent[i - 1][j]]);
            maximum[i][j] = max(maximum[i - 1][j], maximum[i - 1][parent[i - 1][j]]);
        }
    }
}

void solve(int x, int y) {
    int X = x, Y = y;
    int mini = 10000001, maxi = 0;

    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i = 0; diff; i++) {
        if(diff & 1) {
            mini = min(mini, minimum[i][x]);
            maxi = max(maxi, maximum[i][x]);
            x = parent[i][x];
        }
        diff >>= 1;
    }

    if(x != y) {
        for(int i = 16; i >= 0; i--) {
            if(parent[i][x] != parent[i][y]) {
                mini = min(mini, min(minimum[i][x], minimum[i][y]));
                maxi = max(maxi, max(maximum[i][x], maximum[i][y]));
                x = parent[i][x];
                y = parent[i][y];
            }
        }
        mini = min(mini, min(minimum[0][x], minimum[0][y]));
        maxi = max(maxi, max(maximum[0][x], maximum[0][y]));
        x = parent[0][x];
    }

    cout << mini << ' ' << maxi << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y, dist; cin >> x >> y >> dist;
        graph[x].push_back({y, dist});
        graph[y].push_back({x, dist});
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    Traversal(1);
    MakeTable();
    cin >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
}