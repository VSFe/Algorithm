/*
Problem: 1학년
Tier: Gold 5
Detail: 상근이가 1학년 때, 덧셈, 뺄셈을 매우 좋아했다. 상근이는 숫자가 줄 지어있는 것을 보기만 하면, 마지막 두 숫자 사이에 '='을 넣고
 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만들며 놀고 있다. 예를 들어, "8 3 2 4 8 7 2 4 0 8 8"에서 등식 "8+3-2-4+8-7-2-4-0+8=8"을 만들 수 있다.
상근이는 올바른 등식을 만들려고 한다. 상근이는 아직 학교에서 음수를 배우지 않았고, 20을 넘는 수는 모른다.
따라서, 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다. 예를 들어, "8+3+2-4-8-7+2+4+0+8=8"은 올바른 등식이지만,
8+3+2-4-8-7이 음수이기 때문에, 상근이가 만들 수 없는 등식이다.
숫자가 주어졌을 때, 상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오.
Comment: 숫자의 갯수가 100개, 가능한 범위가 0~20이니, 2차원 dp 테이블을 만들어서 풀면 된다...
*/

#include <iostream>
using namespace std;

long long dp[101][21], N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int tmp; cin >> tmp;
    dp[1][tmp] = 1;
    for(int i = 2; i < N; i++) {
        cin >> tmp;
        for(int j = 0; j <= 20; j++) {
            if(j + tmp < 21) dp[i][j + tmp] += dp[i-1][j];
            if(j - tmp > -1) dp[i][j - tmp] += dp[i-1][j]; 
        }
    }
    int stand; cin >> stand;
    cout << dp[N-1][stand];
}