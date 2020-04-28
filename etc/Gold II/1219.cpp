#define INF 2000000000
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int V, E, start, finish, prices[101];
vector<ll> dist;
vector<pair<int, int>> graph[101];

int main() {
    scanf("%d %d %d %d", &V, &start, &finish, &E);
    dist = vector<ll>(V+1, INF);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    for(int i = 0; i < V; i++) {
        int price; scanf("%d", &price);
        prices[i] -= price;
    }
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < graph[i].size(); i++) {
            graph[i][j].second += prices[graph[i][j].first];
        }
    }
    dist[start] = prices[start];
    for(int i = 0; i < V; i++) {
        int size = graph[i].size();
        for(int j = 0; j < size; j++) {
            pair<int, int> p = graph[i][j];
            if(dist[p.first] > dist[i] + p.second) dist[p.first] = dist[i] + p.second;
        }
    }
    // 음수 사이클 존재 여부 판단
    bool is_negacycle = false;
    for(int i = 1; i <= V; i++) {
        int size = graph[i].size();
        for(int j = 0; j < size; j++) {
            pair<int, int> p = graph[i][j];
            if(dist[p.first] > dist[i] + p.second) {
                is_negacycle = true;
                i = V;
                break;
            }
        }
    }
    if(dist[finish] == INF) printf("gg");
    else if(is_negacycle) printf("Gee");
    else printf("%d", -1 * dist[finish]);
    return 0;
}