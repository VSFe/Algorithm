/*
Problem: 숨바꼭질 3 (13549)
Tier: Gold 5
Detail: 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
Comment: 숨바꼭질 (1697)을 아주 약간 비틈.
2배 할 때 안 더한다는것만 알면 될 듯.
*/

#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int bfs_num[200002];
queue<int> q;

int main() {
    scanf("%d %d", &N, &M);
    q.push(N);
    bfs_num[N] = 1;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        if(t + 1 <= M && (bfs_num[t + 1] == 0 || bfs_num[t + 1] > bfs_num[t])) {
            bfs_num[t + 1] = bfs_num[t] + 1;
            q.push(t+1);
        }  
        if(t * 2 < 2 * M && (bfs_num[t * 2] == 0 || bfs_num[t * 2] > bfs_num[t])) {
            bfs_num[t * 2] = bfs_num[t];
            q.push(t*2);
        }
        if(t - 1 >= 0 && (bfs_num[t - 1] == 0 || bfs_num[t - 1] > bfs_num[t])) {
            bfs_num[t - 1] = bfs_num[t] + 1;
            q.push(t-1);
        }
    }
    printf("%d", bfs_num[M] - 1);
    return 0;
}