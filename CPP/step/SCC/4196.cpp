/*
Problem: 도미노 (4196)
Tier: Platinum 5
Detail:  도미노는 재밌다. 도미노 블록을 일렬로 길게 늘어세운 뒤 블록 하나를 넘어뜨리면 그 블록이 넘어지며 다음 블록을 넘어뜨리는 일이 반복되어 일렬로 늘어선 블록들을 연쇄적으로 모두 쓰러뜨릴 수 있다.
그러나, 가끔씩 도미노가 다른 블록을 넘어뜨리지 못하게 배치되어 있다면, 우리는 다음 블록을 수동으로 넘어뜨려야 한다.
이제 각 도미노 블록의 배치가 주어졌을 때, 모든 블록을 넘어뜨리기 위해 손으로 넘어뜨려야 하는 블록 개수의 최솟값을 구하자.
Comment: SCC끼리 묶으면 하나의 배치가 된다. 그런식으로 묶음 그래프를 만들고, 플러드 필을 시전하면 해결!
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
        SC++;
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

int solve() {
    init();
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= N; i++) {
        if(!dfs_num[i]) get_SCC(i);
    }
    int SCCOutDegree[100001] = {0};
    for(int i = 1; i <= N; i++) {
        for(int j : graph[i]) if(SCC_num[i] != SCC_num[j]) {
            SCCOutDegree[SCC_num[j]]++;
        }
    }
    int result = 0;
    for(int i = 1; i <= SC; i++) {
        if(!SCCOutDegree[i]) result++;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    while(TC--) cout << solve() << '\n';
    return 0;
}