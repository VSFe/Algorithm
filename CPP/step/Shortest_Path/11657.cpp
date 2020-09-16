/*
Problem: 타임머신
Tier: Gold 4
Detail: N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다.
각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다.
C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.
Comment: 가중치에 음수가 있음 -> 다익스트라는 안되겠네...
M이 작음 -> 벨만포드네!
백준 특징: 출력 초과가 진짜 초과만을 의미하는게 아님....
적을수도 있다!!!!
*/

#define INF 200000000
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<long long> dist;
vector<vector<pair<int, int>>> graph;

int main() {
    scanf("%d %d", &V, &E);
    dist = vector<long long>(V+1, INF);
    graph.reserve(V+1);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
    }
    dist[1] = 0;
    for(int s = 0; s < V-1; s++) {
        for(int i = 1; i <= V; i++) {
            int size = graph[i].size();
            for(int j = 0; j < size; j++) {
                pair<int, int> v = graph[i][j];
                if(dist[i] != INF && dist[v.second] > dist[i] + v.first) dist[v.second] = dist[i] + v.first;
            }
        }        
    }

    // 음수 사이클 존재 여부 판단
    bool is_negacycle = false;
    for(int i = 1; i <= V; i++) {
        int size = graph[i].size();
        for(int j = 0; j < size; j++) {
            pair<int, int> v = graph[i][j];
                if(dist[i] != INF && dist[v.second] > dist[i] + v.first) {
                is_negacycle = true;
                i = V;
                break;
            }
        }
    }
    if(is_negacycle) printf("-1");
    else{
        for(int i = 2; i <= V; i++) {
            if(dist[i] == INF) printf("-1\n");
            else printf("%lld\n", dist[i]);
        }
    }
    return 0;
}