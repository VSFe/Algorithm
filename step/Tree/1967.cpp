/*
Problem: 트리의 지름 (1967)
Tier: Gold 4
Detail: 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.
Commant: 한쪽에서 최장거리를 찾아낸 다음에, 그 점에서의 최장거리를 찾으면 됨.
거리는 뭐... 단순히 DFS로 풀면 됨.
일부러 1167 (트리의 지름)과 순회 방식을 다르게 함.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int V;
vector<vector<pair<int, int>>> vec(V+1);
vector<int> visited(V+1, 0);
vector<int> dist(V+1, 0);

void dfs(int num) {
    visited[num] = 1;
    for(int i = 0; i < vec[num].size(); i++) {
        pair<int, int> p = vec[num][i];
        if(visited[p.first]) continue;
        dist[p.first] = dist[num] + p.second;
        dfs(p.first);
    }
}

int main() {
    scanf("%d", &V);
    vec.reserve(V+1);
    visited.assign(V+1, 0);
    dist.assign(V+1, 0);
    for(int i = 0; i < V-1; i++) {
        int s, e, d; scanf("%d %d %d", &s, &e, &d);
        vec[s].push_back(make_pair(e, d));
        vec[e].push_back(make_pair(s, d));
    }
    dfs(1);
    int MAX = 0;
    for(int i = 1; i <= V; i++) {
        if(dist[i] > dist[MAX]) MAX = i;
    }
    visited.assign(V+1, 0);
    dist.assign(V+1, 0);
    dfs(MAX);
    for(int i = 1; i <= V; i++) {
        if(dist[i] > dist[MAX]) MAX = i;
    }
    printf("%d", dist[MAX]);
    return 0;
}