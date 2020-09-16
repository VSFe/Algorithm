/*
Problem: 종이의 개수(1780)
Tier: Silver 2
Detail: N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다.
우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.
    1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
    2. (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.
Comment: ㅈㄴ 귀찮지만 9등분 하면 되겠네...
*/

#include <stdio.h>

int N;
int dat[2187][2187];
int cnt_nega = 0, cnt_zero = 0, cnt_posi = 0;

void find(int x, int y, int size) {
    int sd = dat[x][y];
    bool sus = true;
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(dat[i][j] != sd) {
                sus = false;
                i = x + size;
                break;
            }
        }
    }
    if(sus) {
        if(sd == -1) cnt_nega++;
        else if(sd == 0) cnt_zero++;
        else cnt_posi++;
    }
    else {
        find(x, y, size/3);
        find(x, y + size/3, size/3);
        find(x, y + size/3*2, size/3);
        find(x + size/3, y, size/3);
        find(x + size/3, y + size/3, size/3);
        find(x + size/3, y + size/3*2, size/3);
        find(x + size/3 * 2, y, size/3);
        find(x + size/3 * 2, y + size/3, size/3);
        find(x + size/3 * 2, y + size/3*2, size/3);
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &dat[i][j]);
        }
    }
    find(0, 0, N);
    printf("%d\n%d\n%d", cnt_nega, cnt_zero, cnt_posi);
}