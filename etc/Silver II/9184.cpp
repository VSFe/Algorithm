/*
Problem: 신나는 함수 실행 (9184)
Tier: Silver 2
Detail: 
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1
if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)
if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
이 때, w(a, b, c)의 값을 구하시오.
Comment: 메모이제이션만 적절히 사용하면 해결 될 것 같은데...
*/

#include <stdio.h>

int dp[21][21][21];

int cal(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a >= 21 || b >= 21 || c >= 21) return cal(20, 20, 20);
    if(dp[a][b][c] != -0) return dp[a][b][c];
    else if(a < b && b < c) return dp[a][b][c] = cal(a, b, c-1) + cal(a, b-1, c-1) - cal(a, b-1, c);
    else return dp[a][b][c] = cal(a-1, b, c) + cal(a-1, b-1, c) + cal(a-1, b, c-1) - cal(a-1, b-1, c-1);
}

int main() {
    while(true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) return 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, cal(a, b, c));
    }
}