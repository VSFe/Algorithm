/*
Problem: 토마토 (7576)
Tier: Silver 1
Detail: 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며,
토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때,
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
Comment: 코드 구조를 바꾸면서, 마지막 카운트 출력 부분이 중요하게 되었는데, 정확히 어떤 부분에서 순회가 종료되었는지 판단하기 어렵기 때문에 걍 하나 빼고 다 뽑아버렸다.
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int graph[1000][1000];
int visited[1000][1000];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt;
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            scanf("%d", &tmp);
            graph[i][j] = tmp;
            if(tmp == 1) {
                cnt++;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            else if(tmp == -1) cnt++;
        }
    } 
    if(cnt == n * m) {
        printf("0");
        return 0;
    }
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i], new_y = y + dy[i];
            if(new_x == m || new_x < 0 || new_y == n || new_y < 0) continue;
            if(graph[new_x][new_y] == 0 && visited[new_x][new_y] == 0) {
                visited[new_x][new_y] = visited[x][y] + 1;
                q.push(make_pair(new_x, new_y));
                cnt++;
            }
        }
        if(cnt == n * m) {
            int size = q.size();
            for(int i = 0; i < size - 1; i++) q.pop();
            printf("%d", visited[q.front().first][q.front().second] - 1);
            break;
        }
    }
    if(cnt != n * m) printf("-1");
    return 0;
}
