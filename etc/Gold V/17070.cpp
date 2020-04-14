/*
Problem: 파이프 옮기기 1 (17070)
Tier: Gold 5
Detail: 유현이가 새 집으로 이사했다. 새 집의 크기는 N×N의 격자판으로 나타낼 수 있고, 1×1크기의 정사각형 칸으로 나누어져 있다.
각각의 칸은 (r, c)로 나타낼 수 있다. 여기서 r은 행의 번호, c는 열의 번호이고, 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.
오늘은 집 수리를 위해서 파이프 하나를 옮기려고 한다. 파이프는 아래와 같은 형태이고, 2개의 연속된 칸을 차지하는 크기이다.
파이프는 회전시킬 수 있다. 파이프는 매우 무겁기 때문에, 유현이는 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안 된다. 즉, 파이프는 항상 빈 칸만 차지해야 한다.
파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.
파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.
가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.
Comment: (0, 0)부터 (N, N)까지 놓을 수 있는 경우의 수 = (0, 0) 부터 (A, B)까지 놓을 수 있는 경우의 수 + (A, B)부터 (N, N)까지 놓을 수 있는 경우의 수
문제 분할이 가능하므로 다이나믹 프로그래밍으로 풀면 됨.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[16][16], visited[16][16][3], N;

int cal(int x, int y, int prev) {
    if(x == N-1 && y == N-1) return 1;
    if(visited[x][y][prev] != -1) return visited[x][y][prev];
    int &ret = visited[x][y][prev];
    ret = 0;
    if(prev != 1 && y != N-1 && !graph[x][y + 1]) {
        ret += cal(x, y + 1, 0);
    }
    if(prev != 0 && x != N-1 && !graph[x + 1][y]) {
        ret += cal(x + 1, y, 1);
    }
    if(x != N-1 && y != N-1 && !graph[x + 1][y] && !graph[x][y + 1] && !graph[x+1][y+1]) {
        ret += cal(x + 1, y + 1, 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            for(int k = 0; k < 3; k++) visited[i][j][k] = -1;
        }
    }
    cout << cal(0, 1, 0);
    return 0;
}