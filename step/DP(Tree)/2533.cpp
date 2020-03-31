/*
Problem: 사회망 서비스(SNS) (2533)
Tier: Gold 2
Detail: 친구 관계 그래프를 이용하면 사회망 서비스에서 어떤 새로운 아이디어가 전파되는 과정을 이해하는데 도움을 줄 수 있다.
어떤 새로운 아이디어를 먼저 받아들인 사람을 얼리 아답터(early adaptor)라고 하는데, 사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 아니다.
얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 아답터일 때만 이 아이디어를 받아들인다. 
어떤 아이디어를 사회망 서비스에서 퍼뜨리고자 할 때, 가능한 한 최소의 수의 얼리 아답터를 확보하여 모든 사람이 이 아이디어를 받아들이게 하는 문제는 매우 중요하다. 
일반적인 그래프에서 이 문제를 푸는 것이 매우 어렵다는 것이 알려져 있기 때문에, 친구 관계 그래프가 트리인 경우, 즉 모든 두 정점 사이에 이들을 잇는 경로가 존재하면서 사이클이 존재하지 않는 경우만 고려한다. 
친구 관계 트리가 주어졌을 때, 모든 개인이 새로운 아이디어를 수용하기 위하여 필요한 최소 얼리 어답터의 수를 구하는 프로그램을 작성하시오.
Comment: Minimum Vertex Cover Problem.
트리로 변경해서 풀면 됨.
새로운 문법 많이 알고 갑니다...
오버헤드 줄일 수도 있을 것 같은데... 뭐 일단 여기까지.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[1000001][2];
int N;
vector<int> input[1000001];
vector<int> tree[1000001];

void dfs(int now, int prev) {
    for(auto next : input[now]) {
        if(next ^ prev) {
            tree[now].push_back(next);
            dfs(next, now);
        }
    }
}

int DP(int idx, int cs) {
    int &ans = memo[idx][cs];
    if(ans != -1) return ans;
    ans = 0;

    if(cs) {
        for(auto next : tree[idx]) {
            int t0 = DP(next, 0);
            int t1 = DP(next, 1);
            ans += min(t0, t1);
        }
        ans++;
    }
    else {
        for(auto next : tree[idx]) ans += DP(next, 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        input[x].push_back(y);
        input[y].push_back(x);
    }
    dfs(1, 0);
    memset(memo, -1, sizeof(memo));
    cout << min(DP(1, 0), DP(1, 1));
    return 0;
}

