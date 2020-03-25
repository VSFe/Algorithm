/*
Problem: 숨바꼭질 (13913)
Tier: Gold 4
Detail: 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
Comment: 배열을 하나 늘려서 역으로 추적 하면 됨.
*/

#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int bfs_num[200002][2];
queue<int> q;
vector<int> vec;

int main() {
    for(int i = 0; i < 200002; i++) { for(int j = 0; j < 2; j++) bfs_num[i][j] = -1; }
    scanf("%d %d", &N, &M);
    q.push(N);
    bfs_num[N][0] = 1;
    while(bfs_num[M][0] == -1) {
        int t = q.front(); q.pop();
        if(t + 1 <= M && bfs_num[t + 1][0] == -1) {
            bfs_num[t + 1][0] = bfs_num[t][0] + 1;
            bfs_num[t + 1][1] = t;
            q.push(t+1);
        }  
        if(t * 2 < 2 * M && bfs_num[t * 2][0] == -1) {
            bfs_num[t * 2][0] = bfs_num[t][0] + 1;
            bfs_num[t * 2][1] = t;
            q.push(t*2);
        }
        if(t - 1 >= 0 && bfs_num[t - 1][0] == -1) {
            bfs_num[t - 1][0] = bfs_num[t][0] + 1;
            bfs_num[t - 1][1] = t;
            q.push(t-1);
        }
    }
    printf("%d\n", bfs_num[M][0] - 1);
    vec.reserve(bfs_num[M][0]);
    int result = M;
    while(result != -1) {
        vec.push_back(result);
        result = bfs_num[result][1];
    }
    for(int i = vec.size() - 1; i >= 0; i--) printf("%d ", vec[i]);
    return 0;
}