/*
Problem: 연속합 (1912)
Tier: Silver 2
Detail: n개의 정수로 이루어진 임의의 수열이 주어진다.
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
단, 수는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
여기서 정답은 12+21인 33이 정답이 된다.
Comment: LIS만 풀다가 머리가 굳어버림...
점화식을 세우라고 좀
*/

#include <stdio.h>
#include <algorithm>
using std::max;

int N, MAX = -1001;
int num[100000], sub_max[100001];
bool connected = true;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &num[i]);
    sub_max[0] = -1001;
    for(int i = 1; i < N+1; i++) {
        sub_max[i] = max(sub_max[i-1] + num[i-1], num[i-1]);
        MAX = max(MAX, sub_max[i]);
    }
    printf("%d", MAX);
}