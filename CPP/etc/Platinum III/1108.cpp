/*
Problem: 검색 엔진
Tier: Platinum 3
Detail: 새로운 검색 엔진을 만들었다. 이 검색 엔진은 구글을 뛰어넘는 세계 최고의 검색 엔진이기 때문에, 신뢰도가 높은 결과를 보여줘야 한다.
하지만, 사용자가 검색어를 입력했을 때, 이것에 맞는 결과가 수천, 수만개가 될 수 있으므로, 이 중에 어떤 것이 중요하고, 어떤 사이트를 보여줘야 하는지가 큰 문제이다.
구글은 이러한 것을 사이트를 크롤링해서 자체 알고리즘을 이용해서 사이트의 순위를 매긴다. 우리의 검색 엔진은 다음과 같은 방법을 사용할 것이다.
일단 모든 웹사이트에 1점을 준다. 만약에 웹사이트 A에 웹사이트 B로 가는 링크가 있다면, 웹사이트 B의 점수에 웹사이트 A의 점수를 더한다.
예를 들어, 웹사이트가 총 3개가 있다. A, B, C이다. 일단 모든 웹사이트의 점수는 1이다. 이제, 웹사이트 A와 B에 모두 C로 가는 링크가 있다고 하면,
C의 점수는 3이 되고, A와 B의 점수는 그대로 1이다. 만약 어떤 검색어가 입력 되었는데, 이 웹사이트 A B C에 모두 해당하는 것이었다면, C가 가장 위에 표시된다.
이런 웹사이트에 점수를 매기는 일이 어려운 이유는 바로, 링크를 교환하는 사이트 들이 있기 때문이다. 이 말은 A가 B를 링크하고, B가 A를 링크하는 것이다.
따라서, 이런 현상으로 점수가 무한대로 늘어나는 것을 방지하기 위해서, A의 점수를 B에 더할 때는, B에서 A로의 링크가 직접적으로 또는 간접적으로 없을 때이다.
링크가 어떻게 되어있는 지가 주어지고, 웹사이트의 이름이 주어질 때, 그 웹사이트의 점수를 출력하는 프로그램을 작성하시오.
Comment: 해싱 + SCC + 위상정렬 짬뽕 볶음 문제.
꽤나 어려운 문제였지만 차근차근하면 풀리긴 하네...
1. 문자열은 해싱을 활용해서 입력 받음
2. 각각의 입력에 맞춰 그래프를 생성하고, SCC를 만들어 줌
3. SCC로 위상정렬을 수행하기 위해, SCC로 단편화된 DAG를 만들어주되, 각각의 간선에는 실제 그래프에서의 어떤 원소가 나와서 어떤 원소로 들어가는지까지 기록해 줌.
4. 3번에서 입력 받은 값에 맞춰 위상정렬을 수행함.
아이고 이걸 푸네
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

struct edge {
    int scc_to, node_from, node_to;
    edge() {}
    edge(int _s, int _f, int _t) : scc_to(_s), node_from(_f), node_to(_t) {}
};

vector<int> graph[3000], SCC_Component[3000];
vector<edge> SCC_graph[3000];
int dfs_num[3000], dfs_low[3000], finished[3000];
long long ans[3000];
int cnt = 1, SC = 1, idx = 0, N;
stack<int> st;
queue<int> q;
unordered_map<string, int> um;

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
            SCC_Component[SC].push_back(t);
            st.pop();
            if(t == idx) break;
        } SC++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
        int num, begin_idx, end_idx;
        cin >> s >> num;
        if(um.find(s) == um.end()) um.insert({s, ++idx});
        end_idx = um.find(s)->second;
        for(int j = 0; j < num; j++) {
            cin >> s;
            if(um.find(s) == um.end()) um.insert({s, ++idx});
            begin_idx = um.find(s)->second;
            graph[begin_idx].push_back(end_idx);
        }
    }
    for(int i = 1; i <= idx; i++) {
        if(!finished[i]) dfs(i, 0);
    }
    int SCCOutDegree[3000] = {0, }, SCC_Point[3000];
    fill(ans, ans+3000, 1);
    for(int i = 1; i <= idx; i++) {
        for(auto next : graph[i]) {
            if(finished[i] != finished[next]) {
                SCC_graph[finished[i]].push_back({finished[next], i, next});
                SCCOutDegree[finished[next]]++;
            }            
        }
    }
    for(int i = 1; i < SC; i++) {
        if(!SCCOutDegree[i]) q.push(i);
    }
    while(!q.empty()) {
        int tmp = q.front(); q.pop();
        for(auto next : SCC_graph[tmp]) {
            ans[next.node_to] += ans[next.node_from];
            if(!(--SCCOutDegree[next.scc_to])) q.push(next.scc_to);
        }
    }
    cin >> s;
    cout << ans[um.find(s)->second];
}

