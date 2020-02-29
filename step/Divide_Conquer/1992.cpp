/*
Problem: 쿼드트리(1992)
Tier: Silver 1
Detail: 입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때
잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.
Comment: 여러 줄 입력 -> \n도 읽어들이기 때문에 getchar로 커트 수시로 해줘야함....
*/

#include <stdio.h>

int N;
char dat[64][64];

void comp(int start_x, int start_y, int end_x, int end_y) {
    char sd = dat[start_x][start_y];
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
        if(sd == '1') printf("1");
        else printf("0");
    }
    else if((end_x-start_x) * (end_y * start_y) == 4) {
        printf("(");
        for(int i = start_x; i < end_x; i++) {
            for(int j = start_y; j < end_y; j++) {
                printf("%c", dat[i][j]);
            }
        } 
        printf(")");
    }
    else {
        printf("(");
        comp(start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2);
        comp(start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y);
        comp((start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2);
        comp((start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y);
        printf(")");
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        getchar();        
        for(int j = 0; j < N; j++) {
            dat[i][j] = getchar();
        }
    }
    comp(0, 0, N, N);
}