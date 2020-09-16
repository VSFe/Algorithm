/*
Problem: 팰린드롬 분할 (1509)
Tier: Gold 1
Detail: 세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다. 예를 들어, ABACABA를 팰린드롬으로 분할하면, {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}등이 있다.
분할의 개수의 최솟값을 출력하는 프로그램을 작성하시오.
Comment: 탑다운 말고 보텀업으로 접근.
*/

#include <iostream>
#include <string>
using namespace std;

string s;
int s_size, dp[2500];
bool is_pel[2500][2500];
const int INF = 25000;

void preprocess() {
    for(int i = 0; i < s_size; i++) is_pel[i][i] = 1;
    for(int i = 1; i < s_size; i++) {
        if(s[i - 1] == s[i]) is_pel[i - 1][i] = 1;
    }
    for(int i = 2; i < s_size; i++) {
        for(int j = 0; i + j < s_size; j++) {
            if(is_pel[j + 1][j + i - 1] && s[j] == s[j + i]) is_pel[j][j + i] = 1;
        }
    }
}

int cal_dp(int x) {
    if(x == s_size) return 0;
    if(dp[x] != 0) return dp[x];
    int &ret = dp[x], len = s_size - x;
    ret = INF;
    for(int i = 0; i < len; i++) {
        if(is_pel[x][x + i]) ret = min(ret, 1 + cal_dp(x + i + 1));
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s_size = s.size();
    preprocess();
    cout << cal_dp(0);
}