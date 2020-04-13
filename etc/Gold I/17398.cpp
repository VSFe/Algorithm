/*
Problem: 통신망 분할 (17398)
Tier: Gold 1
Detail: BOJ의 인기스타, 방송인 권욱제는 통신 회사에 취업했다. 현재 이 통신 회사는 너무나 큰 통신망을 한 지사에서 관리하느라 큰 비용을 지불하고 있었다.
그래서 회사는 최근 IT의 트렌드 중 하나인 '탈중앙화'에 편승하여, 통신망을 분할하도록 결정했다. 그래서 욱제한테 통신망을 분할 할때 발생하는 비용을 분석하도록 지시했다.
현재 회사 망에는 1번부터 N번까지 총 N개의 통신 탑이 존재하며, 통신탑 간의 연결이 M개 존재한다.
이때 회사에서는 총 Q번 통신탑 간의 연결을 제거함으로써 하나의 통신망을 여러 개의 통신망으로 분리하려고 한다. 통신망이란, 통신탑의 연결을 통해 도달 가능한 통신탑들의 집합이다.
통신탑 간의 연결 관계를 제거할 때 드는 비용은 제거한 후 통신망이 두 개로 나누어진다면 나눠진 두 개의 통신망에 속한 통신탑들의 갯수의 곱이 되며, 나누어지지 않을 경우 0이다.
Comment: 다 끊어버리고 합치면 될 것 같은데...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct connection {
    int u, v;
    bool enable;
    connection() {}
    connection(int a, int b, bool is) : u(a), v(b), enable(is) {}
};

connection cn[11];
int N, M, Q, uf[11], query[11];
long long ans = 0;

int find(int i) {
    return (uf[i] < 0) ? i : (uf[i] = find(uf[i]));
}

void un(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if(pi == pj) return;
    uf[pi] += uf[pj];
    uf[pj] = pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++) uf[i] = -1;
    for(int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        cn[i] = {x, y, 1};
    }
    for(int i = 0; i < Q; i++) {
        int tmp; cin >> tmp;
        cn[tmp].enable = 0;
        query[i] = tmp;
    }
    for(int i = 1; i <= M; i++) {
        if(cn[i].enable) un(cn[i].u, cn[i].v);
    }
    for(int i = Q - 1; i >= 0; i--) {
        int x = find(cn[query[i]].u), y = find(cn[query[i]].v);
        if(x == y) continue;
        ans += uf[x] * uf[y];
        un(x, y);
    }
    cout << ans;
}


