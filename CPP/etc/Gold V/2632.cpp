/*
Problem: 줄세우기 (2631)
Tier: Gold 5
Detail:KOI 어린이집에는 N명의 아이들이 있다. 오늘은 소풍을 가는 날이다. 선생님은 1번부터 N번까지 번호가 적혀있는 번호표를 아이들의 가슴에 붙여주었다.
선생님은 아이들을 효과적으로 보호하기 위해 목적지까지 번호순서대로 일렬로 서서 걸어가도록 하였다. 이동 도중에 보니 아이들의 번호순서가 바뀌었다.
그래서 선생님은 다시 번호 순서대로 줄을 세우기 위해서 아이들의 위치를 옮기려고 한다.
그리고 아이들이 혼란스러워하지 않도록 하기 위해 위치를 옮기는 아이들의 수를 최소로 하려고 한다.
Comment: LIS를 구한 다음에 전체 길이 - LIS 길이 빼면 답.
*/

#include <stdio.h>

int N;
int IDX = 0;
int data[201], result[201];

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
    printf("%d", N - IDX);
    return 0;
}