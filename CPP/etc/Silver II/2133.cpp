/*
Problem: 타일 채우기(2133)
Tier: Silver 2
Detail: 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
Comment: 2*3 인 경우: 가능한 케이스가 단 두개! (이거는 어차피 꼭 들어갈거고...)
반 강제로 연장하는 케이스: 4*3, 6*3... 이거는 이거 따로 2개씩
생각을 해보면 애초에 이거 홀수는 불가인데?
DP[N] = DP(N-2) * 6 + DP(N-4) * 4 + DP(N-6) * 4 ...
*/

#include <stdio.h>

int gap[15];

int cal(int n) {
    if(gap[n] != 0) return gap[n];
    int sum = 0;
    sum += cal(n-1) * 3;
    for(int i = 0; i < n-1; i++) {
        if(gap[i] == 0) gap[i] = cal(i);
        sum += gap[i] * 2;
    }
    return sum + 2;
}

int main() {
    int n;
    scanf("%d", &n);
    gap[0] = 3;
    if(n % 2 == 1) printf("0");
    else printf("%d", cal(n/2 - 1));
    return 0;
}