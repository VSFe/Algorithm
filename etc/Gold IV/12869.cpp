/*
Problem: 뮤탈리스크 (12869)
Tier: Gold 4
Detail: 수빈이는 강호와 함께 스타크래프트 게임을 하고 있다. 수빈이는 뮤탈리스크 1개가 남아있고, 강호는 SCV N개가 남아있다.
각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다. 즉, 이 게임은 수빈이가 이겼다는 것이다.
뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.
    첫 번째로 공격받는 SCV는 체력 9를 잃는다.
    두 번째로 공격받는 SCV는 체력 3을 잃는다.
    세 번째로 공격받는 SCV는 체력 1을 잃는다.
SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 가능한 케이스가 꽤 많다... dp 테이블을 60 * 60 * 60 으로 짜면 216000이니 할 만 한 것 같기도 하고...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dp[61][61][61], N, scv[3];

int cal_dp(int x1, int x2, int x3) {
    x1 = max(x1, 0), x2 = max(x2, 0), x3 = max(x3, 0);
    if(x1 == 0 && x2 == 0 && x3 == 0) return 0;
    if(dp[x1][x2][x3] != -1) return dp[x1][x2][x3];
    int &ret = dp[x1][x2][x3];
    ret = 100;
    ret = min(ret, cal_dp(x1 - 9, x2 - 3, x3 - 1) + 1);
    ret = min(ret, cal_dp(x1 - 9, x2 - 1, x3 - 3) + 1);
    ret = min(ret, cal_dp(x1 - 3, x2 - 9, x3 - 1) + 1);
    ret = min(ret, cal_dp(x1 - 3, x2 - 1, x3 - 9) + 1);
    ret = min(ret, cal_dp(x1 - 1, x2 - 9, x3 - 3) + 1);
    ret = min(ret, cal_dp(x1 - 1, x2 - 3, x3 - 9) + 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> scv[i];
    }
    cout << cal_dp(scv[0], scv[1], scv[2]);
}


