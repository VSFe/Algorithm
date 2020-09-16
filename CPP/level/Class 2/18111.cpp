/*
Problem: 마인크래프트 (18111)
Tier: Silver 3
Detail: 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다. 우리는 다음과 같은 두 종류의 작업을 할 수 있다.
    좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
    인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다.
‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.
단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다.
땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.
Comment: 충분히 브루트 포스로 풀만한 문제.
근데 그건 그렇다 쳐도 진짜 코드 리뷰 실력 개판이다 어떡하냐...
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int x, y, item;
int stage[501][501];
int min_time = 128e6+10, max_height = -1;

int main() {
    scanf("%d %d %d", &x, &y, &item);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            scanf("%d", &stage[i][j]);
        }
    }
    for(int i = 0; i <= 256; i++) {
        int tmp_item = item, time = 0;
        for(int j = 0; j < x; j++) {
            for(int k = 0; k < y; k++) {
                if(stage[j][k] > i) {
                    time += (stage[j][k] - i) * 2;
                    tmp_item += (stage[j][k] - i);
                }
                else if(stage[j][k] < i) {
                    int tmp = i - stage[j][k];
                    tmp_item -= tmp;
                    time += tmp;
                }
            }
        }
        if(tmp_item >= 0 && min_time >= time) {
                min_time = min(min_time, time);
                max_height = i;
        }
    }
    printf("%d %d", min_time, max_height);
    return 0;
}
