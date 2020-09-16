/*
Problem: 열쇠 (9328)
Tier: Gold 1
Detail: 상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다.
빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다. 상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다.
상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.
Comment: 최소 횟수 이런게 아니라 평소와 푸는 방식을 다르게 생각해야 한다.
이런 방식으로도 접근할 수 있구나... 라는걸 배운 문제 어휴
*/


#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {

    int TC; scanf("%d", &TC);
    for(int tc = 0; tc < TC; tc++) {
        int N, M, ans = 0, key = 0;
        char graph[102][102];
        bool visited[102][102];
        queue<pair<int, int>> door[27];
        queue<pair<int, int>> bfs;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                scanf(" %c", &graph[i][j]);
            }
        }
        char keys[30]; scanf("%s", keys);
        int keysSizeof = strlen(keys);
        if(strcmp(keys, "0")) {
            for(int i = 0; i < keysSizeof; i++) {
                char tmp = keys[i];
                key |= (1 << (tmp - 'a'));
            }
        }

        N += 2, M += 2;
        visited[0][0] = 1;
        bfs.push({0, 0});

        while(!bfs.empty()) {
            pair<int, int> p = bfs.front(); bfs.pop();
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    int x = p.first + dx[i], y = p.second + dy[i];
                    if(x == -1 || x == N || y == -1 || y == M) continue;
                    if(graph[x][y] == '*') continue;
                    if(visited[x][y]) continue;
                    visited[x][y] = 1;

                    if(graph[x][y] >= 'A' && graph[x][y] <= 'Z') {
                        if(key & (1 << (graph[x][y] - 'A'))) bfs.push({x, y});
                        else door[graph[x][y] - 'A'].push({x, y});
                    }

                    else if(graph[x][y] >= 'a' && graph[x][y] <= 'z') {
                        int idx = graph[x][y] - 'a';
                        key |= (1 << idx);
                        while(!door[idx].empty()) {
                            bfs.push(door[idx].front());
                            door[idx].pop();
                        }
                        bfs.push({x, y});
                    }

                    else if(graph[x][y] == '$') {
                        ans++;
                        bfs.push({x, y});
                    }

                    else bfs.push({x, y});
                }
            } 
        }
        printf("%d\n", ans);
    }
}