#include <bits/stdc++.h>
using namespace std;

bool is_exist[7] = {0, };
vector<pair<int, int>> pos[7];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int Mx[4] = {3, 3, 0, 0};
int My[4] = {0, 3, 0, 3};
int startX, startY;

int get_path(const vector<vector<int>> &board, vector<int> &candidate, vector<int> &order) {
    vector<vector<int>> graph(4, vector<int>(4));
    int X = startX, Y = startY;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            graph[i][j] = board[i][j];

    int answer = 0;

    for(int i = 0; i < candidate.size(); i++) {
        int dist[2][4][4];
        int idx = candidate[i];
        int first = order[i], second = 1 - order[i];
        memset(dist, -1, sizeof(dist));

        dist[0][X][Y] = 0;
        dist[1][pos[idx][first].first][pos[idx][first].second] = 0;
        queue<pair<int, int>> q;

        vector<pair<int, int>> start = {{X, Y}, pos[idx][first]};

        for(int idx = 0; idx < 2; idx++) {
            q.push(start[idx]);

            while(!q.empty()) {
                pair<int, int> p = q.front(); q.pop();
                int x = p.first, y = p.second;

                for(int j = 0; j < 4; j++) {
                    if(x + dx[j] < 0 || x + dx[j] == 4 || y + dy[j] < 0 || y + dy[j] == 4) continue;
                    if(dist[idx][x + dx[j]][y + dy[j]] == -1) {
                        dist[idx][x + dx[j]][y + dy[j]] = dist[idx][x][y] + 1;
                        q.push({x + dx[j], y + dy[j]});
                    }
                }

                if(x != 0) {
                    int tmp = x - 1;
                    while(tmp > 0 && graph[tmp][y] == 0) tmp--;
                    if(dist[idx][tmp][y] == -1) {
                        dist[idx][tmp][y] = dist[idx][x][y] + 1;
                        q.push({tmp, y});
                    }
                }

                if(x != 3) {
                    int tmp = x + 1;
                    while(tmp < 3 && graph[tmp][y] == 0) tmp++;
                    if(dist[idx][tmp][y] == -1) {
                        dist[idx][tmp][y] = dist[idx][x][y] + 1;
                        q.push({tmp, y});
                    }
                }

                if(y != 0) {
                    int tmp = y - 1;
                    while(tmp > 0 && graph[x][tmp] == 0) tmp--;
                    if(dist[idx][x][tmp] == -1) {
                        dist[idx][x][tmp] = dist[idx][x][y] + 1;
                        q.push({x, tmp});
                    }
                }

                if(y != 3) {
                    int tmp = y + 1;
                    while(tmp < 3 && graph[x][tmp] == 0) tmp++;
                    if(dist[idx][x][tmp] == -1) {
                        dist[idx][x][tmp] = dist[idx][x][y] + 1;
                        q.push({x, tmp});
                    }
                }
            }
        }

        answer += dist[0][pos[idx][first].first][pos[idx][first].second] + dist[1][pos[idx][second].first][pos[idx][second].second] + 2;

        graph[pos[idx][first].first][pos[idx][first].second] = 0;
        graph[pos[idx][second].first][pos[idx][second].second] = 0;

        X = pos[idx][second].first, Y = pos[idx][second].second;
    }

    return answer;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 10000;
    startX = r, startY = c;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] >= 1) {
                is_exist[board[i][j]] = 1;
                pos[board[i][j]].push_back({i, j});
            }
        }
    }

    vector<int> candidate;
    for(int i = 0; i < 7; i++) {
        if(is_exist[i]) candidate.push_back(i);
    }

    do {
        for(int i = 0; i <= candidate.size(); i++) {
            vector<int> order(candidate.size());
            for(int j = 0; j < i; j++) order[j] = 0;
            for(int j = 0; j < candidate.size() - i; j++) order[candidate.size() - j - 1] = 1;
            do {
                answer = min(answer, get_path(board, candidate, order));
            } while(next_permutation(order.begin(), order.end()));
        }
    } while(next_permutation(candidate.begin(), candidate.end()));

    return answer;
}

// Driver
int main() {
    vector<vector<int>> board(4, vector<int>(4));
    int r, c;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> board[i][j];
    cin >> r >> c;

    cout << solution(board, r, c);
}