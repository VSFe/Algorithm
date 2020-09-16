/*
Problem: 피보나치 수 3 (2749)
Tier: Gold 2
Detail: n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
Comment: 행렬 곱셈에서 아이디어 얻음.
분할정복이 은근 유용하네...
*/

#include <stdio.h>

long long int N;
long long int A[2][2];
long long int tmp[2][2], result[2][2];

int cal_sum(int x, int y, long long int A[2][2], long long int B[2][2]) {
    int sum = 0;
    for(int i = 0; i < 2; i++) {
        sum+= (A[x][i] * B[i][y]) % 1000000;
    }
    return sum % 1000000;
}

void multiply(long long int x[2][2], long long int y[2][2]) {
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
    scanf("%lld", &N);
    N--;
    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 1;
    result[0][0] = 1;
    result[1][1] = 1;
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
    printf("%lld", result[1][1]);
    return 0;
}