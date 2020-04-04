/*
Problem: 2-SAT - 4 (11281)
Tier: Platinum 3
Detail:  2-SAT은 N개의 불리언 변수 가 있을 때, 2-CNF 식을 true로 만들기위해 x를 어떤 값으로 정해야하는지를 구하는 문제이다.
변수의 개수 N과 절의 개수 M, 그리고 식 f가 주어졌을 때, 식 f를 true로 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.
Comment: 풀기야 풀었는데... 가독성이 아쉬워서 다시 품.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[20001];
vector<vector<int>> SCC;
int dfs_num[20001], dfs_low[20001], TF[10001], finished[20001];
int cnt = 1, SC = 1, V, E;
bool is_error = false;
stack<int> st;

const int stand = 10000;

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

void get_answer() {
    vector<pair<int, int>> vec;
	for (int i = 1; i <= V; i++){
		vec.push_back({finished[stand - i], stand - i});
		vec.push_back({finished[stand + i], stand + i});
	}
	sort(vec.begin(), vec.end(), greater<pair<int, int>>());
	for (auto p : vec){
		int x, tf;
		x = p.second;
		if (x < stand){ x = stand - x; tf = 1; }
		else { x = x - stand; tf = 0; }
		if (TF[x] < 0) TF[x] = tf;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(TF, -1, sizeof(TF));
    cin >> V >> E;
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
            cout << 0;
            return 0;
        }
    }
    cout << 1 << '\n';
    get_answer();
    for(int i = 1; i <= V; i++) cout << TF[i] << ' ';
    return 0;
}