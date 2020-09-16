/*
Problem: 가장 긴 증가하는 부분 수열 2 (12015)
Tier: Gold 2
Detail: 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은
A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
Comment: DAY 하루를 날려먹은... 문제
*/

#include <stdio.h>

int N;
int IDX = 0;
int data[1000000], result[1000001];

int bs(int val, int start, int end) {
    if(start == end) return end;
    int mid = (start + end) / 2;
    if(result[mid] < val) return bs(val, mid + 1, end);
    else return bs(val, start, mid);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &data[i]);
    result[0] = 0;
    for(int i =0; i < N; i++) {
        if(result[IDX] < data[i]) result[++IDX] = data[i];
        else {
            int tmp = bs(data[i], 1, IDX);
            if(result[tmp] > data[i]) result[tmp] = data[i]; 
        }
    }
    printf("%d", IDX);
    return 0;
}