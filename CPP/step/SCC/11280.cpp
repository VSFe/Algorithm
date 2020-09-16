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
using namespace std;

vector<int> graph[20003];
vector<vector<int>> SCC;
int dfs_num[20003], dfs_low[20003], cnt = 1;
bool finished[20003], is_error = false;
stack<int> st;

void dfs(int idx, int prev) {
    dfs_num[idx] = dfs_low[idx] = cnt++;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) dfs(next, idx);
        if(!finished[next]) dfs_low[idx] = min(dfs_low[idx], dfs_low[next]);
    }
    if(dfs_num[idx] == dfs_low[idx]) {
        vector<int> vec;
        while(1) {
            int t = st.top();
            finished[t] = 1;
            vec.push_back(t);
            st.pop();
            if(t == idx) break;
        } 
        sort(vec.begin(), vec.end());
        SCC.push_back(vec);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int V, E; cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        if(x < 0) graph[abs(x) * 2].push_back((y < 0) ? abs(y)*2+1 : y*2);
        else graph[x * 2 + 1].push_back((y < 0) ? abs(y)*2+1 : y*2);
        if(y < 0) graph[abs(y) * 2].push_back((x < 0) ? abs(x)*2+1 : x * 2);
        else graph[y * 2 + 1].push_back((x < 0) ? abs(x)*2+1 : x * 2);
    }
    for(int i = 2; i < 2 * V + 2; i++) {
        if(!dfs_num[i]) dfs(i, 0);
    }
    for(int i = 0; i < SCC.size(); i++) {
        for(int j = 0; j < SCC[i].size() - 1; j++) {
            int x = SCC[i][j], y = SCC[i][j + 1];
            if(x/2 == y/2 && abs(x - y) == 1) {
                is_error = true;
                i = SCC.size();
                break;
            } 
        }
    }
    if(is_error) cout << 0;
    else cout << 1;
    return 0;
}