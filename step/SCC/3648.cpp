/*
Problem: 아이돌 (11280)
Tier: Platinum 4
Detail:  대한민국 아이돌 오디션 프로그램에서 참가자는 심사위원에게 10분동안 자신의 매력을 발산할 기회를 갖는다. 모든 참가자가 경연이 끝난후에, 심사위원은 모두 모여서 투표를 하게 된다.
각 심사위원은 다음 라운드에 꼭 진출시켰으면 하는 사람(찬성)이나 이번 라운드에서 꼭 탈락시켰으면 하는 사람(반대)을 두 명 고른다.
한 심사위원이 찬성표를 두 개 내는 것과 반대표를 두 개 내는 것도 가능하며, 찬성과 반대를 각각 하나씩 내는 것도 가능하다. 또, 반드시 두 표를 내야 한다.
다음 라운드에 진출하는 참가자의 수는 정해져 있지 않다. 즉, 실력이 참가자의 경연이 모두 나쁜 경우에는 다음 라운드에 진출하는 참가자가 없을 수도 있고,
모두 엄청난 경연을 한 경우에는 모든 참가자기 다음 라운드에 진출할 수도 있다.
상근이는 심판들이 자신의 프로그래밍 능력에 큰 관심을 보이지 않을 것 같아 걱정하고 있다. 따라서, 상근이는 해킹을 이용해서 다음 라운드에 진출하려고 한다.
상근이는 투표 집계 시스템을 해킹해서, 다음 라운드 진출자를 선택하는 프로그램을 바꿔치기 하려고 한다. 하지만, 의심을 받지 않아야 한다.
각 심사위원은 자신이 행사한 두 표 중 적어도 하나는 결과에 영향을 미쳐야 한다고 생각을 한다. 두 표 모두와 반대되는 결과가 나오면, 심사위원은 투표 결과에 대해서 의심을 하게 된다.
예를 들어, 고원섭 심사위원이 박현수 참가자에게 찬성을, 김선영 참가자에게 반대를 한 경우를 생각해보자.
이 경우에 김선영이 다음 라운드에 진출하고, 박현수가 탈락을 하게 된다면, 두 결과가 모두 영향을 미치지 못했기 때문에, 고원섭 심사위원은 투표를 의심하게 된다.
상근이는 심사위원의 의심을 받지 않으면서, 다음 라운드에 진출하는 목록을 만들 수 있는지를 알고 싶어 한다. 당연히 이 목록에는 상근이가 포함되어 있어야 한다.
 각 심사위원이 투표한 결과가 주어졌을 때, 상근이가 포함된 다음 라운드 진출 목록을 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.
Comment: x1의 값은 반드시 고정...

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
        graph[stand - 1].push_back(stand + 1);
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
        if(is_error) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}