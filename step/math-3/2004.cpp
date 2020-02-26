/*
Problem: 조합 0의 개수 (2007)
Tier: Silver 2
Detail: nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.
Comment: 똑같지 뭐... 라고 생각했는데 메모리가 터진다
우리가 쓰는 편법을 써보자.
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;

int five(int s) {
    int result = 0;
    for(long long int i = 5; s / i >= 1; i *= 5) result += s / i;
    return result;
}

int two(int s) {
    int result = 0;
    for(long long int i = 2; s / i >= 1; i *= 2) result += s / i;
    return result;
}

int main () {
    scanf("%d %d", &N, &K);
    int oh = five(N) - five(K) - five(N-K);
    int yee = two(N) - two(K) - two(N-K);
    printf("%d", min(oh, yee));
    return 0;
}