/*
Problem: 트리의 독립집합 (2213)
Tier: Gold 2
Detail: 그래프 G(V, E)에서 정점의 부분 집합 S에 속한 모든 정점쌍이 서로 인접하지 않으면 (정점쌍을 잇는 에지가 없으면) S를 독립 집합(independent set)이라고 한다.
독립 집합의 크기는 정점에 가중치가 주어져 있지 않을 경우는 독립 집합에 속한 정점의 수를 말하고, 정점에 가중치가 주어져 있으면 독립 집합에 속한 정점의 가중치의 합으로 정의한다.
독립 집합이 공집합일 때 그 크기는 0이라고 하자. 크기가 최대인 독립 집합을 최대 독립 집합이라고 한다.
문제는 일반적인 그래프가 아니라 트리(연결되어 있고 사이클이 없는 그래프)와 각 정점의 가중치가 양의 정수로 주어져 있을 때, 최대 독립 집합을 구하는 것이다.
Comment: 우선 트리로 바꿔주고...
케이스를 나눠서 DP를 한 다음에...
백트래킹 과정에 주목
->  check[i] i의 부모가 꺼진 상태라면, i를 키는게 낫냐 끄는게 낫냐?? -> 즉 i의 부모가 켜져 있는 상태면 참조하는 의미가 없음...
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[10001][2], val[10001], check[10001];
int N;
vector<int> input[10001];
vector<int> tree[10001];
vector<int> sol;

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
            ans += DP(next, 0);
        } ans += val[idx];
    }
    else {
        for(auto next : tree[idx]) {
            int t0 = DP(next, 0);
            int t1 = DP(next, 1);
            if(t0 < t1) {
                check[next] = 1;
            } else check[next] = 0;
            ans += max(t0, t1);
        }
    }
    return ans;
}

void reverse_tracking(int idx, bool is_include) {
    if(is_include) {
        sol.push_back(idx);
    for(auto next : tree[idx]) reverse_tracking(next, 0);
    }
    else for(auto next : tree[idx]) reverse_tracking(next, check[next]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    sol.reserve(N);
    for(int i = 1; i <= N; i++) cin >> val[i];
    for(int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        input[x].push_back(y);
        input[y].push_back(x);
    }
    dfs(1, 0);
    memset(memo, -1, sizeof(memo));
    int t0 = DP(1, 0), t1 = DP(1, 1);
    if(t1 >= t0) check[1] = 1;
    reverse_tracking(1, check[1]);
    sort(sol.begin(), sol.end());
    cout << max(t0, t1) << '\n';
    for(int i = 0; i < sol.size(); i++) cout << sol[i] << ' ';
    return 0;
}

