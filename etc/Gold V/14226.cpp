/*
Problem: 이모티콘 (14226)
Tier: Gold 5
Detail: 영선이는 매우 기쁘기 때문에, 효빈이에게 스마일 이모티콘을 S개 보내려고 한다.
영선이는 이미 화면에 이모티콘 1개를 입력했다. 이제, 다음과 같은 3가지 연산만 사용해서 이모티콘을 S개 만들어 보려고 한다.
    화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
    클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
    화면에 있는 이모티콘 중 하나를 삭제한다.
모든 연산은 1초가 걸린다. 또, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다. 클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 일부만 클립보드에 복사할 수는 없다. 또한, 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다. 화면에 이모티콘을 붙여넣기 하면, 클립보드에 있는 이모티콘의 개수가 화면에 추가된다.
영선이가 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 각각의 케이스
복사 (1초)
붙여넣기 (1초. 단 복사가 선행 되어야 함. 붙여넣을 수 있는 갯수를 나타내는게 필요하겠는데...)
삭제 (1초)
dp 테이블: dp[현재 갯수][클립보드에 있는 이모티콘 수]
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
int N, dp[1010][1000];

int cal_dp(int x, int y) {
    if(x == N) return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = INF;
    if(y != 0 && x + y < N + 10) ret = min(ret, (cal_dp(x + y, y) + 1));
    if(x != y) ret = min(ret, (cal_dp(x, x) + 1));
    if(x != 1) ret = min(ret, (cal_dp(x - 1, y) + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << cal_dp(1, 0);
}

