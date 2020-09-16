/*
Problem: 단지번호붙이기 (2667)
Tier: Silver 1
Detail:  <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
Comment: 삼삼한 Flood Fill 문제...
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int visited[25][25];
int graph[25][25];
int cnt = 0;
int N;
vector<int> house;

void travel(int x, int y) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    visited[x][y] = 1;
    house[cnt-1]++;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] == N || y + dy[i] < 0 || y + dy[i] == N) continue;
        if(graph[x+dx[i]][y+dy[i]] == 1 && visited[x+dx[i]][y+dy[i]] == 0) {
            travel(x + dx[i], y + dy[i]);
        }
    }

}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int c;
            scanf("%1d", &c);
            graph[i][j] = c;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                house.push_back(0);
                travel(i, j);
            }
        }
    }
    printf("%d\n", cnt);
    sort(house.begin(), house.end());
    for(int i = 0; i < cnt; i++) printf("%d\n", house[i]);
    return 0;
}