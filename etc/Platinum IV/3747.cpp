/*
Problem: 완벽한 선거! (3747)
Tier: Platinum 4
Detail: N어떤 나라에서는 (뭔 나라인지는 기억이 안 나지만), 후보 {1, 2 ... N}이 나와서 국회의원 선거를 치루고 있다.
여론조사에서는 사람들마다 "만약 두 후보 i, j에 대해서, 그 두 후보의 선거 결과가 어떻게 나오면 행복할 것 같으세요?" 라고 물어봤다.
이 질문에 대한 가능한 답변은 밑의 표에 나와있고, i와 j가 동일할 수도 있다.
우리는 M개의 가능한 답변의 리스트를 가지고 있고, 이 M개의 답변 중 비슷하거나 동일한 것이 있을 수도 있다.
만약에 이 M개의 답변을 동시에 만족하는 선거 결과가 있다면, 이 선거 결과를 완벽하다고 한다. (다만, 후보 {1, 2 ... N}이 모두 당선되거나 모두 낙선될 수도 있고, 이 중 일부만 당선될 수도 있다!)
우리가 할 일은 M개의 답변에 대해서 완벽한 선거 결과가 있으면 1을, 아니면 0을 출력하는 것이다.
나는 i와 j 둘 중 한 명은 당선되었으면 좋겠어. 	+i +j
난 i랑 j 둘 중 한 명은 떨어졌으면 좋겠어. 	-i -j
난 i가 붙거나 j가 떨어지거나, 둘 다 만족했음 좋겠어. 	+i -j
난 j가 붙거나 i가 떨어지거나, 둘 다 만족했음 좋겠어. 	-i +j
Comment: 정말 정말 평범한 2-SAT 문제인데??
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[2001];
int dfs_num[2001], dfs_low[2001], finished[2001];
int cnt = 1, SC = 1, V, E;
bool is_error = false;
stack<int> st;

const int stand = 1000;

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
    while(cin >> V >> E) {
        is_error = false; cnt = 1, SC = 1;
        memset(finished, 0, sizeof(finished));
        memset(dfs_num, 0, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));
        for(int i = 0; i < 2001; i++) graph[i].clear();
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
                is_error = true;
                i = V + 1;
            }
        }
        if(is_error) cout << "0" << '\n';
        else cout << "1" << '\n';
    }
}