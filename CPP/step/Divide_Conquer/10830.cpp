/*
Problem: 행렬 제곱 (10830)
Tier: Gold 4
Detail: 크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니,
A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.
Comment:
쉬트라센 알고리즘 (Strassen Algorithm)이 있는데... 안 쓰고도 풀 수 있나?
사실 앞에서 봤던 곱셉 문제의 응용.
*/

#include <stdio.h>

int N;
long long int K;
long long int A[5][5];
long long int tmp[5][5], result[5][5];

int cal_sum(int x, int y, long long int A[5][5], long long int B[5][5]) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum+= (A[x][i] * B[i][y]) % 1000;
    }
    return sum % 1000;
}

void multiply(long long int x[5][5], long long int y[5][5]) {
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int sum = cal_sum(i, j, x, y);
            tmp[i][j] = sum;
        }
    }
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    scanf("%d %lld", &N, &K);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%lld", &A[i][j]);
        }
        result[i][i] = 1;
    }
    while(K != 0) {
        if(K % 2 == 0) {
            multiply(A, A);
            K /= 2;
        }
        else {
            multiply(result, A);
            K--;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%lld ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}