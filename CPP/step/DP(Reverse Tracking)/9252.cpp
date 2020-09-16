/*
Problem: LCS2 (9252)
Tier: Gold 5
Detail: LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
Comment: 그렇게 하면 얼추 DP는 될듯?
근데 만들고 보니 딱히 DP... 같지는 않고... 역추적 하라고 둔 것 같음.
LCS: 서로 하나씩 글자를 늘리면서 만나는 거니, DP 테이블에서 1 추가하는 기준은 대각선 위...
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string str1, str2, str3 = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size();
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int x = len1, y = len2;
    while(str3.size() != dp[len1][len2]) {
        if(max(dp[x-1][y], dp[x][y-1]) == dp[x][y]) {
            if(dp[x-1][y] >= dp[x][y-1]) x--;
            else y--;
        }
        else {
            str3 += str1[x-1];
            x--; y--;
        }  
    }

    cout << dp[len1][len2] << '\n';
    for(int i = str3.size() - 1; i != -1; i--) cout << str3[i];
    return 0;
}