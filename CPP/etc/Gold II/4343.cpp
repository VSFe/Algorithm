/*
Problem: Arctic Network (4343)
Tier: Gold 2
Detail: The Department of National Defence (DND) wishes to connect several northern outposts by a wireless network.
Two different communication technologies are to be used in establishing the network
every outpost will have a radio transceiver and some outposts will in addition have a satellite channel.
Any two outposts with a satellite channel can communicate via the satellite, regardless of their location.
Otherwise, two outposts can communicate by radio only if the distance between them does not exceed D, which depends of the power of the transceivers.
Higher power yields higher D but costs more. Due to purchasing and maintenance considerations, the transceivers at the outposts must be identical
that is, the value of D is the same for every pair of outposts.
Your job is to determine the minimum D required for the transceivers. There must be at least one communication path (direct or indirect) between every pair of outposts.
Comment: 일반적인 크루스컬 알고리즘으로 진행하되, 다음과 같은 절차를 진행한다.
1. MST에 속하는 모든 간선을 따로 보관한다.
2. 간선의 길이가 큰 순서대로 다시 체크하면서, 그 과정에서 새로운 uf를 하나 만들어주고, 병합한다.
병합하는 원소의 수가 위성 통신망 수에 도달하면 현재 간선의 최댓값 리턴.
만들어질 수 있는 간선의 수는 최대 124750개로, 충분히 할만함.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
    int x, y;
    node() : node(0, 0) {}
    node(int _x, int _y) : x(_x), y(_y) {}
};

struct edge {
    int u, v;
    double dist;
    edge() : edge(-1, -1, 0) {}
    edge(int _u, int _v, double _dist) : u(_u), v(_v), dist(_dist) {}
    bool operator <(const edge& e) const { return dist < e.dist; }
};

int N, M, uf_1[501], uf_2[501];
double MAX;
edge Edges[200001];
node Node[501];
vector<edge> vec;

int uf_find(int uf[], int x) {
    return (uf[x] == -1) ? x : uf[x] = uf_find(uf, uf[x]);
}

bool uf_union(int uf[], int x, int y) {
    int p_x = uf_find(uf, x), p_y = uf_find(uf, y);
    if(p_x == p_y) return false;
    uf[p_y] = p_x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
    int total = 0, cnt = 0;
    vec.clear();
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        Node[i] = node(x, y);
    }
    for(int i = 0; i < M; i++) {
        for(int j = i + 1; j < M; j++) {
            double dist = sqrt(pow(Node[i].x - Node[j].x, 2) + pow(Node[i].y - Node[j].y, 2));
            Edges[total++] = edge(i, j, dist);
        }
    }
    fill(uf_1, uf_1 + M, -1);
    fill(uf_2, uf_2 + M, -1);
    sort(Edges, Edges + total);
    for(int i = 0; ; i++) {
        if(uf_union(uf_1, Edges[i].u, Edges[i].v)) {
            vec.push_back(Edges[i]);
            if(++cnt == M-1) break;
        }
    }
    double ans = vec.back().dist;
    N--;
    for(int i = vec.size() - 1; i >= 0 ; i--) {
        if(!N) break;
        if(uf_union(uf_2, vec[i].u, vec[i].v)) {
            N--;
            ans = vec[i-1].dist;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans << '\n';
}
}