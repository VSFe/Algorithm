/*
Problem: 케빈 베이컨의 6단계 법칙
Tier: Silver 1
Detail: 예를 들어, BOJ의 유저가 5명이고, 1과 3, 1과 4, 2와 3, 3과 4, 4와 5가 친구인 경우를 생각해보자.
1은 2까지 3을 통해 2단계 만에, 3까지 1단계, 4까지 1단계, 5까지 4를 통해서 2단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 2+1+1+2 = 6이다.
2는 1까지 3을 통해서 2단계 만에, 3까지 1단계 만에, 4까지 3을 통해서 2단계 만에, 5까지 3과 4를 통해서 3단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 2+1+2+3 = 8이다.
3은 1까지 1단계, 2까지 1단계, 4까지 1단계, 5까지 4를 통해 2단계 만에 알 수 있다. 따라서, 케빈 베이컨의 수는 1+1+1+2 = 5이다.
4는 1까지 1단계, 2까지 3을 통해 2단계, 3까지 1단계, 5까지 1단계 만에 알 수 있다. 4의 케빈 베이컨의 수는 1+2+1+1 = 5가 된다.
마지막으로 5는 1까지 4를 통해 2단계, 2까지 4와 3을 통해 3단계, 3까지 4를 통해 2단계, 4까지 1단계 만에 알 수 있다. 5의 케빈 베이컨의 수는 2+3+2+1 = 8이다.
5명의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람은 3과 4이다.
BOJ 유저의 수와 친구 관계가 입력으로 주어졌을 때, 케빈 베이컨의 수가 가장 작은 사람을 구하는 프로그램을 작성하시오.
Comment: BFS N번 돌리면 끝...
*/

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
vector<int> visited;
int V, E, head, tail, cnt;
int MIN = 50000, answer = 0;

int bfs(int start) {
    queue<pair<int, int>> q;
    int step = 0;
    cnt = 1;
    visited[start] = 1;
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int i = 0; i < vec[p.first].size(); i++) {
            int tmp = vec[p.first][i];
            if(visited[tmp] == 0) {
                visited[tmp] = 1;
                step += p.second + 1;
                cnt++;
                if(cnt == V) return step;
                q.push(make_pair(tmp, p.second + 1));
            }
        }
    }
    return 50000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    vec.reserve(V + 1);
    for(int i = 0; i < E; i++) {
        cin >> head >> tail;
        vec[head].push_back(tail);
        vec[tail].push_back(head);
    }
    for(int i = 1; i < V+1; i++) {
        visited.assign(V + 1, 0);
        int ith_bfs = bfs(i);
        if(ith_bfs < MIN) {
            MIN = ith_bfs;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}