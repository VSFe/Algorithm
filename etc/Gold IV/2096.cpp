/*
Problem: 내려가기 (2096)
Tier: Gold 4
Detail: N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.
먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다.
바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다. 
Comment: 어차피 중요한건 현재의 값.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int max_dp[3], min_dp[3], N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp_dt[3], tmp_max[3], tmp_min[3];
        for(int j = 0; j < 3; j++) {
            cin >> tmp_dt[j];
            tmp_max[j] = max_dp[j];
            tmp_min[j] = min_dp[j];
        }
        max_dp[0] = max(tmp_max[0], tmp_max[1]) + tmp_dt[0];
        max_dp[1] = max({tmp_max[0], tmp_max[1], tmp_max[2]}) + tmp_dt[1];
        max_dp[2] = max(tmp_max[1], tmp_max[2]) + tmp_dt[2];
        min_dp[0] = min(tmp_min[0], tmp_min[1]) + tmp_dt[0];
        min_dp[1] = min({tmp_min[0], tmp_min[1], tmp_min[2]}) + tmp_dt[1];
        min_dp[2] = min(tmp_min[1], tmp_min[2]) + tmp_dt[2];
    }
    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << ' ' << min({min_dp[0], min_dp[1], min_dp[2]});
}


