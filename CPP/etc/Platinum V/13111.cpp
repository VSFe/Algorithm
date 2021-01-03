/*
Problem: 할 일 정하기 1
Tier: Platinum 5
Detail: N명의 사람과 N개의 일이 있다. 각 사람은 일을 하나 담당해야 하고, 각 일을 담당하는 사람은 한 명 이어야 한다.
또한, 모든 사람은 모든 일을 할 능력이 있다. 사람은 1번부터 N번까지 번호가 매겨져 있으며, 일도 1번부터 N번까지 번호가 매겨져 있다.
Dij를 i번 사람이 j번 일을 할 때 필요한 비용이라고 했을 때, 모든 일을 하는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 고려해야 할 변수는 두개. 두개를 모두 DP로 접근하게 되면 메모리가 터지기 때문에, 하나를 고정하고 다른 하나로 테이블을 구성해서 접근해야 함.
*/
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = (1 << 20) + 1;
int table[21][21];
int dp[21][SIZE];
int N;

int GetDP(int idx, int pos) {
    if(idx == N) return 0;
    int &ret = dp[idx][pos];
    if(ret != -1) return ret;
    
    ret = 200000;
    for(int i = 0; i < N; i++) {
        if(pos & (1 << i)) continue;
        ret = min(ret, GetDP(idx + 1, pos | (1 << i)) + table[idx][i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> table[i][j];
    memset(dp, -1, sizeof(dp));
    cout << GetDP(0, 0);
}