/*
Problem: 미로 탐색 (2178)
Tier: Silver 1
Detail: N×M크기의 배열로 표현되는 미로가 있다.
1 	0 	1 	1 	1 	1
1 	0 	1 	0 	1 	0
1 	0 	1 	0 	1 	1
1 	1 	1 	0 	1 	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
Comment: 괜히 쓸데 없이 MIN 만들고 처음에 그랬는데 생각해보니 걍 bfs_num 만들면 되는거 아냐? (bfs spanning tree)
그와 별개로 메모리 관리에 대한 중요성을 깨닫고 갑니다! 맨날 TLE만 났는데 MLE 처음 나니 진짜 당황함 ㅋㅋㅋ;;;
*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int graph[100][100];
int visited[100][100];
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs_num[100][100];
queue<pair<int, pair<int, int>>> q;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int tmp;
            scanf("%1d", &tmp);
            graph[i][j] = tmp;
        }
    }
    q.push(make_pair(0, make_pair(0, 1)));
    visited[0][0] = 1;
    while(!q.empty()) {
        pair<int, pair<int, int>> p = q.front(); q.pop();
        bfs_num[p.first][p.second.first] = p.second.second;
        int x = p.first, y = p.second.first;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] == N || x + dx[i] < 0 || y + dy[i] == M || y + dy[i] < 0) continue;
            if(graph[x + dx[i]][y + dy[i]] == 1 && visited[x + dx[i]][y + dy[i]] == 0) {
                q.push(make_pair(x + dx[i], make_pair(y + dy[i], p.second.second + 1)));
                visited[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
    printf("%d", bfs_num[N-1][M-1]);
    return 0;
}