/*
Problem: Chess Tournament (13344)
Tier: Platinum 5
Detail: Since chess is a game of skill, and not of chance, a player will always beat their opponent if their skill level is higher.
A game will result in a draw if and only if the two players’ skills are exactly equal.
However, the skill level of the players is not known. He has therefore asked you to write a program that, given a list of reported matches,
determines whether this list is consistent or not. The list is inconsistent if we can determine that at least reported match is falsely reported, otherwise it is consistent.
Comment: UF + 위상정렬
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int uf[50000], uf_rank[50000], in[50000], cnt = 0;
queue<int> q;

void un(int x, int y) {
    if(uf_rank[x] > uf_rank[y]) {
        uf[y] = x;
    } else {
        if(uf_rank[x] == uf_rank[y]) {
            uf[y] = x;
            uf_rank[x]++;
        }
        else uf[x] = y;
    }
}

int find(int x) {
    return (uf[x] == x) ? x : uf[x] = find(uf[x]);
}

int N, M;
vector<int> graph[50000];
vector<pair<int, int>> pending;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) { uf[i] = i; uf_rank[i] = i; }
    for(int i = 0; i < M; i++) {
        int x, y;
        char sign;
        cin >> x >> sign >> y;
        if(sign == '>') pending.push_back(make_pair(x, y));
        else if(sign == '<') pending.push_back(make_pair(y, x));
        else un(x, y);
    }
    for(int i = 0; i < pending.size(); i++) {
        int x = pending[i].first, y = pending[i].second;
        x = find(x), y = find(y);
        graph[x].push_back(y);
        in[y]++;
    }
    for(int i = 0; i < N; i++) {
        if(!in[i]) q.push(i);
    }
    while(!q.empty()) {
        int tmp = q.front(); q.pop();
        cnt++;
        for(int child : graph[tmp]) {
            in[child]--;
            if(!in[child]) q.push(child);
        }
    }
    if(cnt == N) cout << "consistent";
    else cout << "inconsistent";
    return 0;
}


