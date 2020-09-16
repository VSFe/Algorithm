/*
Problem: 달이 차오른다, 가자. (1194)
Tier: Gold 1
Detail: 민식이는 지금 미로 속에 있다. 미로는 직사각형 모양이고, 여행길을 떠나기 위해 미로를 탈출하려고 한다. 미로는 다음과 같이 구성되어져있다.
    빈 곳 : 언제나 이동할 수 있다. ('.‘로 표시됨)
    벽 : 절대 이동할 수 없다. (‘#’)
    열쇠 : 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. (a - f)
    문 : 대응하는 열쇠가 있을 때만 이동할 수 있다. (A - F)
    민식이의 현재 위치 : 빈 곳이고, 민식이가 현재 서 있는 곳이다. (숫자 0)
    출구 : 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. (숫자 1)
달이 차오르는 기회를 놓치지 않기 위해서, 미로를 탈출하려고 한다. 한 번의 움직임은 현재 위치에서 수평이나 수직으로 한 칸 이동하는 것이다.
민식이가 미로를 탈출하는데 걸리는 이동 횟수의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 좌표와 갖고 있는 열쇠를 해싱해서 풂. 좌표야 50까지 있으니까 어쩔 수 없긴 한데, 열쇠 정보는 비트마스크로 풀 수 있음.
*/

#include <stdio.h>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

struct point {
    int x, y, cnt, hash;
    point() {}
    point(int _x, int _y, int _cnt, int _hash) : x(_x), y(_y), cnt(_cnt), hash(_hash) {}
};

int N, M, x, y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[50][50];

int solve() {
    queue<point> q;
    unordered_set<int> us;
    q.push({x, y, 0, x * 100 + y});
    us.insert(x * 100 + y);
    while(!q.empty()) {
        point p = q.front(); q.pop();
        int x = p.x, y = p.y, cnt = p.cnt, hash = p.hash;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] == -1 || x + dx[i] == N || y + dy[i] == -1 || y + dy[i] == M) continue;
            char tmp = map[x + dx[i]][y + dy[i]];
            int headHash = hash / 10000, tailHash = (x + dx[i]) * 100 + y + dy[i]; 

            if(tmp == '1') return cnt + 1;
            else if(tmp == '#') continue;

            else if(tmp >= 'a' && tmp <= 'f') {
                headHash |= 1 << (tmp - 'a');
            }

            else if(tmp >= 'A' && tmp <= 'F') {
                if(!(headHash & 1 << (tmp - 'A'))) continue;
            }

            if(us.find(headHash * 10000 + tailHash) != us.end()) continue;
            us.insert(headHash * 10000 + tailHash);
            q.push({x + dx[i], y + dy[i], cnt + 1, headHash * 10000 + tailHash});
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == '0') {
                x = i, y = j;
            }
        }
    }
    printf("%d", solve());
}