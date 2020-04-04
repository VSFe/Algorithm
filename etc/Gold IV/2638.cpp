/*
Problem: 치즈 (2638)
Tier: Gold 4
Detail: N×M (5≤N, M≤100)의 모눈종이 위에 아주 얇은 치즈가 <그림 1>과 같이 표시되어 있다. 단, N 은 세로 격자의 수이고, M 은 가로 격자의 수이다.
이 치즈는 냉동 보관을 해야만 하는데 실내온도에 내어놓으면 공기와 접촉하여 천천히 녹는다.
그런데 이러한 모눈종이 모양의 치즈에서 각 치즈 격자(작 은 정사각형 모양)의 4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다.
<그림 2>와 같이 치즈 내부에 있는 공간은 치즈 외부 공기와 접촉하지 않는 것으로 가정한다. 그러므 로 이 공간에 접촉한 치즈 격자는 녹지 않고 C로 표시된 치즈 격자만 사라진다.
그러나 한 시간 후, 이 공간으로 외부공기가 유입되면 <그림 3>에서와 같이 C로 표시된 치즈 격자들이 사라지게 된다.
모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다. 입력으로 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 구하는 프로그램을 작성하시오.
Comment: 
*/

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
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
};

int visited[101][101];
int graph[101][101];
int cnt = 0;
int N, M, result = 0;
queue<point> remain;

void travel(int x, int y) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
        if(visited[x+dx[i]][y+dy[i]] == 0) {
            if(graph[x+dx[i]][y+dy[i]] != 0) visited[x+dx[i]][y+dy[i]] = 2;
            else travel(x + dx[i], y + dy[i]);
        }
    }
}

void remove() {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int size = remain.size();
    memset(visited, 0, sizeof(visited));
    travel(0, 0);
    vector<pair<int, int>> removing;
    for(int i = 0; i < size; i++) {
        point p = remain.front(); remain.pop();
        int x = p.x, y = p.y, cnt = 0;
        if(visited[x][y] != 2) {
            remain.push(p);
            continue;
        }
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
            if(visited[x+dx[i]][y+dy[i]] == 1) cnt++; 
        }
        if(cnt < 2) remain.push(point(x, y));
        else removing.push_back({x, y});
    }
    for(int i = 0; i < removing.size(); i++) graph[removing[i].first][removing[i].second] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int t; cin >> t;
            if(t) remain.push(point(i, j));
            graph[i][j] = t;
        }
    }
    while(!remain.empty()) {
        result++;
        remove();
    }
    cout << result;
    return 0;
}
