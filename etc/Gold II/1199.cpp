/*
Problem: 오일러 회로 (1199)
Tier: Gold 2
Detail: 어느 점에서 출발하여 그래프 상에 있는 모든 간선을 지나되 한번 지난 간선은 다시 지나지 않고 출발점으로 돌아오는 회로를 오일러 회로라 한다. 단, 그래프는 양방향 그래프가 주어진다.
문제는 그래프가 주어졌을 때 오일러 회로 경로를 출력하는 것이다.
Comment: 쭉 돌고 출력하면 된다.
아니 근데 시발 리턴값 좀...
*/


#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N;
int path[1010][1010], in[1010];


void dfs(int x) {
    for(int i = 1; i <= N; i++) {
        if(path[x][i] <= 0) continue;
		while (path[x][i]) {
			path[x][i]--;
			path[i][x]--;
			dfs(i);
		}
    }
    cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/root/debug/input.txt", "r", stdin);
    #endif
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> path[i][j];
            in[i] += path[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        if(in[i] % 2) {
            cout << -1;
            return 0;
        }
    }
    dfs(1);
}