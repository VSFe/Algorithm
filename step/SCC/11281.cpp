/*
Problem: 2-SAT - 4 (11281)
Tier: Platinum 3
Detail:  2-SAT은 N개의 불리언 변수 가 있을 때, 2-CNF 식을 true로 만들기위해 x를 어떤 값으로 정해야하는지를 구하는 문제이다.
변수의 개수 N과 절의 개수 M, 그리고 식 f가 주어졌을 때, 식 f를 true로 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.
Comment: 기본적인 해결 방법은 2-SAT - 3 (11280)과 동일하지만, 이 문제는 어떤 값인지도 적어야 하네??
상식적으로 제약조건이 널널해야 뒷 값을 설정함에 있어 충돌하지 않음.
SCC 번호에 주목하자면, 나중에 호출되는 함수가 먼저 종료되는 재귀함수의 특성상, SCC 번호는 DFS 방문 순서의 역순,
즉 위상정렬의 역순이라고 생각할 수 있음.
그러므로 SCC 들어간 것의 역순으로 값을 불러 들이면 DFS 방문 순서이고, 먼저 방문하는 값부터 false를 박아버리면 될 거임!
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[20003];
vector<vector<int>> SCC;
int dfs_num[20003], dfs_low[20003], TF[10003], cnt = 1;
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
    memset(TF, -1, sizeof(TF));
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
    for(int i = SCC.size() - 1; i >= 0; i--) {
        int tmp = SCC[i][0];
        if(TF[tmp/2] == -1) {
            if(tmp % 2 == 0) TF[tmp/2] = 0;
            else TF[tmp/2] = 1; 
        }
        for(int j = 0; j < SCC[i].size() - 1; j++) {
            int x = SCC[i][j], y = SCC[i][j + 1];
            if(x/2 == y/2 && abs(x - y) == 1) {
                is_error = true;
                i = 0;
                break;
            }
            if(TF[y/2] == -1) {
                if(y % 2 == 0) TF[y/2] = 0;
                else TF[y/2] = 1; 
            }
        }
    }
    if(is_error) cout << 0;
    else {
        cout << 1 << '\n';
        for(int i = 1; i <= V; i++) {
            cout << TF[i] << ' ';
        }
    }
    return 0;
}