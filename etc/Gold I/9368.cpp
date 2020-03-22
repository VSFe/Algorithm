/*
Problem: 매수 (9368)
Tier: Gold 1
Detail:  각 조직원들에 대한 정보, 즉 그들이 요구할 돈과 변절할 확률이 주어지고, 당신이 필요한 최소한의 변절자 수가 주어질 때, 과연 이번 계획이 어느 정도의 확률로 성공할 지 계산할 수 있을까?
Comment: 외판원 문제에 갖혀있다보니 당해버린 문제...
외판원과 비슷할 수 있어도, 모든 곳을 방문하는 것이 아니기 때문에 카운트 변수와 방문 인자를 어떤 방식으로 활용하냐가 중점이 되는 문제.
*/

#define INF 10000000
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int t;

int search(int n, int visited, const vector<int> &dp) {
    if(visited == (1 << n)) return 0;
    if(dp[visited] != 1) return dp[visited];
}

int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n, c, m; scanf("%d %d %d", &n, &c, &m);
        vector<int> dp(1 << n, -1);
        vector<pair<int, int>> status(n);
        for(int j = 0; j < n; j++) {
            int a, b; scanf("%d %d", &a, &b);
            status.push_back(make_pair(a, b));
        }
    }
}