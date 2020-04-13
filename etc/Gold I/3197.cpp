/*
Problem: 백조의 호수 (3197)
Tier: Gold 1
Detail: 두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.
호수는 가로로 R, 세로로 C만큼의 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.
호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.
아래에는 세 가지 예가 있다.
...XXXXXX..XX.XXX ....XXXX.......XX .....XX.......... 
....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... 
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... 
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX.... 
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... 
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ 
..XXXXX...XXX.... ....XX.....X..... ................. 
....XXXXX.XXX.... .....XX....X..... ................. 
      처음               첫째 날             둘째 날
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다. 며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성한다.
Comment: BFS 반복하면 무조건 TLE.
단 한번으로 끝낼 수 있는 방법이 있지 않을까?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int status[1500][1500], visited[1500][1500], N, M;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char tmp;

int find_minimum(int x, int y) {
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    fill(&visited[0][0], &visited[N-1][M-1], -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tmp;
            if(tmp == '.' || tmp == 'L') {
                q.push({i, j});
                visited[i][j] = 0;
            }
            status[i][j] = tmp;
        }
    }
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == M) continue;
            if(visited[x + dx[i]][y + dy[i]] != -1) continue;
            visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
            q.push({x + dx[i], y + dy[i]});
        }
    } 
    return 0;
}


