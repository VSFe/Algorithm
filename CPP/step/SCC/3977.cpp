/*
Problem: 축구전술 (3977)
Tier: Platinum 4
Detail:  도현이의 전략은 경기장을 여러 개의 구역으로 나누고, 어떤 선수가 A구역에서 B구역으로 이동하게 하는 움직임을 (A, B)로 표현한다.
모든 도현이의 팀 선수들이 이 움직임만을 따라서 이동한다면 승리하리라고 도현이는 확신한다.
도현이는 선수들에게 자신의 전술을 말해주며, 다른 모든 구역에 도달할 수 있는 시작 구역을 찾은 뒤 지시한 움직임만을 따라가라고 했다.
그러나 도현이는 한 가지 간과한 것이 있었는데 그건 선수들이 자신만큼 똑똑하지 않다는 것이다. 선수들은 그러한 시작 구역을 찾는 것이 어려웠다. 이제 당신이 적절한 시작 구역을 찾아줘야 한다.
Comment: 진입 차수에 대한 문제.
진입차수가 0인 SCC 컴포넌트가 딱 한개여야 함.
(0개일수는 없다! 0개면 그것 자체로 SCC를 형성함.)
2개 이상일 경우는 Confused 출력, 아닌 경우는 해당 컴포넌트 그대로 삽입.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[100001];
int dfs_num[100001], dfs_low[100001], SCC_num[100001];
bool finished[100001];
vector<vector<int>> SCC;
int N, M, cnt, SC;
stack<int> st;


void get_SCC(int idx) {
    dfs_num[idx] = dfs_low[idx] = ++cnt;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) get_SCC(next);
        if(!finished[next]) dfs_low[idx] = min(dfs_low[idx], dfs_low[next]);
    }
    if(dfs_num[idx] == dfs_low[idx]) {
        vector<int> vec;
        while(1) {
            int t = st.top();
            SCC_num[t] = SC;
            finished[t] = 1;
            vec.push_back(t);
            st.pop();
            if(t == idx) break;
        } 
        sort(vec.begin(), vec.end());
        SCC.push_back(vec);
        SC++;
    }
}

void init() {
    for(int i = 0; i < 100001; i++) graph[i].clear();
    SCC.clear();
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(finished, 0, sizeof(finished));
    memset(SCC_num, 0, sizeof(SCC_num));
    cnt = 0, SC = 0;
    while(!st.empty()) st.pop();
}

void solve() {
    init();
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 0; i < N; i++) {
        if(!dfs_num[i]) get_SCC(i);
    }
    int SCCOutDegree[100001] = {0};
    for(int i = 0; i < N; i++) {
        for(int j : graph[i]) if(SCC_num[i] != SCC_num[j]) {
            SCCOutDegree[SCC_num[j]]++;
        }
    }
    int result = -1;
    bool ok = true;
    for(int i = 0; i < SC; i++) {
        if(!SCCOutDegree[i]) {
            if(result != -1) {
                ok = 0;
                i = SC;
                break;
            }
            else result = i;
        }
    }
    if(ok) {
        for(int i = 0; i < SCC[result].size(); i++) cout << SCC[result][i] << '\n';
        cout << '\n';
    }
    else cout << "Confused" << '\n' << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    while(TC--) solve();
    return 0;
}