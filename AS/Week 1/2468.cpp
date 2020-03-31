/*
Problem: 안전 영역 (2468)
Tier: Silver 1
Detail: 
재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 먼저 어떤 지역의 높이 정보를 파악한다. 그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다.
이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.
어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다. 
어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오. 
Comment: 플러드 필 N회
*/

#include <iostream>
#include <cstring>
using namespace std;

int graph[101][101], visited[101][101];
int N; 

void dfs(int x, int y, int standard) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 1 || x + dx[i] > N || y + dy[i] < 1 || y + dy[i] > N) continue;
        if(graph[x+dx[i]][y+dy[i]] > standard && visited[x+dx[i]][y+dy[i]] == 0) {
            dfs(x + dx[i], y + dy[i], standard);
        }
    }
}

int floodfill(int standard) {
    memset(visited, 0, sizeof(visited));
    int result = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(visited[i][j] == 0 && graph[i][j] > standard) {
                result++;
                dfs(i, j, standard);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }
    int cnt = 0, MAX = -1;
    while(true) {
        int tmp = floodfill(cnt++);
        if(tmp == 0) break;
        else MAX = max(MAX, tmp);
    }
    cout << MAX;
    return 0;
}

