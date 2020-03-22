/*
Problem: 트리의 지름 (1167)
Tier: Gold 3
Detail: 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.
Commant: 한쪽에서 최장거리를 찾아낸 다음에, 그 점에서의 최장거리를 찾으면 됨.
거리는 뭐... 단순히 BFS를 돌리던지 하면 됨.
그래프로 생각해도 될 것 같은데?
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int V;
queue<int> q;

int main() {
    scanf("%d", &V);
    vector<vector<pair<int, int>>> vec(V+1);
    vector<int> visited(V+1, 0);
    vector<int> dist(V+1, 0);
    for(int i = 0; i < V; i++) {
        int S; scanf("%d", &S);
        while(true) {
            int t1, t2;
            scanf("%d", &t1);
            if(t1 == -1) break;
            scanf("%d", &t2);
            vec[S].push_back(make_pair(t1, t2));
        }
    }
    q.push(1); visited[1] = 1;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(int i = 0; i < vec[t].size(); i++) {
            pair<int, int> tmp = vec[t][i];
            if(visited[tmp.first])  continue;
            dist[tmp.first] = dist[t] + tmp.second;
            q.push(tmp.first); visited[tmp.first] = 1;
        }
    }
    int MAX = 0;
    for(int i = 1; i <= V; i++) {
        if(dist[i] > dist[MAX]) MAX = i;
    }
    visited.assign(V+1, 0);
    dist.assign(V+1, 0);
    q.push(MAX); visited[MAX] = 1;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(int i = 0; i < vec[t].size(); i++) {
            pair<int, int> tmp = vec[t][i];
            if(visited[tmp.first])  continue;
            dist[tmp.first] = dist[t] + tmp.second;
            q.push(tmp.first); visited[tmp.first] = 1;
        }
    }
    for(int i = 1; i <= V; i++) {
        if(dist[i] > MAX) MAX = dist[i];
    }
    printf("%d", MAX);
    return 0;
}