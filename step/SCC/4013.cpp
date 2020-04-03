/*
Problem: ATM (4013)
Tier: Platinum 3
Detail:  인도의 도시 중 하나인 시루세리에는 모든 도로들이 일방통행으로 되어 있다. 도로들이 만나는 모든 교차로에는 시루세리 은행의 현금입출금기(ATM)가 설치되어 있다.
시루세리에는 유명한 레스토랑 체인인 아웃백 커리 하우스가 있다. 이 레스토랑의 각 체인점들은 교차로에만 위치한다. 물론 각 교차로마다 항상 이 레스토랑 체인점이 있는 것은 아니다. 이 레스토랑은 현금만 사용할 수 있다. 
시루세리에 사는 반디치는 오늘 오후에 이 레스토랑에서 가족들과 파티를 열려고 한다. 그런데 갖고 있는 현금이 부족하여 레스토랑으로 가는 동안에 가능한 한 많은 현금을 ATM 기기로부터 인출할 계획을 세웠다.
그는 자신의 집에서 출발하여 차로 이동하면서 통과하는 모든 교차로 ATM 기기에 들어있는 현금 전부를 인출하려고 한다. 차량의 최종 목적지는 아웃백 커리 하우스 체인점 중의 한 곳이고, 이 체인점이 어떤 교차로에 위치하는지는 상관없다.
반디치는 시루세리 은행의 홈페이지 정보를 통해 각 ATM 기기에 현금이 얼마나 들어 있는지를 알고 있다. 이동 시 동일한 도로나 교차로를 여러 번 지날 수 있다.
ATM 기기의 현금은 새로 보충되지 않기 때문에 첫 번째 이후 다시 방문하는 교차로의 ATM 기기에는 인출할 현금이 없다.
예를 들어, 아래 그림처럼 도시에 6개의 교차로가 있다고 하자. 교차로는 원으로 표시되어 있고, 화살표는 도로를 나타낸다. 이중 원으로 표시된 교차로에는 레스토랑이 있다.
각 ATM 기기가 갖고 있는 현금의 액수는 교차로 위에 표시된 숫자이다. 이 예에서 현금 인출을 1번 교차로부터 시작한다면, 반디치는 1-2-4-1-2-3-5의 경로를 통해서 총 47의 현금을 인출할 수 있다.
반디치가 출발 장소에서 어떤 레스토랑까지 이동하면서 인출할 수 있는 현금의 최대 액수가 얼마인지를 계산하는 프로그램을 작성하시오.
Comment: 진입 차수에 대한 문제.
진입차수가 0인 SCC 컴포넌트가 딱 한개여야 함.
(0개일수는 없다! 0개면 그것 자체로 SCC를 형성함.)
2개 이상일 경우는 Confused 출력, 아닌 경우는 해당 컴포넌트 그대로 삽입.
*/

#define INF -5000000
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

vector<int> graph[5001];
set<int> SCC_graph[5001];
int dfs_num[5001], SCC_index[5001], node_data[5001], SCC_data[5001], result[5001], sOutDegree[5001];
bool is_restaurant[5001], finished[5001];
int N, M, start, cnt_rest, cnt = 0, SC = 1;
stack<int> st;

void get_SCC(int idx) {
    int dn = dfs_num[idx] = ++cnt;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) get_SCC(next);
        if(!finished[next]) dfs_num[idx] = min(dfs_num[idx], dfs_num[next]);
    }
    if(dfs_num[idx] == dn) {
        while(1) {
            int t = st.top();
            SCC_index[t] = SC;
            finished[t] = 1;
            SCC_data[SC] += node_data[t];
            st.pop();
            if(t == idx) break;
        } 
        SC++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= N; i++) cin >> node_data[i];
    for(int i = 1; i <= N; i++) {
        if(!dfs_num[i]) get_SCC(i);
    }
    for(int i = 1; i <= N; i++) {
        for(auto next : graph[i]) {
            if(SCC_index[i] != SCC_index[next]) {
                SCC_graph[SCC_index[i]].insert(SCC_index[next]);
                sOutDegree[SCC_index[next]]++;
            }
        }
    }
    cin >> start >> cnt_rest;
    for(int i = 0; i < cnt_rest; i++) {
        int tmp; cin >> tmp;
        is_restaurant[SCC_index[tmp]] = true;
    }
    queue<int> Q;
    bool sCal[5001] = {0}; // 시작점에서 이 SCC에 도달할 수 있는가?
    for(int i=1; i<=SC; i++){
        result[i] = SCC_data[i]; // 결과값 초기화: 자신의 액수만큼은 챙길 수 있음
        if(i == SCC_index[start]) sCal[i] = true;
        if(sOutDegree[i] == 0) Q.push(i); // outdegree가 0인 SCC를 큐에 넣음
    }
 
    // 위상 정렬 시작
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: SCC_graph[curr]){
            if(sCal[curr]){ // 시작점에서 이 SCC에 도달 가능해야만 next의 정보 갱신
                result[next] = max(result[next], result[curr] + SCC_data[next]);
                sCal[next] = true;
            }
            if(--sOutDegree[next] == 0) Q.push(next);
        }
    }
 
    // 결과 구해서 출력
    int MAX = 0;
    for(int i=1; i<=SC; i++)
        if(is_restaurant[i] && sCal[i]) MAX = max(MAX, result[i]);
    printf("%d\n", MAX);
}