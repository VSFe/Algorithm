/*
Problem: 불우이웃돕기 (1414)
Tier: Gold 1
Detail: 다솜이는 불우이웃 돕기 활동을 하기 위해 무엇을 할지 생각했다. 마침 집에 엄청나게 많은 랜선이 있다는 것을 깨달았다. 마침 랜선이 이렇게 많이 필요 없다고 느낀 다솜이는 랜선을 지역사회에 봉사하기로 했다.
다솜이의 집에는 N개의 방이 있다. 각각의 방에는 모두 한 개의 컴퓨터가 있다. 각각의 컴퓨터는 랜선으로 연결되어 있다.
어떤 컴퓨터 A와 컴퓨터 B가 있을 때, A와 B가 서로 랜선으로 연결되어 있거나, 또 다른 컴퓨터를 통해서 연결이 되어있으면 서로 통신을 할 수 있다. 다솜이는 집 안에 있는 N개의 컴퓨터를 모두 서로 연결되게 하고 싶다.
N개의 컴퓨터가 서로 연결되어 있는 랜선의 길이가 주어질 때, 다솜이가 기부할 수 있는 랜선의 길이의 최댓값을 출력하는 프로그램을 작성하시오.
Comment: 초성체 마려운 문제.
getline으로 한줄 통째로 읽어들이고, 각 글자에 맞춰 처리해야 할 것 같음.
크루스컬보다 텍스트 처리면에서 조금 더 어려웠던 문제.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, dist;
    edge() : edge(-1, -1, 0) {}
    edge(int _u, int _v, int _dist) : u(_u), v(_v), dist(_dist) {}
    bool operator <(const edge& e) const { return dist < e.dist; }
};

int N, ans = 0, cnt = 0, total = 0, uf[101];
vector<edge> Edges;

int uf_find(int x) {
    return (uf[x] == -1) ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int p_x = uf_find(x), p_y = uf_find(y);
    if(p_x == p_y) return false;
    uf[p_y] = p_x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    string _; getline(cin, _);
    for(int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        for(int j = 0; j < s.size(); j++) {
            char c = s[j]; int len;
            if(c >= 'a' && c <= 'z') len = c - 'a' + 1;
            else if(c >= 'A' && c <= 'Z') len = c - 'A' + 27;
            else continue;
            Edges.push_back({i, j, len});
            total += len;
        }
    }
    sort(Edges.begin(), Edges.end());
    fill(uf, uf + 101, -1);
    for(int i = 0; i < Edges.size(); i++) {
        if(uf_union(Edges[i].u, Edges[i].v)) {
            ans += Edges[i].dist;
            if(++cnt == N - 1) break;
        }
    }
    if(cnt != N-1) cout << -1;
    else cout << total - ans;
}