/*
Problem: 숨바꼭질 2 (1697)
Tier: Gold 5
Detail: 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
Comment: 숨바꼭질 (1697)을 아주 약간 비틈.
어차피 큐로 제어하니까 시간을 쪼금 희생해서 풀면 됨.
*/

#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int bfs_num[200002][2];
queue<int> q;

int main() {
    scanf("%d %d", &N, &M);
    q.push(N);
    bfs_num[N][0] = 1, bfs_num[N][1] = 1;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        if(t + 1 <= M) {
            if(bfs_num[t + 1][0] > bfs_num[t][0] + 1 || bfs_num[t + 1][0] == 0) {
                bfs_num[t + 1][0] = bfs_num[t][0] + 1;
                bfs_num[t + 1][1] = bfs_num[t][1];
                q.push(t + 1);
            }
            else if(bfs_num[t + 1][0] == bfs_num[t][0] + 1) {
                bfs_num[t + 1][1] += bfs_num[t][1];
            }
        }
        if(t * 2 <= 2 * M) {
            if(bfs_num[t * 2][0] > bfs_num[t][0] + 1 || bfs_num[t * 2][0] == 0) {
                bfs_num[t * 2][0] = bfs_num[t][0] + 1;
                bfs_num[t * 2][1] = bfs_num[t][1];
                q.push(t * 2);
            }
            else if(bfs_num[t * 2][0] == bfs_num[t][0] + 1) {
                bfs_num[t * 2][1] += bfs_num[t][1];
            }
        }
        if(t - 1 >= 0) {
            if(bfs_num[t - 1][0] > bfs_num[t][0] + 1 || bfs_num[t - 1][0] == 0) {
                bfs_num[t - 1][0] = bfs_num[t][0] + 1;
                bfs_num[t - 1][1] = bfs_num[t][1];
                q.push(t - 1);
            }
            else if(bfs_num[t - 1][0] == bfs_num[t][0] + 1) {
                bfs_num[t - 1][1] += bfs_num[t][1];
            }
        }
    }
    printf("%d\n%d", bfs_num[M][0] - 1, bfs_num[M][1]);
    return 0;
}