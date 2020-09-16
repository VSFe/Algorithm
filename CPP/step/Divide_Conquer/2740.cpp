/*
Problem: 행렬 곱셈(2740)
Tier: bronze 1
Detail: N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.
Comment: 행렬곱 공식을 떠올리면 그냥 풀림.
*/

#include <stdio.h>

int N, M, K;
int A[100][100], B[100][100];
int multi[100][100];

int cal_sum(int x, int y) {
    int sum = 0;
    for(int i = 0; i < M; i++) {
        sum+= A[x][i] * B[i][y];
    }
    return sum;
}

void multiply() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            int sum = cal_sum(i, j);
            multi[i][j] = sum;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &M, &K);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    multiply();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
    return 0;
}