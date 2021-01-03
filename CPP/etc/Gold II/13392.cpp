/*
Problem: 방법을 출력하지 않는 숫자 맞추기
Tier: Gold 2
Detail: N개의 회전이 가능한 숫자 나사가 아래위로 연결되어 있다. 가장 위에 있는 숫자나사는 숫자나사 1이고 가장 아래에 있는 숫자나사는 숫자나사 N이다.
모든 숫자나사는 각각 10개의 면을 가지고 있고, 각 면에는 오른쪽 방향으로 0, 1, 2, 3, …, 9까지의 숫자가 하나씩 순서대로 적혀 있다.
하나의 숫자나사를 왼쪽으로 회전 시키면, 이 나사보다 아래에 위치한 모든 나사는 같이 따라서 돌게 되지만, 나사를 오른쪽으로 회전시키면, 다른 나사는 함께 돌지는 않는다.
정면에서 보아 위에서부터 아래쪽으로 숫자를 읽어 내려간다고 할 때, 현재의 상태에서 가장 적은 칸수의 움직임으로 원하는 숫자를 만들기 위한 방법을 출력하는 프로그램을 작성하라.
예를 들어 세 개의 숫자나사가 주어졌을 때, 정면에서 보는 현재 상태가 326이고 원하는 상태는 446이라면 최소 회전 칸수는 4이다.
먼저 숫자나사 1을 왼쪽으로 한 칸 돌리면 437이 되고, 숫자나사 2를 역시 왼쪽으로 한 칸 돌리면 448이 되며, 마지막으로 숫자나사 3을 오른쪽으로 두 칸 돌리면 446이 된다.
Comment: 왼쪽과 오른쪽으로 나눠서 돌리면 편-인
*/

#include <iostream>
#include <cstring>
using namespace std;

int N;
string start, target;
int dp[10][10001];

int CalDP(int x, int idx) {
    if(idx == N) return 0;
    int &ret = dp[x][idx];
    if(ret != -1) return ret;

    int number = (int(start[idx] - '0') + x) % 10;
    int target_number = int(target[idx] - '0');
    int left = target_number > number ? target_number - number: target_number - number + 10;
    int right = target_number > number ? number - target_number + 10 : number - target_number;
    ret = 100000;

    ret = min(ret, CalDP((x + left) % 10, idx + 1) + left);
    ret = min(ret, CalDP(x, idx + 1) + right);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> start >> target;
    memset(dp, -1, sizeof(dp));
    cout << CalDP(0, 0);
}