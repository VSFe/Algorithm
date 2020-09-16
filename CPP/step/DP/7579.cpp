/*
Problem: 앱 (7579)
Tier: Gold 3
Detail: 현재 N개의 앱, A1, ..., AN이 활성화 되어 있다고 가정하자. 이들 앱 Ai는 각각 mi 바이트만큼의 메모리를 사용하고 있다.
또한, 앱 Ai를 비활성화한 후에 다시 실행하고자 할 경우, 추가적으로 들어가는 비용(시간 등)을 수치화 한 것을 ci 라고 하자.
이러한 상황에서 사용자가 새로운 앱 B를 실행하고자 하여, 추가로 M 바이트의 메모리가 필요하다고 하자.
즉, 현재 활성화 되어 있는 앱 A1, ..., AN 중에서 몇 개를 비활성화 하여 M 바이트 이상의 메모리를 추가로 확보해야 하는 것이다.
여러분은 그 중에서 비활성화 했을 경우의 비용 ci의 합을 최소화하여 필요한 메모리 M 바이트를 확보하는 방법을 찾아야 한다.
Comment: 냅색 같은 문제네?
*/

#include <stdio.h>
 
int n, m;
int memory[101];
int cost[101];
int dp[10001][100];
int list[10001];
 
void init()
{
    int i, j;
 
    for (i = 0; i < 10001; i++) {
        for (j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }
}
int process()
{
    int i, j, t;
    int c, mem;
 
    dp[0][0] = 0;
 
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 10000; j++) {
            if (dp[j][i - 1] >= 0) {
                c = j;
                mem = 0;
                for (t = 0; t < 2; t++) {
                    if (dp[j][i - 1] + mem> dp[c][i])    dp[c][i] = dp[j][i - 1] + mem;
                    c = j + cost[i];
                    mem = memory[i];
                }
            }
        }
    }
 
    j = 0;
    while (j <= 10000 && dp[j][n] < m)    j++;
    return j;
}
 
int main() {
    int i;
 
    scanf("%d %d", &n, &m);
 
    init();
 
    for (i = 1; i <= n; i++)        scanf("%d", &memory[i]);
    for (i = 1; i <= n; i++)         scanf("%d", &cost[i]);
 
    printf("%d\n", process());
 
    return 0;
}