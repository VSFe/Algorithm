/*
Problem: 팰린드롬 분할 (1509)
Tier: Gold 1
Detail: 세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다. 예를 들어, ABACABA를 팰린드롬으로 분할하면, {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}등이 있다.
분할의 개수의 최솟값을 출력하는 프로그램을 작성하시오.
Comment: 완전히 탑다운으로 해결하려고 하니 오버헤드가 너무 많이 발생...
그래도 차근차근 접근하면 풀린다.
*/

#include <iostream>
#include <string>
using namespace std;

string s;
int s_size, dp[2500][2500];
const int INF = 25000;

bool is_pel(int x, int y) {
    while(x < y) {
        if(s[x] != s[y]) return false;
        x++; y--;
    }
    return true;
}

int cal_dp(int x, int len) {
    if(s_size - 1 == x) {
        if(len == 1 || is_pel(x - len + 1, x)) return 1;
        else return INF;
    }
    int &ret = dp[x][len];
    if(ret != -1) return ret;
    ret = INF;
    if(len == 1 || is_pel(x - len + 1, x)) {
        ret = min(ret, 1 + cal_dp(x + 1, 1));
    }
    ret = min(ret, cal_dp(x + 1, len + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s_size = s.size();
    fill(&dp[0][0], &dp[2499][2499], -1);
    cout << cal_dp(0, 1);
}