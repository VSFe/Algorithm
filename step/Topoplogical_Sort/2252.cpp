/*
Problem: 줄 세우기 (2252)
Tier: Gold 2
Detail: N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다.
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.
일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.
Comment: 위상정렬의 기본 of 기본 문제.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<vector<int>> vec;
int N, M, in[32001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    vec.reserve(N + 1);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        in[y]++;
    }
    for(int i = 1; i <= N; i++) {
        if(!in[i]) pq.push(i);
    }
    while(!pq.empty()) {
        int dt = pq.top(); pq.pop();
        cout << dt << " ";
        for(auto child : vec[dt]) {
            in[child]--;
            if(!in[child]) pq.push(child);
        }
    }
    return 0;
}
