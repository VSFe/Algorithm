/*
Problem: 숫자 맞추기 (2494)
Tier: Gold 1
Detail:  N개의 회전이 가능한 숫자 나사가 아래위로 연결되어 있다. 가장 위에 있는 숫자나사는 숫자나사 1이고 가장 아래에 있는 숫자나사는 숫자나사 N이다.
모든 숫자나사는 각각 10개의 면을 가지고 있고, 각 면에는 오른쪽 방향으로 0, 1, 2, 3, …, 9까지의 숫자가 하나씩 순서대로 적혀 있다.
하나의 숫자나사를 왼쪽으로 회전 시키면, 이 나사보다 아래에 위치한 모든 나사는 같이 따라서 돌게 되지만, 나사를 오른쪽으로 회전시키면, 다른 나사는 함께 돌지는 않는다.
정면에서 보아 위에서부터 아래쪽으로 숫자를 읽어 내려간다고 할 때, 현재의 상태에서 가장 적은 칸수의 움직임으로 원하는 숫자를 만들기 위한 방법을 출력하는 프로그램을 작성하라.
예를 들어 세 개의 숫자나사가 주어졌을 때, 정면에서 보는 현재 상태가 326이고 원하는 상태는 446이라면 최소 회전 칸수는 4이다.
먼저 숫자나사 1을 왼쪽으로 한 칸 돌리면 437이 되고, 숫자나사 2를 역시 왼쪽으로 한 칸 돌리면 448이 되며, 마지막으로 숫자나사 3을 오른쪽으로 두 칸 돌리면 446이 된다.
Comment: 숫자가 10000자... -> int [10000] 으로 받아야 할 듯 함.
문제 좀 똑바로 읽어엄ㄴ오ㅜㅁ너윰ㅇ륨너ㅏ류ㅗㄴ멀나ㅓ륨ㄴ어류ㅓㄴ뮬어류ㅏㅁ뉴ㅓ뉴러ㅏㅁ뉼머뉴ㅗㅓ
*/

#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int D[10001][10], From[10001], To[10001];
int Dir[10001][10], Cost[10001][10], N;

int cal_dp(int idx, int turn) {
    if (idx == N) return 0;
 
    int& ret = D[idx][turn];
    if (ret != -1) return ret;
 
    int cur = (From[idx] + turn)%10;
 
    //left
    int leftTurn = (To[idx] - cur + 10) % 10;
    int leftCostSum = cal_dp(idx + 1, (turn + leftTurn) % 10) + leftTurn;
 
    //right
    int rightTurn = (cur - To[idx] + 10) % 10;
    int rightCostSum = cal_dp(idx + 1, turn) + rightTurn;
 
    if (rightCostSum > leftCostSum) {
        ret = leftCostSum;
        Dir[idx][turn] = 1;
        Cost[idx][turn] = leftTurn;
    }
    else {
        ret = rightCostSum;
        Dir[idx][turn] = -1;
        Cost[idx][turn] = rightTurn;
    }
 
    return ret;
}

void tracking(int idx, int turn) {
    if (idx == N) return;
 
    int move = Dir[idx][turn] * Cost[idx][turn];
 
    if (move != 0) printf("%d %d\n", idx + 1, move);
    if (Dir[idx][turn] > 0) tracking(idx + 1, (turn + move + 10) % 10);
    else tracking(idx + 1, turn);
}

int main() {
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++) scanf("%1d", &From[i]);
    for (int i = 0; i < N; i++) scanf("%1d", &To[i]);
 
    memset(D, -1, sizeof(D));
    printf("%d\n", cal_dp(0,0));
    tracking(0, 0);
 
    return 0;
}


