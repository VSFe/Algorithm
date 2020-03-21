/*
Problem: 외판원 순회 3 (16991)
Tier: Gold 1
Detail: 1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 모든 도시 사이에는 길이 있다. 이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 한다. 단, 한 번 갔던 도시로는 다시 갈 수 없다.
(맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외) 이런 여행 경로는 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.
도시 A에서 도시 B로 가는 비용은 두 도시 사이의 거리와 같다. 한 도시 A의 좌표가 (xA, yA), B의 좌표가 (xB, yB)라고 한다면, 두 도시의 거리는 √((xB-xA)2 + (yB-yA)2)와 같다.
도시의 수 N과 모든 도시의 위치가 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.
Comment: 외판원 순회 (2098)과 사실상 같은 문제!!
*/

#define MAX 16000001
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

double dist[17][17], cache[17][65537];
pair<int, int> point[17];
int N;
int visited = 0;
double MIN = MAX;

double TSP(int cur, int visited) {
    if(visited == (1 << N) - 1) {
        if(dist[cur][0] != 0) return dist[cur][0];
        //dist[cur][0] == 0 마지막 방문 시도를 했는데 안될경우!!
    }
    double &ret = cache[cur][visited];
    if (ret != 0) return ret;
    ret = MAX;
    for(int i = 0; i < N; i++) {
        if(visited & (1 << i)) continue;
        if(dist[cur][i] == 0) continue;
        ret = min(ret, TSP(i, visited | (1 << i)) + dist[cur][i]);
    }
    return MIN = ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        point[i] = make_pair(s, e);
    }
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            double tmp = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
            dist[i][j] = tmp, dist[j][i] = tmp;
        }
    }
    printf("%f", TSP(0, 1));
    return 0;
}