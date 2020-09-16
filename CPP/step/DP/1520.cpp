/*
Problem: 내리막 길 (1520)
Tier: Gold 4
Detail: 여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다.
그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 
지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.
Comment: 단순 완전 탐색? O(4^N)!
그래프 탐색의 경우, 방문 여부를 반드시 표기해야 한다.
괜히 방문했던데 또 방문하는 대 참사 없도록
하나는 시간초과, 하나는 고작 32ms!
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, bool> dp[501][501];
int num_data[501][501];
int N, M;

int dfs(int x, int y, int gap) {
    if(dp[x][y].second) return dp[x][y].first;
    if(y != 0 && num_data[x][y-1] < gap) dp[x][y].first += dfs(x, y-1, num_data[x][y-1]);
    if(y != M-1 && num_data[x][y+1] < gap) dp[x][y].first += dfs(x, y+1, num_data[x][y+1]);
    if(x != 0 && num_data[x-1][y] < gap) dp[x][y].first += dfs(x-1, y, num_data[x-1][y]);
    if(x != N-1 && num_data[x+1][y] < gap) dp[x][y].first += dfs(x+1, y, num_data[x+1][y]);
    dp[x][y].second = true;
    return dp[x][y].first;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &num_data[i][j]);
        }
    }
    dp[N-1][M-1] = make_pair(1, true);
    printf("%d", dfs(0, 0, num_data[0][0]));
    return 0;
}