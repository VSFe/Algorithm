/*
Problem: 색종이 만들기(2630)
Tier: Silver 3
Detail: 입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때
잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.
Comment: 쉬운 분할정복 문제. 어디서 쪼갤지만 눈치채면 쉽게 풀리는 듯.
*/

#include <stdio.h>

int N;
int dat[128][128];
int cnt_blue = 0, cnt_white = 0;

void find(int start_x, int start_y, int end_x, int end_y) {
    int sd = dat[start_x][start_y];
    bool sus = true;
    for(int i = start_x; i < end_x; i++) {
        for(int j = start_y; j < end_y; j++) {
            if(dat[i][j] != sd) {
                sus = false;
                i = end_x;
                break;
            }
        }
    }
    if(sus) {
        if(sd) cnt_blue++;
        else cnt_white++;
    }
    else {
        find(start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2);
        find(start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y);
        find((start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2);
        find((start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &dat[i][j]);
        }
    }
    find(0, 0, N, N);
    printf("%d\n%d", cnt_white, cnt_blue);
}