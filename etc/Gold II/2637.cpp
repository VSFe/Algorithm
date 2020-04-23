/*
Problem: 장난감조립 (2637)
Tier: Gold 2
Detail: 우리는 어떤 장난감을 여러 가지 부품으로 조립하여 만들려고 한다. 이 장난감을 만드는데는 기본 부품과 그 기본 부품으로 조립하여 만든 중간 부품이 사용된다. 기본 부품은 다른 부품을 사용하여 조립될 수 없는 부품이다. 중간 부품은 또 다른 중간 부품이나 기본 부품을 이용하여 만들어지는 부품이다.
예를 들어보자. 기본 부품으로서 1, 2, 3, 4가 있다. 중간 부품 5는 2개의 기본 부품 1과 2개의 기본 부품 2로 만들어진다. 그리고 중간 부품 6은 2개의 중간 부품 5, 3개의 기본 부품 3과 4개의 기본 부품 4로 만들어진다. 마지막으로 장난감 완제품 7은 2개의 중간 부품 5, 3개의 중간 부품 6과 5개의 기본 부품 4로 만들어진다.
이런 경우에 장난감 완제품 7을 만드는데 필요한 기본 부품의 개수는 1번 16개, 2번 16개, 3번 9개, 4번 17개이다.
이와 같이 어떤 장난감 완제품과 그에 필요한 부품들 사이의 관계가 주어져 있을 때 하나의 장난감 완제품을 조립하기 위하여 필요한 기본 부품의 종류별 개수를 계산하는 프로그램을 작성하시오.
Comment: 트리 구조로 만들어보자... 그리고 위상정렬 돌리면 매우 간단하게 해결.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, answer[101], in[101];
vector<pair<int, int>> vec[101];
bool is_not_element[101];
priority_queue<int> pq;

void dfs(int idx, int ans) {
    for(auto next : vec[idx]) {
        if(is_not_element[next.first]) dfs(next.first, ans * next.second);
        else answer[next.first] += ans * next.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int u, v, dist;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> dist;
        in[v]++;
        vec[u].push_back({v, dist});
        is_not_element[u] = true;
    }
    for(int i = 1; i <= N; i++) {
        if(in[i]) continue;
        pq.push(i);
        answer[i] = 1;
    }
    while(!pq.empty()) {
        int num = pq.top(); pq.pop();
        for(auto next : vec[num]) {
            answer[next.first] += answer[num] * next.second;
            if(!(--in[next.first])) pq.push(next.first);
        }
    }
    for(int i = 1; i <= N; i++) {
        if(!is_not_element[i]) cout << i << ' ' << answer[i] << '\n';
    }
}