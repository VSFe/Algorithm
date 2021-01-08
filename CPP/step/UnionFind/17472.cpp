/*
Problem: 다리 만들기 2 (17472)
Tier: Gold 3
Detail: 섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 한다. 이 나라의 지도는 N×M 크기의 이차원 격자로 나타낼 수 있고, 격자의 각 칸은 땅이거나 바다이다.
섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 말하고, 아래 그림은 네 개의 섬으로 이루어진 나라이다. 색칠되어있는 칸은 땅이다.
다리는 바다에만 건설할 수 있고, 다리의 길이는 다리가 격자에서 차지하는 칸의 수이다. 다리를 연결해서 모든 섬을 연결하려고 한다. 섬 A에서 다리를 통해 섬 B로 갈 수 있을 때, 섬 A와 B를 연결되었다고 한다.
다리의 양 끝은 섬과 인접한 바다 위에 있어야 하고, 한 다리의 방향이 중간에 바뀌면 안된다. 또, 다리의 길이는 2 이상이어야 한다.
다리의 방향이 중간에 바뀌면 안되기 때문에, 다리의 방향은 가로 또는 세로가 될 수 밖에 없다.
방향이 가로인 다리는 다리의 양 끝이 가로 방향으로 섬과 인접해야 하고, 방향이 세로인 다리는 다리의 양 끝이 세로 방향으로 섬과 인접해야 한다.
섬 A와 B를 연결하는 다리가 중간에 섬 C와 인접한 바다를 지나가는 경우에 섬 C는 A, B와 연결되어있는 것이 아니다. 
다리가 교차하는 경우가 있을 수도 있다. 교차하는 다리의 길이를 계산할 때는 각 칸이 각 다리의 길이에 모두 포함되어야 한다. 아래는 다리가 교차하는 경우와 기타 다른 경우에 대한 2가지 예시이다.
나라의 정보가 주어졌을 때, 모든 섬을 연결하는 다리 길이의 최솟값을 구해보자.
Comment: 1) Flood-fill을 통해 각각의 컴포넌트가 속한 그래프 포인트를 알아냄
2) 모든 포인트에서 직진을 쭉 해서 최솟값을 계속 갱신함
3) MST 생성
구 현 싫 어
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int table[10][10];
int visited[10][10];
int idx = 0;
int answer = 0;
int uf[6];
vector<pair<int, int>> graph[6];
vector<pair<int, pair<int, int>>> length_table;

void dfs(int x, int y, int idx) {
    visited[x][y] = idx;
    graph[idx].push_back({x, y});
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
        if(!table[x + dx[i]][y + dy[i]]) continue;
        if(visited[x + dx[i]][y + dy[i]] == -1) dfs(x + dx[i], y + dy[i], idx);
    }
}

int get_path(int x) {
    int answer = 1e9 + 1;
    vector<int> length(idx, 200);

    for(int i = 0; i < graph[x].size(); i++) {
        pair<int, int> p = graph[x][i];

        for(int idx = 0; idx < 4; idx++) {
            int X = p.first, Y = p.second;
            int cnt = 0;
            while(true) {
                X += dx[idx], Y += dy[idx];
                if(X < 0 || X == N || Y < 0 || Y == M) break;
                cnt++;
                if(visited[X][Y] != -1) {
                    if(visited[X][Y] <= x) break;
                    if(cnt <= 2) break;
                    length[visited[X][Y]] = min(length[visited[X][Y]], cnt - 1);
                    break;
                }
            }
        }
    }

    for(int i = x + 1; i < length.size(); i++)
        length_table.push_back({length[i], {x, i}});
}

int uf_find(int x) {
    return uf[x] == -1 ? x : uf[x] = uf_find(uf[x]);
}

void solve() {
    for(int i = 0; i < idx; i++) get_path(i);

    sort(length_table.begin(), length_table.end());
    for(int i = 0; i < 6; i++) uf[i] = -1;

    for(int i = 0; i < length_table.size(); i++) {
        int X = uf_find(length_table[i].second.first), Y = uf_find(length_table[i].second.second);
        if(X == Y) continue;
        uf[X] = Y;
        answer += length_table[i].first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> table[i][j];
    
    memset(visited, -1, sizeof(visited));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(visited[i][j] == -1 && table[i][j]) dfs(i, j, idx++);

    solve();
    if(answer >= 200) cout << -1;
    else cout << answer;
}

