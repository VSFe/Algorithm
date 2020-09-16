/*
Problem: 2-SAT - 3 (11280)
Tier: Platinum 4
Detail:  2-SAT은 N개의 불리언 변수 가 있을 때, 2-CNF 식을 true로 만들기위해 x를 어떤 값으로 정해야하는지를 구하는 문제이다.
변수의 개수 N과 절의 개수 M, 그리고 식 f가 주어졌을 때, 식 f를 true로 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.
Comment: 각각의 Clause에는 두개의 추론 식을 만들 수 있음 (하나가 거짓이면 다른 하나가 참)
해당 논리식을 그래프로 옮겼을 때, ^x -> x 와 x -> ^x가 공존해서는 안됨.
즉, 같은 SCC 컴포넌트에 들어있으면 안됨!!!

x의 참 값은 해당 번지수 * 2, 거짓 값은 해당 번지수 * 2 + 1
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[10001];
int dfs_num[10001], dfs_low[10001], finished[10001];
int cnt = 1, SC = 1, V, E;
stack<int> st;

const int stand = 5000;

void dfs(int idx, int prev) {
    dfs_num[idx] = dfs_low[idx] = cnt++;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) dfs(next, idx);
        if(!finished[next]) dfs_low[idx] = min(dfs_low[idx], dfs_low[next]);
    }
    if(dfs_num[idx] == dfs_low[idx]) {
        while(1) {
            int t = st.top();
            finished[t] = SC;
            st.pop();
            if(t == idx) break;
        } SC++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> E >> V;
    for(int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        graph[stand - x].push_back(stand + y);
        graph[stand - y].push_back(stand + x);
    }
    for(int i = 1; i <= V; i++) {
        if(!dfs_num[stand + i]) dfs(stand + i, 0);
        if(!dfs_num[stand - i]) dfs(stand - i, 0);
    }
    for(int i = 1; i <= V; i++) {
        if(finished[stand + i] == finished[stand - i]) {
            cout << "OTL";
            return 0;
        }
    }
    cout << "^_^" << '\n';
    return 0;
}