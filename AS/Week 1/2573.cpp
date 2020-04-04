/*
Problem: 빙산 (2573)
Tier: Gold 4
Detail:  지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 2차원 배열에 표시한다고 하자. 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.
빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.
단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다.
한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

Comment: 플러드 필 + 순회 문제인데
매번 일일히 풀로 순회 돌리면 열 받잖아...
그래서 1회 이후에는 남는걸 기준으로 큐에 넣고 돌리자.
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct point {
    int x, y, ice;
    point() {}
    point(int x, int y, int ice) : x(x), y(y), ice(ice) {}
};

int visited[301][301];
int graph[301][301];
int cnt = 0;
int N, M, year = 0;
queue<point> remain;

void travel(int x, int y) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
        if(graph[x+dx[i]][y+dy[i]] != 0 && visited[x+dx[i]][y+dy[i]] == 0) {
            travel(x + dx[i], y + dy[i]);
        }
    }
}

void remove() {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int size = remain.size();
    vector<pair<int, int>> removing;
    for(int i = 0; i < size; i++) {
        point p = remain.front(); remain.pop();
        int x = p.x, y = p.y, ice = p.ice;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
            if(!graph[x+dx[i]][y+dy[i]]) ice--;
        }
        if(ice >= 1) remain.push(point(x, y, ice));
        else removing.push_back({x, y});
    }
    for(int i = 0; i < removing.size(); i++) graph[removing[i].first][removing[i].second] = 0;
}

int get_size() {
    int size = remain.size(), ans = 0;
    for(int i = 0; i < size; i++) {
        point p = remain.front(); remain.pop();
        if(!visited[p.x][p.y]) {
            ans++;
            travel(p.x, p.y);
        }
        remain.push(p);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int t; cin >> t;
            if(t) remain.push(point(i, j, t));
            graph[i][j] = t;
        }
    }
    while(true) {
        memset(visited, 0, sizeof(visited));
        int tmp = get_size();
        if(tmp == 0) {
            cout << 0;
            return 0;
        }
        else if(tmp > 1) break;
        remove();
        year++;
    }
    if(year) cout << year;
    return 0;
}
