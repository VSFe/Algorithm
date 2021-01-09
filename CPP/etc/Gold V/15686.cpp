#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int graph[51][51];
int visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;
int answer = 1e9;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int getMinimumPath() {
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == 2) {
                q.push({i, j});  
                visited[i][j] = 0;
            }            
        }
    }

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int X = p.first + dx[i], Y = p.second + dy[i];
            if(X < 0 || X == N || Y < 0 || Y == N) continue;
            if(visited[X][Y] == -1) {
                visited[X][Y] = visited[p.first][p.second] + 1;
                q.push({X, Y});
            }
        }
    }

    int result = 0;
    for(pair<int, int> p: home) result += visited[p.first][p.second];
    return result;
}

void solve() {
    vector<int> possible_case(chicken.size(), 0);
    for(int i = 0; i < M; i++) possible_case[i] = 1;

    do {
        for(int i = 0; i < possible_case.size(); i++) 
            if(!possible_case[i])
                graph[chicken[i].first][chicken[i].second] = 0;

        answer = min(answer, getMinimumPath());

        for(pair<int, int> p: chicken) graph[p.first][p.second] = 2;
    } while(prev_permutation(possible_case.begin(), possible_case.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int tmp; cin >> tmp;
            graph[i][j] = tmp;
            if(tmp == 2) chicken.push_back({i, j});
            else if(tmp == 1) home.push_back({i, j});
        }
    }

    solve();
    cout << answer;
}