/*
Bellman Ford Algorithm (No. 11657)
설명은 나중에 추가하는걸로...
*/

#define INF 100000000
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<int> dist;
vector<vector<pair<int, int>>> graph;

int main() {
    scanf("%d %d", &V, &E);
    dist = vector<int>(V+1, INF);
    graph.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
    }
    dist[1] = 0;
    for(int i = 1; i <= V; i++) {
        int size = graph[i].size();
        for(int j = 0; j < size; j++) {
            pair<int, int> v = graph[i][j];
            if(dist[v.second] > dist[i] + v.first) dist[v.second] = dist[i] + v.first;
        }
    }
    // 음수 사이클 존재 여부 판단
    bool is_negacycle = false;
    for(int i = 1; i <= V; i++) {
        int size = graph[i].size();
        for(int j = 0; j < size; j++) {
            pair<int, int> v = graph[i][j];
            if(dist[v.second] > dist[i] + v.first) {
                is_negacycle = true;
                i = V;
                break;
            }
        }
    }
    if(is_negacycle) printf("-1");
    return 0;
}