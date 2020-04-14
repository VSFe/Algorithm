/*
Problem: 3루수는 몰라 (17351)
Tier: Gold 5
Detail: (0, 0)에서 출발하여 다음 조건에 맞춰 운동장을 순회할 떄, MOLA를 볼 수 있는 최댓값을 구하는 프로그램을 작성하시오.
    운동장은 N×N 크기의 격자로 표현된다.
    운동장의 각 칸에는 알파벳 대문자로 표현되는 단서들이 숨겨져 있다.
    우리는 (1, 1)에서 (N, N)까지 이동하면서 단서를 수집해야 한다. (각 좌표는 시작점과 도착점이다.)
    지금은 여름이라 몹시 더우므로, (r+1, c) 또는 (r, c+1)로만 움직여야 한다. (안 그러면 탈진해서 쓰러질 것이다!) 물론, 운동장을 벗어날 수는 없다.
    운동장을 지나면서 수집한 단서를 순서대로 이어 붙인 문자열을 S라고 하자. S에 "MOLA"라는 부분 문자열이 최대한 많이 등장하도록 움직여야 한다.
    어떤 칸을 지나면 반드시 해당 칸의 단서를 수집해야 한다. 즉, 단서를 취사 선택하지 않는다.
Comment: 진짜 마음고생 심하게 한 문제였다... dp를 차원을 추가하여 풀면 해결.
*/

#include <iostream>
#include <algorithm>
using namespace std;

char str[4] = {'M', 'O', 'L', 'A'};
char table[10][10];
int dp[10][10][5], N;

int cal_dp(int x, int y, int status) {
    if(dp[x][y][status] != -1) return dp[x][y][status];
    if(x == N-1 && y == N-1 && status == 3 && table[x][y] == 'A') return 1;
    int &ret = dp[x][y][status];
    bool is_complete = false;
    if(status == 4) {
        is_complete = true;
        status = 0;
    }
    ret = 0;
    if(x != N-1) {
        ret = max(cal_dp(x + 1, y, 0), ret);
        if(str[status] == table[x][y]) ret = max(cal_dp(x + 1, y, status + 1), ret);
    }
    if(y != N-1) {
        ret = max(cal_dp(x, y + 1, 0), ret);
        if(str[status] == table[x][y]) ret = max(cal_dp(x, y + 1, status + 1), ret);
    }
    if(is_complete) ret++;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> table[i][j];
            for(int k = 0; k < 5; k++) dp[i][j][k] = -1;
        }
    }
    cal_dp(0, 0, 0);
    cout << dp[0][0][0];
    return 0;
}