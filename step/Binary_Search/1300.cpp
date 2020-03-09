/*
Problem: K번째 수 (1300)
Tier: Gold 4
Detail: 세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다.
이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.
배열 A와 B의 인덱스는 1부터 시작한다.
Comment: Parametric Search의 응용.
MID가 꼭 인덱스라던가, 함수의 인자가 아니어도 됨... 이런식으로 목표값이 될 수도 있다.
솔직히... 대충 풀긴 했는데 결과적으로 많은 것을 배우는 문제.
특히 Parametric Search에서 종종 나오는 망할놈의 경곗값 처리를 익힘...
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K;

int main() {
    scanf("%lld %lld", &N, &K);
    long long low = 1, high = N*N;
    long long result = -1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = 0;
        for(int i = 1; i <= N; i++) {
            cnt += min(N, mid/i);
        }
        if(cnt >= K) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("%lld", result);
    return 0;
}