/*
Problem: 2*n 타일링 (11726)
Tier: Silver 3
Detail: 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
Comment: 
점화식: dp[x] = dp[x-1] + dp[x-2]
*/
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vec(1000);

int cal(int n) {
    if(vec[n] == 0) return vec[n] = (cal(n-1) + cal(n-2)) % 10007;
    else return vec[n];
}

int main() {
    vec[0] = 1;
    vec[1] = 2;
    int n;
    scanf("%d", &n);
    printf("%d", cal(n-1));
    return 0;
}