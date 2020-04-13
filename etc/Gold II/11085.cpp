/*
Problem: 군사 이동 (11085)
Tier: Gold 2
Detail: 전쟁 당시 Baekjoon World의 국왕은 Cube World를 공격할 작전을 세운 적이 있습니다. Baekjoon World와 Cube World는 p개의 지점과 w개의 길로 표현됩니다.
모든 길은 양방향이며, 각 길마다 너비가 존재하여 이에 비례하는 수의 군사가 지나갈 수 있습니다.
Baekjoon World의 국왕은 군사들이 뭉치는 것이 유리하다고 생각해서, 미리 Cube World로 가는 경로를 정해 두고 그 경로로만 모든 군사를 보냈습니다.
Baekjoon World의 국왕은 총명해서, 경로 상에 있는 길 중 너비가 가장 좁은 길의 너비를 최대화하는 경로를 택했습니다.
그런데 전쟁 때문에 어느 길로 보냈는지에 대한 기록이 불타 없어져 버렸습니다. 전쟁사를 완성하려면 이 기록이 꼭 필요합니다. 위대한 과학자인 당신이 다시 복구해 주세요.
Comment: 저는 과학자가 아닌데요?
유니언 파인드 문제라고 했지만 그리디로 풀기 위해 다익스트라 알고리즘을 일부 수정해서 해결함.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge{
    int to, dist;
    edge() {}
    edge(int a, int b) : to(a), dist(b) {}
    bool operator<(const edge ed) {

    }
};

bool operator< (const edge &e1, const edge &e2) {
    if(e1.dist == e2.dist) return e1.to < e2.to;
    else return e1.dist < e2.dist;  
}

int V, E, Baek, Cube, MIN = 1000, included[1000];
vector<edge> vec[1000];
priority_queue<edge> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E >> Baek >> Cube;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    pq.push({Baek, 1000});
    while(!included[Cube]) {
        edge tmp = pq.top(); pq.pop();
        if(included[tmp.to]) continue;
        MIN = min(MIN, tmp.dist);
        for(auto next : vec[tmp.to]) {
            if(!included[next.to]) {
                pq.push(next);
            }
        }
        included[tmp.to] = 1;
    }
    cout << MIN;
}


