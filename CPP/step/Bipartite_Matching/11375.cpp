/*
Problem: 열혈강호 (11375)
Tier: Platinum 4
Detail: 강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 M번까지 번호가 매겨져 있다.
각 직원은 한 개의 일만 할 수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.
각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, M개의 일 중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오.
Comment: 이분매칭의 정석! 간단한 이분매칭을 구현해봅시다...
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;

int N, M, B[MAX];
vector<int> vec[MAX];
int visited[MAX];

int dfs(int a) {
    if(visited[a]) return 0;
    visited[a] = 1;
    for(int next : vec[a]) {
        if(!B[next] || dfs(B[next])) {
            B[next] = a;
            return true;
        }
    }
    return false;
}

int bimatch() {
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        fill(visited, visited + MAX, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int S; cin >> S;
        for(int j = 1; j <= S; j++) {
            int k; cin >> k;
            vec[i].push_back(k);
        }
    }
    cout << bimatch();
    return 0;
}
