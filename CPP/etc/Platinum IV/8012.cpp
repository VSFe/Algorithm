/*
Problem: 한동이는 영업사원! (8012)
Tier: Platinum IV
Detail: 포항 시내의 도시들은 1부터 n까지 번호 지어져 있다. 한동이는 항상 포항시청에서 여행을 시작하고, 포항시청의 번호는 항상 1번이다.
모든 도시들은 양방향 도로로 연결되어있는데 한 도시에서 바로 길이 이어져있는 다른 도시로 이동하는데는 항상 1의 시간이 걸린다. 포항시청에서는 어떤 도시든지 갈 수 있다.
또한 포항의 도로는 굉장히 잘 되어있어서 도로끼리 사이클을 만들지 않는다.
여러분의 목표는 한동이가 모든 도시를 방문하는데 걸리는 최소의 시간을 출력하는 것이다.
Comment: 사이클이 없으니 그래프를 어떻게든 늘여트려서 트리 구조로 유도할 수 있다.
그러면 자연스럽게 LCA로 최단거리를 구하면 해결.
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int SIZE = 30001;
int N, M;
int depth[SIZE];
int parent[16][SIZE];
vector<int> graph[SIZE];

void Traversal(int node) {
    for(int i : graph[node]) {
        if(depth[i] == -1) {
            depth[i] = depth[node] + 1;
            parent[0][i] = node;
            Traversal(i);            
        }
    }
}

void MakeTable() {
    for(int i = 1; i < 16; i++)
        for(int j = 1; j < SIZE; j++)
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int solve(int a, int b) {
    int A = a, B = b;
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

    return depth[A] + depth[B] - depth[a] * 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    Traversal(1);
    MakeTable();

    int M; cin >> M;
    vector<int> route(M);
    for(int i = 0; i < M; i++) {
        cin >> route[i];
    }

    int answer = 0;
    for(int i = 1; i < M; i++) {
        answer += solve(route[i - 1], route[i]);
    }

    cout << answer;
}