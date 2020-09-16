/*
Problem: 벽 부수고 이동하기 4
Tier: Gold 2
Detail: N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.
각각의 벽에 대해서 다음을 구해보려고 한다.
    벽을 부수고 이동할 수 있는 곳으로 변경한다.
    그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
Comment: 플러드 필 방식으로 시도하니 TLE...
이차원으로 uf를 확장해서 (해시 기법을 사용해서 1차원으로 차원을 구겨 넣었다.) 분리집합 문제로 접근하니 한방에 AC.
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int graph[1001][1001], uf[1001][1001], cnt[1001][1001];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int N, M;

int uf_find(int x) {
    int X = x / 1001, Y = x % 1001;
    return (uf[X][Y] == -1) ? x : uf[X][Y] = uf_find(uf[X][Y]); 
}

void uf_union(int x, int y) {
    int tx = uf_find(x), ty = uf_find(y);
    if(tx != ty) {
        int tx_x = tx / 1001, tx_y = tx % 1001;
        int ty_x = ty / 1001, ty_y = ty % 1001;
        uf[ty_x][ty_y] = tx;
        cnt[tx_x][tx_y] += cnt[ty_x][ty_y];
    }
}

bool uf_same(int x, int y) {
    return uf_find(x) == uf_find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            if(tmp[j] == '0') {
                graph[i][j] = 0;
                cnt[i][j] = 1;
            }
            else graph[i][j] = 1;
        }        
    }
    fill(uf[0], uf[0] + (1001 * 1001), -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j]) continue;
            for(int idx = 0; idx < 4; idx++) {
                int X = i + dx[idx], Y = j + dy[idx]; 
                if(X == -1 || X == N || Y == -1 || Y == M) continue;
                if(!graph[X][Y]) uf_union(i * 1001 + j, X * 1001 + Y);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!graph[i][j]) {
                cout << 0;
                continue;
            }
            int ans = 1;
            for(int k = 0; k < 4; k++) {
                int X = i + dx[k], Y = j + dy[k];
                if(X == -1 || X == N || Y == -1 || Y == M) continue;
                bool is_same = false;
                for(int s = 0; s < k; s++) {
                    int X_s = i + dx[s], Y_s = j + dy[s];
                    if(X_s == -1 || X_s == N || Y_s == -1 || Y_s == M) continue;
                    if(uf_same(X * 1001 + Y, X_s * 1001 + Y_s)) {
                        is_same = true;
                        break;
                    }
                }
                if(!is_same) {
                    int tmp = uf_find(X * 1001 + Y);
                    ans += cnt[tmp / 1001][tmp % 1001];
                }
            }
            cout << ans % 10;
        }
        cout << '\n';
    }
}