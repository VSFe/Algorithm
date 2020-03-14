/*
Problem: 바이러스 (2606)
Tier: Silver 2
Detail:  신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다.
한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다.
하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때,
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.
Comment: DFS 딱 한번만 돌리면 되는 개꿀 문제
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> dfs_visited;
int cnt = 0;

void dfs(int u) {
    dfs_visited[u] = 1;
    int size = graph[u].size();
    cnt++;
    for(int i = 0; i < size; i++) {
        int t = graph[u][i];
        if(dfs_visited[t] == 0) dfs(t);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs_visited = vector<int>(N, 0);
    graph.reserve(N);
    for(int i = 0; i < M; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1-1].push_back(tmp2-1);
        graph[tmp2-1].push_back(tmp1-1);
    }
    dfs(0);
    printf("%d", cnt-1);
    return 0;
} 