#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 11;
int N, M;
int depth[SIZE];
int parent[17][SIZE];
int candy_base[SIZE];
int candy[17][SIZE];
vector<int> graph[SIZE];

void Traversal(int node) {
    for(int i : graph[node]) {
        if(depth[i] == -1) {
            depth[i] = depth[node] + 1;
            parent[0][i] = node;
            candy[0][i] = candy_base[node];
            Traversal(i);
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 17; i++) {
        for(int j = 1; j < SIZE; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];   
            candy[i][j] = candy[i - 1][j] | candy[i - 1][parent[i - 1][j]];          
        }
    }
}

bool isOk(int x, int y, int target) {
    int candyIdx = candy_base[x] | candy_base[y];
    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i = 0; diff; i++) {
        if(diff & 1) {
            candyIdx |= candy[i][x];            
            x = parent[i][x];
        }
        diff >>= 1;
    }

    if(x != y) {
        for(int i = 16; i >= 0; i--) {
            if(parent[i][x] != parent[i][y]) {
                candyIdx |= candy[i][x];
                candyIdx |= candy[i][y];
                x = parent[i][x];
                y = parent[i][y];
            }
        }
        candyIdx |= candy[0][x];        
        x = parent[0][x];
    }
    return candyIdx & (1 << target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    vector<int> isCandy(6, 0);
    for(int i = 1; i <= N; i++) {
        int can; cin >> can;
        candy_base[i] = (1 << can);
        isCandy[can] = 1;
    }
    for(int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    Traversal(1);
    MakeTable();
    cin >> M;

    int prev, pos; cin >> prev >> pos;
    if(isCandy[pos]) cout << "PLAY" << '\n';
    else cout << "CRY" << '\n';

    for(int i = 1; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if(isOk(prev, x, y)) cout << "PLAY" << '\n';
        else cout << "CRY" << '\n';
        prev = x;
    }
}