/*
Problem: 1, 2, 3 더하기 (9095)
Tier: Silver 3
Detail: 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
Comment: 숫자 순서를 바꾸는걸 요구하지 않으니 너무 쉬운 문제인거시에오...
점화식: dp[x] = dp[x-1] + dp[x-2] + dp[x-3]
*/

#include <vector>
#include <stdio.h>
using namespace std;

int N;
vector<int> vec(11);

int main() {
    scanf("%d", &N);
    vec[0] = 1;
    vec[1] = 1;
    vec[2] = 2;
    for(int i = 3; i < 11; i++) {
        vec[i] = vec[i-3] + vec[i-2] + vec[i-1];
    }
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", vec[tmp]);
    }
    return 0;
}