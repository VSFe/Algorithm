#include <iostream>
using namespace std;

int room[51][51];
int N, M, T;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int air_1, air_2;

int check(int x, int y, int tmp[][51]) {
    int result = 0;
    for(int i = 0; i < 4; i++) {
        int X = x + dx[i], Y = y + dy[i];
        if(X < 0 || X == N || Y < 0 || Y == M || (Y == 0 && (X == air_1 || X == air_2))) continue;
        tmp[X][Y] += room[x][y] / 5;
        result++;
    }

    return result;
}

void spread() {
    int tmp[51][51] = {0, };
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(room[i][j] > 0) tmp[i][j] += room[i][j] - (room[i][j]) / 5 * check(i, j, tmp);
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            room[i][j] = tmp[i][j];
    room[air_1][0] = -1;
    room[air_2][0] = -1;
}

void cleanUp() {
    for(int i = air_1 - 2; i >= 0; i--) room[i + 1][0] = room[i][0];
    for(int i = 1; i < M; i++) room[0][i - 1] = room[0][i];
    for(int i = 1; i <= air_1; i++) room[i - 1][M - 1] = room[i][M - 1];
    for(int i = M - 1; i >= 1; i--) room[air_1][i] = room[air_1][i - 1];
    room[air_1][1] = 0;
}

void cleanDown() {
    for(int i = air_2 + 2; i < N; i++) room[i - 1][0] = room[i][0];
    for(int i = 1; i < M; i++) room[N - 1][i - 1] = room[N - 1][i];
    for(int i = N - 2; i >= air_2; i--) room[i + 1][M - 1] = room[i][M - 1];
    for(int i = M - 2; i >= 1; i--) room[air_2][i + 1] = room[air_2][i];
    room[air_2][1] = 0; 
}

void solve() {
    spread();
    cleanUp();
    cleanDown();
}

void find_air() {
    for(int i = 0; i < N; i++)
        if(room[i][0] == -1) {
            air_1 = i, air_2 = i + 1;
            return;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> room[i][j];

    find_air();

    for(int i = 0; i < T; i++) solve();

    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            result += room[i][j];
    }

    cout << result + 2;
}