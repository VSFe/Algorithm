/*
Problem: 로봇 조종하기 (2169)
Tier: Gold 1
Detail: NASA에서는 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다. 실제 화성의 모습은 굉장히 복잡하지만, 로봇의 메모리가 얼마 안 되기 때문에 지형을 N×M 배열로 단순화 하여 생각하기로 한다.
지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다. 또한 한 번 탐사한 지역(배열에서 하나의 칸)은 탐사하지 않기로 한다.
각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래 (N, M)으로 보내려고 한다.
이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성하시오.
Comment: 위에서 갓 내려온 경우, 왼쪽에서 온 경우, 오른쪽에서 온 경우 이렇게 3개로 케이스를 나눠서 풀면 될 것 같음...
*/

#include <iostream>
using namespace std;

int N, M;
int dp[1000][1000][3], dt[1000][1000];
const int INF = -1e8;

int cal_dp(int x, int y, int status) {
    if(x == N - 1 && y == M - 1) return dt[N-1][M-1];
    int &ret = dp[x][y][status];
    if(ret != INF) return ret;
    //status 0: 내려옴 -> 왼/오 모두 가능 1: 왼쪽에서 옴 -> 왼쪽으로는 못 감 2: 반대
    if(status != 2 && y != 0) {
        ret = max(ret, dt[x][y] + cal_dp(x, y - 1, 1));
    }
    if(status != 1 && y != M - 1) {
        ret = max(ret, dt[x][y] + cal_dp(x, y + 1, 2));
    }
    if(x != N - 1) {
        ret = max(ret, dt[x][y] + cal_dp(x + 1, y, 0));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> dt[i][j];
    fill(&dp[0][0][0], &dp[999][999][2], INF);
    cout << cal_dp(0, 0, 0);
    return 0;
}