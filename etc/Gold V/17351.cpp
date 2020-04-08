#include <iostream>
#include <algorithm>
using namespace std;

char str[4] = {'M', 'O', 'L', 'A'};
char table[500][500];
int dp[500][500], visited[500][500], N;

int cal_dp(int x, int y, int status, int prev) {
    if(visited[x][y]) return dp[x][y];
    int &ret = dp[x][y];
    int add = 0, val_x = 0, val_y = 0;
    if(table[x][y] == str[status]) {
        if(status == 3) {
            add++;
            status = 0;
        }
        else status++;
    }
    else if(table[x][y] == str[0]) status = 1;
    else status = 0;
    if(x < N - 1) val_x = cal_dp(x + 1, y, status, prev);
    if(y < N - 1) val_y = cal_dp(x, y + 1, status, prev);
    ret = max(val_x, val_y) + add;
    visited[x][y] = 1;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> table[i][j];
    }
    cal_dp(0, 0, 0, 0);
    cout << dp[0][0];
    return 0;
}