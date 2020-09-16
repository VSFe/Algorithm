/*
Problem: 복제 로봇 (1944)
Tier: Gold 2
Detail: 세준이는 어느 날 획기적인 로봇을 한 개 개발하였다. 그 로봇은 복제 장치를 이용하면 자기 자신을 똑같은 로봇으로 원하는 개수만큼 복제시킬 수 있다.
세준이는 어느 날 이 로봇을 테스트하기 위하여 어떤 미로에 이 로봇을 풀어 놓았다. 이 로봇의 임무는 미로에 흩어진 열쇠들을 모두 찾는 것이다.
그리고 열쇠가 있는 곳들과 로봇이 출발하는 위치에 로봇이 복제할 수 있는 장치를 장착해 두었다.
N*N의 정사각형 미로와 M개의 흩어진 열쇠의 위치, 그리고 이 로봇의 시작 위치가 주어져 있을 때, 모든 열쇠를 찾으면서 로봇이 움직이는 횟수의 합을 최소로 하는 프로그램을 작성하여라.
로봇은 상하좌우 네 방향으로 움직이며, 로봇이 열쇠가 있는 위치에 도달했을 때 열쇠를 찾은 것으로 한다.
(복제된 로봇이어도 상관없다) 하나의 칸에 동시에 여러 개의 로봇이 위치할 수 있으며, 로봇이 한 번 지나간 자리라도 다른 로봇 또는 자기 자신이 다시 지나갈 수 있다.
복제에는 시간이 들지 않으며, 로봇이 움직이는 횟수의 합은 분열된 로봇 각각이 움직인 횟수의 총 합을 말한다. 복제된 로봇이 열쇠를 모두 찾은 후 같은 위치로 모일 필요는 없다.
Comment: 문제가 어려운 것 같지만 꼼꼼히 읽으면 해석이 가능하다.
결과적으로 A 지점과 B 지점은 로봇 하나로 커버가 가능함.
즉, 모든 구간을 방문하기 위한 모든 로봇의 최소거리는 MST를 의미함.
따라서 0이 아닌 지점의 칸을 찾아내어 MST를 만들어 내면 해결!!
BFS를 섞다보니 코드가 길어졌다... 그래도 잘 풀었네.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
    int u, v;
    double dist;
    edge() : edge(-1, -1, 0) {}
    edge(int _u, int _v, double _dist) : u(_u), v(_v), dist(_dist) {}
    bool operator <(const edge& e) const { return dist < e.dist; }
};

int N, M, visited[51][51], uf[501], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> vec;
queue<pair<int, int>> q;
vector<edge> Edges;
int maze[51][51];

int uf_find(int x) {
    return (uf[x] == -1) ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int p_x = uf_find(x), p_y = uf_find(y);
    if(p_x == p_y) return false;
    uf[p_y] = p_x;
    return true;
}

void bfs() {
    for(int i = 0; i < M; i++) {
        q.push(vec[i]);
        fill(&visited[0][0], &visited[50][50], 0);
        visited[vec[i].first][vec[i].second] = 1;
        int len = 0;
        while(!q.empty()) {
            int size = q.size();
            len++;
            for(int j = 0; j < size; j++) {
                pair<int, int> p = q.front(); q.pop();
                int x = p.first, y = p.second;
                visited[x][y] = 1;
                for(int idx = 0; idx < 4; idx++) {
                    int X = x + dx[idx], Y = y + dy[idx];
                    if(X < 0 || X == N || Y < 0 || Y == N) continue;
                    if(visited[X][Y]) continue;
                    if(maze[X][Y] == 0) {
                        q.push({X, Y});
                        visited[X][Y] = 1;
                    }
                    else if(maze[X][Y] != 1) {
                        Edges.push_back({maze[vec[i].first][vec[i].second] - 1, maze[X][Y] - 1, len});
                        visited[X][Y] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    char c;
    int total = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c;
            if(c == 'S' || c == 'K') {
                vec.push_back({i, j});
                maze[i][j] = 1 + ++total;
            }
            else maze[i][j] = c - '0';
        }
    }
    M++;
    bfs();
    sort(Edges.begin(), Edges.end());
    fill(uf, uf + 501, -1);
    int ans = 0, cnt = 0;
    for(int i = 0; i < Edges.size(); i++) {
        if(uf_union(Edges[i].u, Edges[i].v)) {
            ans += Edges[i].dist;
            if(++cnt == M - 1) break;
        }
    }
    if(cnt != M-1) cout << -1;
    else cout << ans;
}