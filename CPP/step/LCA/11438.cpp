/*
1. 그래프를 입력 받음
2. 트리로 바꿔 줌.
3. 
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 100001;
int N, M;
vector<int> graph[SIZE];
int depth[SIZE];
int table[18][SIZE];

void Traversal(int node) {
    for(int i : graph[node]) {
        if(depth[i] == -1) {
            table[0][i] = node;
            depth[i] = depth[node] + 1;
            Traversal(i);
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 18; i++)
        for(int j = 1; j < SIZE; j++)
            table[i][j] = table[i - 1][table[i - 1][j]];
}

int solve(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];

    for(int i = 0; diff; i++) {
        if(diff & 1) {
            b = table[i][b];
        }
        diff >>= 1;
    }

    if(a != b) {
        for(int i = 17; i >= 0; i--) {
            if(table[i][a] != table[i][b]) {
                a = table[i][a];
                b = table[i][b];
            }
        }
        a = table[0][a];
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
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