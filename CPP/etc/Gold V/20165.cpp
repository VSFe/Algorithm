#include <bits/stdc++.h>
using namespace std;

int dominos_len[101][101];
bool dominos_alive[101][101];

int N, M, R;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int score = 0;

void offense(int x, int y, char pos) {
    int idx;
    int dest = 0;
    if(pos == 'E') idx = 0;
    else if(pos == 'W') idx = 1;
    else if(pos == 'S') idx = 2;
    else idx = 3;

    if(!dominos_alive[x][y]) return;
    score++;
    dominos_alive[x][y] = 0;
    dest = dominos_len[x][y];

    while(dest != 1) {
        dest--;
        x += dx[idx];
        y += dy[idx];

        if(x == N || x < 0 || y == M || y < 0) break;

        if(dominos_alive[x][y]) {
            dest = max(dominos_len[x][y], dest);
            score++;
        }
        dominos_alive[x][y] = 0;

    }
}

void defense(int x, int y) {
    dominos_alive[x][y] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> dominos_len[i][j]; 
            dominos_alive[i][j] = 1;           
        }
    }


    for(int i = 0; i < R; i++) {
        int x, y;
        char pos;

        cin >> x >> y >> pos;
        offense(x - 1, y - 1, pos);

        cin >> x >> y;
        defense(x - 1, y - 1);
    }

    cout << score << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dominos_alive[i][j]) cout << 'S' << ' ';
            else cout << 'F' << ' ';
        }
        cout << '\n';
    }
}