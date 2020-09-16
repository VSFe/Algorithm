/*
Problem: 리모컨(1107)
Tier: Gold 5
Detail: 리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다.
채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 
수빈이가 지금 보고 있는 채널은 100번이다.
Comment: 진짜 진짜 브루트 포스... 다 쌩까고 모든 경우의 수 다 때려박으면 해결!!
*/

#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int dest, cnt;
int st = 0;
int MIN = 1000000;

int main() {
    scanf("%d %d", &dest, &cnt);
    for(int i = 0; i < cnt; i++) {
        int tmp;
        scanf("%d", &tmp);
        st |= (1 << tmp);
    }
    if(st & 1) MIN = abs(dest - 100);
    else MIN = min(dest + 1, abs(dest - 100));
    for (int i = 1; i <= dest; i++) {
        int tmp_st = 0;
        int i_size = log10(i) + 1;
        int i_cp = i;
        for(int j = 0; j < i_size; j++) {
            int tmp = i_cp / pow(10, i_size - 1 - j);
            tmp_st |= (1 << tmp);
            i_cp -= tmp * pow(10, i_size - 1 - j);
        }
        tmp_st &= st;
        if(tmp_st == 0) {
            MIN = min(MIN, i_size + dest - i);
        }
    }
    for (int i = dest + 1; i < 1000000; i++) {
        int tmp_st = 0;
        int i_size = log10(i) + 1;
        int i_cp = i;
        for(int j = 0; j < i_size; j++) {
            int tmp = i_cp / pow(10, i_size - 1 - j);
            tmp_st |= (1 << tmp);
            i_cp -= tmp * pow(10, i_size - 1 - j);
        }
        tmp_st &= st;
        if(tmp_st == 0) {
            MIN = min(MIN, i_size + i - dest);
        }
    }
    printf("%d", MIN);
    return 0;
}