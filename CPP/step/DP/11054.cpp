/*
Problem: 가장 긴 바이토닉 부분수열 (11054)
Tier: Gold 3
Detail: 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면,
그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
Comment: 시간복잡도가 여유 있으니 뒤집어서 풀면 될 것 같긴 함...
*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
int MAX = 0;
int d[1000], d_re[1000];

int bs(int result[1001], int val, int start, int end) {
    if(start == end) return end;
    int mid = (start + end) / 2;
    if(result[mid] > val) return bs(result, val, mid + 1, end);
    else return bs(result, val, start, mid);
}

int search_lis(int data[1000], int index) {
    int IDX = 0, result[1001];
    result[0] = 1001;
    for(int i = index; i < N; i++) {
        if(result[IDX] > data[i]) result[++IDX] = data[i];
        else {
            int tmp = bs(result, data[i], 1, IDX);
            if(result[tmp] < data[i]) result[tmp] = data[i]; 
        }
    }
    return IDX;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &d[i]);
    for(int i = 0; i < N; i++) d_re[N-1-i] = d[i];
    for(int i = 0; i < N; i++) {
        int tmp = search_lis(d, i) + search_lis(d_re, N-1-i);
        MAX = max(MAX, tmp);
    }
    printf("%d", MAX - 1);
    return 0;
}