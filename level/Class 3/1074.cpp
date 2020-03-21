/*
Problem: Z (1074)
Tier: Silver 1
Detail: 한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
만약, 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.
N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.
Comment: 2차원 이분탐색이라고 생각하고 푸니까 금방 풀림.
*/

#include <stdio.h>
#include <cmath>
using std::pow;

int result = 0;

int cal(int n, int r, int c) {
    if(n == 0) return 0;
    int tmp = n / 2;
    int sub = 0;
    if(r > tmp) {
        sub += tmp * tmp * 2;
        r -= tmp;
    }
    if(c > tmp) {
        sub += tmp * tmp;
        c -= tmp;
    }
    return sub + cal(tmp, r, c);
}


int main() {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    int tmp = pow(2, n);
    printf("%d", cal(tmp, r+1, c+1));
    return 0;
}