/*
Problem: 피보나치 수의 합 (2086)
Tier: Gold 2
Detail: 제 1항과 제 2항을 1이라 하고, 제 3항부터는 앞의 두 항의 합을 취하는 수열을 피보나치(fibonacci) 수열이라고 한다. 예를 들어 제 3항은 2이며, 제 4항은 3이다.
피보나치 수열의 a번째 항부터 b번째 항까지의 합을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으므로 마지막 아홉 자리만을 구하도록 한다. 즉 1,000,000,000으로 나눈 나머지를 구하면 된다.
Comment: F1부터 FN 까지의 합은 F(N + 2) - 1.
해당 식을 활용하면 금방 해결.
*/

#include <stdio.h>

typedef long long ll;
ll N, M;
ll A[2][2] = {{0, 1}, {1, 1}}, result[2][2] = {{1, 0}, {0, 1}}, tmp[2][2];
const int divide = 1e9;

int cal_sum(int x, int y, ll A[2][2], ll B[2][2]) {
    int sum = 0;
    for(int i = 0; i < 2; i++) {
        sum+= (A[x][i] * B[i][y]) % divide;
    }
    return sum % divide;
}

void multiply(ll x[2][2], ll y[2][2]) {
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int sum = cal_sum(i, j, x, y);
            tmp[i][j] = sum;
        }
    }
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    scanf("%lld %lld", &N, &M);
    N += 1; M += 2;
    while(N != 0) {
        if(N % 2 == 0) {
            multiply(A, A);
            N /= 2;
        }
        else {
            multiply(result, A);
            N--;
        }
    }
    ll ans = result[0][1];
    A[0][0] = 0, A[0][1] = 1, A[1][0] = 1, A[1][1] = 1;
    result[0][0] = 1, result[0][1] = 0, result[1][0] = 0, result[1][1] = 1;
    while(M != 0) {
        if(M % 2 == 0) {
            multiply(A, A);
            M /= 2;
        }
        else {
            multiply(result, A);
            M--;
        }
    }
    printf("%lld", (result[0][1] + divide - ans) % divide);
    return 0;
}