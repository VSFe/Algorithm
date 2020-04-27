/*
Problem: 호텔 관리
Tier: Platinum 3
Detail: 구사과 호텔에는 총 N개의 방이 있고, 방의 잠금 상태를 제어할 수 있는 스위치가 M개 있다. 모든 방은 두 개의 스위치와 연결되어 있다.
초기 방의 잠금 상태를 알고 있을 때, 스위치를 이용해 모든 방을 열려고 한다. 스위치를 누르면 연결된 방의 상태가 반전된다.
예를 들어, 방 1, 2, 3의 상태가 열림, 닫힘, 열림이고, 모두 스위치 1과 연결되어 있는 경우에 이 스위치를 누르면 방의 상태가 닫힘, 열림, 닫힘이 된다.
스위치를 이용해 모든 방을 열 수 있는지 알아보자.
Comment: 만약 A번 방과 B번 방에 스위치가 달려있다고 한다면...
1. 초기 상태가 1인 경우 (A ^ B) V (~A ^ ~B)
(A V ~B) ^ (~A V B) 
2. 초기 상태가 0인 경우 (~A ^ B) V (A ^ ~B)
(A V B) ^ (~A ^ ~B)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> graph[200005];
vector<vector<int>> SCC;
int dfs_num[200005], pos[200005][2], cnt = 1;
bool finished[200005], stand[200005], is_error = false;
stack<int> st;

void dfs(int idx, int prev) {
    int dfn = dfs_num[idx] = cnt++;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) dfs(next, idx);
        if(!finished[next]) dfs_num[idx] = min(dfs_num[idx], dfs_num[next]);
    }
    if(dfs_num[idx] == dfn) {
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
    for(int i = 1; i <= V; i++) {
        int tmp; cin >> tmp;
        if(tmp) stand[i] = 1;
    }
    for(int i = 1; i <= E; i++) {
        int size, x; cin >> size;
        for(int j = 0; j < size; j++) {
            cin >> x;
            if(!pos[x][0]) pos[x][0] = i;
            else pos[x][1] = i;
        }
    }
    for(int i = 1; i <= V; i++) {
        int x = pos[i][0], y = pos[i][1];
        if(!stand[i]) {
            graph[x * 2].push_back(y * 2 + 1);
            graph[x * 2 + 1].push_back(y * 2);
            graph[y * 2].push_back(x * 2 + 1);
            graph[y * 2 + 1].push_back(x * 2);
        }
        else {
            graph[x * 2].push_back(y * 2);
            graph[x * 2 + 1].push_back(y * 2 + 1);
            graph[y * 2].push_back(x * 2);
            graph[y * 2 + 1].push_back(x * 2 + 1);
        } 
    }
    int size = 2 * V + 2;
    for(int i = 2; i <= size; i++) {
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