/*
Problem: 동전 (2293)
Tier: Silver 1
Detail: n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다. 사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
Comment: 메모리 4MB ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
일단 점화식...
위에서부터 긁어버리면 되지 않을까?
DP[동전의 종류, 금액] = DP[동전의 종류, 금액 - 해당 동전의 금액] + DP[동전의 종류, 금액]
즉, 동전을 사용하는 경우, 해당 동전을 사용하지 않는 경우로 나눠서 구분.
메모리 초과만 잡으면 될 것 같은데...
결국 보텀업으로 풀었다.
점화식은 dp[N, K] = dp[N-K, K] + dp[N-K, K-1]
*/

#include <stdio.h>

int test[10001], coin[100];
int N, K;

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &coin[i]);
    test[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = coin[i]; j <= K; j++) {
            test[j] += test[j-coin[i]];
        }
    }
    printf("%d", test[K]);
    return 0;
}