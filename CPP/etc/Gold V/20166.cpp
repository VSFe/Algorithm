#include <bits/stdc++.h>
using namespace std;

int dp[11][11][6];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
char hell[11][11];

int N, M, K;

int call_dp(string target) {
    queue<pair<int, int>> q;
    int cnt = 1;
    int visited[11][11][6];

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(hell[i][j] == target[0]) {
                q.push({i, j});
                dp[i][j][0] = 1;
            }
        }        
    }

    while(cnt != target.length()) {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;

            if(visited[x][y][cnt]) continue;
            visited[x][y][cnt] = 1;

            for(int idx = 0; idx < 8; idx++) {
                int X = x + dx[idx], Y = y + dy[idx];

                if(X < 0) X += N;
                if(Y < 0) Y += M;
                X %= N; Y %= M;

                if(hell[X][Y] == target[cnt]) {
                    q.push({X, Y});
                    dp[X][Y][cnt] += dp[x][y][cnt - 1];
                }
            }
        }

        cnt++;
    }

    int answer = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            answer += dp[i][j][target.length() - 1];

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> hell[i][j];

    for(int i = 0; i < K; i++) {
        memset(dp, 0, sizeof(dp));
        string target; cin >> target;
        cout << call_dp(target) << '\n';
    }    
}