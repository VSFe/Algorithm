/*
Problem: Dance Dance Revolution (18891)
Tier: Gold 1
Detail: 너무 뚱뚱한 백승환은 요즘 “Dance Dance Revolution”이라는 게임에 미쳐서 살고 있다. 하지만 그의 춤솜씨를 보면 알 수 있듯이, 그는 DDR을 잘 하지 못한다. 그럼에도 불구하고 그는 살을 뺄 수 있다는 일념으로 DDR을 즐긴다.
DDR은 아래의 그림과 같은 모양의 발판이 있고, 주어진 스텝에 맞춰 나가는 게임이다. 발판은 하나의 중점을 기준으로 위, 아래, 왼쪽, 오른쪽으로 연결되어 있다. 편의상 중점을 0, 위를 1, 왼쪽을 2, 아래를 3, 오른쪽을 4라고 정하자.
처음에 게이머는 두 발을 중앙에 모으고 있다.(그림에서 0의 위치) 그리고 게임이 시작하면, 지시에 따라 왼쪽 또는 오른쪽 발을 움직인다. 하지만 그의 두 발이 동시에 움직이지는 않는다.
이 게임에는 이상한 규칙이 더 있다. 두 발이 같은 지점에 있는 것이 허락되지 않는 것이다. (물론 게임 시작시에는 예외이다) 만약, 한 발이 1의 위치에 있고, 다른 한 발이 3의 위치에 있을 때, 3을 연속으로 눌러야 한다면, 3의 위치에 있는 발로 반복해야 눌러야 한다는 것이다.
오랫동안 DDR을 해 온 백승환은 발이 움직이는 위치에 따라서 드는 힘이 다르다는 것을 알게 되었다. 만약, 중앙에 있던 발이 다른 지점으로 움직일 때, 2의 힘을 사용하게 된다.
그리고 다른 지점에서 인접한 지점으로 움직일 때는 3의 힘을 사용하게 된다. (예를 들면 왼쪽에서 위나 아래로 이동할 때의 이야기이다.) 그리고 반대편으로 움직일때는 4의 힘을 사용하게 된다.
(위쪽에서 아래쪽으로, 또는 오른쪽에서 왼쪽으로). 만약 같은 지점을 한번 더 누른다면, 그때는 1의 힘을 사용하게 된다.
이 때 백승환이 모든 지시 사항을 만족시키는데 사용하는 최소 힘을 구하여라.
Comment: 평범한 3차원 dp.
*/

#include <iostream>
using namespace std;

int dp[100010][5][5], dt[100010], cnt = 0;

int cal_dp(int x, int y, int idx) {
    if(idx == cnt) return 0;
    int &ret = dp[idx][x][y];
    if(ret != -1) return ret;
    int k = dt[idx];
    if(x == k) return ret = cal_dp(x, y, idx + 1) + 1;
    if(y == k) return ret = cal_dp(x, y, idx + 1) + 1;
    int add_x, add_y;
    if(x == 0) add_x = 2;
    else if(abs(x - k) % 2) add_x = 3;
    else add_x = 4;
    if(y == 0) add_y = 2;
    else if(abs(y - k) % 2) add_y = 3;
    else add_y = 4;
    return ret = min(cal_dp(k, y, idx + 1) + add_x, cal_dp(x, k, idx + 1) + add_y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true) {
        cin >> dt[++cnt];
        if(!dt[cnt]) break;
    }
    for(int i = 1; i <= cnt; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                dp[i][j][k] = -1;
            } 
        }
    }
    cout << cal_dp(0, 0, 1);
    return 0;
}