/*
Problem: 빵집
Tier: Gold 2
Detail: 유명한 제빵사 김원웅은 빵집을 운영하고 있다. 원웅이의 빵집은 글로벌 재정 위기를 피해가지 못했고, 결국 심각한 재정 위기에 빠졌다.
원웅이는 지출을 줄이고자 여기저기 지출을 살펴보던 중에, 가스비가 제일 크다는 것을 알게되었다. 따라서 원웅이는 근처 빵집의 가스관에 몰래 파이프를 설치해 훔쳐서 사용하기로 했다.
빵집이 있는 곳은 R*C 격자로 표현할 수 있다. 첫째 열은 근처 빵집의 가스관이고, 마지막 열은 원웅이의 빵집이다.
원웅이는 가스관과 빵집을 연결하는 파이프를 설치하려고 한다. 빵집과 가스관 사이에는 건물이 있을 수도 있다. 건물이 있는 경우에는 파이프를 놓을 수 없다.
가스관과 빵집을 연결하는 모든 파이프라인은 첫째 열에서 시작해야 하고, 마지막 열에서 끝나야 한다. 각 칸은 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 연결할 수 있고, 각 칸의 중심끼리 연결하는 것이다.
원웅이는 가스를 되도록 많이 훔치려고 한다. 따라서, 가스관과 빵집을 연결하는 파이프라인을 여러 개 설치할 것이다. 이 경로는 겹칠 수 없고, 서로 접할 수도 없다. 즉, 각 칸을 지나는 파이프는 하나이어야 한다.
원웅이 빵집의 모습이 주어졌을 때, 원웅이가 설치할 수 있는 가스관과 빵집을 연결하는 파이프라인의 최대 개수를 구하는 프로그램을 작성하시오.
Comment: 재밌는 그리디 문제.
경로가 최대한 안 겹치게 하려면 위에서부터 올라가면 된다.
dp처럼 기록하는건 좋은 방법이었다는걸 깨달음.
꼭 백트래킹이라고 이전 상태로 완전히 돌아가야 하는건 아니라는 걸 깨달음...
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int N, M, cnt = 0, graph[10001][501];
int dt[3] = {-1, 0, 1};

bool get_ans(int x, int y) {
    graph[x][y] = 1;
    if(y == M - 1) {
        cnt++;
        return true;
    }
    bool is_ok = false;
    for(int i = 0; i < 3; i++) {
        if(x + dt[i] == -1 || x + dt[i] == N) continue;
        if(!graph[x + dt[i]][y + 1]) {
            is_ok = get_ans(x + dt[i], y + 1);
            if(is_ok) break;
        }
    }
    return is_ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/root/debug/input.txt", "r", stdin);
    #endif
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char t; cin >> t;
            if(t == 'x') graph[i][j] = 1;
        }
    }
    for(int i = 0; i < N; i++) {
        if(!graph[i][0]) get_ans(i, 0);
    }
    cout << cnt;
}