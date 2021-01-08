#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int N, I;
int visited[301][301];

void visit(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < 8; i++) {
            int X = p.first + dx[i], Y = p.second + dy[i];
            if(X < 0 || X >= I || Y < 0 || Y >= I) continue;
            if(visited[X][Y] == -1) {
                visited[X][Y] = visited[p.first][p.second] + 1;
                q.push({X, Y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> I;
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        memset(visited, -1, sizeof(visited));
        visited[start_x][start_y] = 0;
        visit(start_x, start_y);

        if(visited[end_x][end_y] == -1) cout << 0 << '\n';
        else cout << visited[end_x][end_y] << '\n';
    }
}
