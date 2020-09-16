#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[101][101];
int H, W;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char c; cin >> c;
            if(c == '\\' || c == '/') graph[i][j] = 1;
        }
    }

    queue<pair<int, int>> q;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < W; j++) {
            if(!graph[i * (H - 1)][j]) {
                q.push({i * (H - 1), j});
                graph[i * (H - 1)][j] = -1;
            }                  
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < H; j++) {
            if(!graph[j][i * (W - 1)]) {
                q.push({j, i * (W - 1)});
                graph[j][i * (W - 1)] = -1;
            }                  
        }
    }

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] == H || y + dy[i] < 0 || y + dy[i] == W) continue;
            if(!graph[x + dx[i]][y + dy[i]]) {
                graph[x + dx[i]][y + dy[i]] = -1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }

    double answer = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(graph[i][j] == 1) answer += 0.5;
            else if(!graph[i][j]) answer += 1;
        }
    }

    cout << answer;
    return 0;
}