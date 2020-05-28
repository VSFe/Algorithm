/*
Problem: 비숍 (1799)
Tier: Gold 2
Detail: 서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다.
정사각형 체스판 위에 B라고 표시된 곳에 비숍이 있을 때 비숍은 대각선 방향으로 움직여 다른 말을 잡을 수 있다.
그런데 체스판 위에는 비숍이 놓일 수 없는 곳이 있다. 체스판에 색칠된 부분은 비숍이 놓일 수 없다고 하자. 색칠된 부분에는 비숍이 놓일 수 없지만 지나갈 수는 있다.
정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다. 체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때,
서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.
Comment: 문제를 쪼개서 해결할 수 있다는걸 배운 문제.
고생했으니 나중에 까먹지 말고...
*/

#include <iostream>
using namespace std;

int N, MAX = 0, graph[10][10], visited[10][10], color[10][10];
int dx[] = {1, -1, 1, -1};
int dy[] = {-1, 1, 1, -1};
int ans[] = {0, 0};

void get_ans(int idx, int cnt, int col) {
    ans[col] = max(cnt, ans[col]);
    for(int i = idx + 1; i < N * N; i++) {
        int x = i / N;
        int y = i % N;
        if(color[x][y] != col || !graph[x][y]) continue;
        bool is_correct = true;
        for(int j = 0; j < 4; j++) {
            int nx = x, ny = y;
            while(true) {
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                if(visited[nx][ny]) {
                    is_correct = false;
                    j = 4;
                    break;
                }
                nx += dx[j], ny += dy[j];
            }
        }
        if(!is_correct) continue;
        visited[x][y] = 1;
        get_ans(i, cnt + 1, col);
        visited[x][y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(i % 2 == 0) {
                if(j % 2 == 0) color[i][j] = 1;
            }
            else if(j % 2 == 1) color[i][j] = 1;
        }
    }
    get_ans(-1, 0, 0);
    get_ans(-1, 0, 1);
    cout << ans[0] + ans[1];
}