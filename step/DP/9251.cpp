/*
Problem: LCS (9251)
Tier: Gold 5
Detail: 
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
Comment: 공간복잡도를 조금 감수합시다...
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N1, N2;
string s1, s2;
int gap[1001][1000];

int main() {
    cin >> s1 >> s2;
    N1 = s1.length();
    N2 = s2.length();
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N2; j++) {
            if(s1[i] == s2[j]) gap[i+1][j] = gap[i][j-1] + 1;
            else gap[i+1][j] = max(gap[i][j], gap[i+1][j-1]);
        }
    }
    printf("%d", gap[N1][N2-1]);
}