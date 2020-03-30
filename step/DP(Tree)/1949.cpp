/*
Problem: 우수 마을 (1949)
Tier: Gold 1
Detail: N개의 마을로 이루어진 나라가 있다. 편의상 마을에는 1부터 N까지 번호가 붙어 있다고 하자. 이 나라는 트리(Tree) 구조로 이루어져 있다.
즉 마을과 마을 사이를 직접 잇는 N-1개의 길이 있으며, 각 길은 방향성이 없어서 A번 마을에서 B번 마을로 갈 수 있다면 B번 마을에서 A번 마을로 갈 수 있다.
또, 모든 마을은 연결되어 있다. 두 마을 사이에 직접 잇는 길이 있을 때, 두 마을이 인접해 있다고 한다.
이 나라의 주민들에게 성취감을 높여 주기 위해, 다음 세 가지 조건을 만족하면서 N개의 마을 중 몇 개의 마을을 '우수 마을'로 선정하려고 한다.
    '우수 마을'로 선정된 마을 주민 수의 총 합을 최대로 해야 한다.
    마을 사이의 충돌을 방지하기 위해서, 만일 두 마을이 인접해 있으면 두 마을을 모두 '우수 마을'로 선정할 수는 없다. 즉 '우수 마을'끼리는 서로 인접해 있을 수 없다.
    선정되지 못한 마을에 경각심을 불러일으키기 위해서, '우수 마을'로 선정되지 못한 마을은 적어도 하나의 '우수 마을'과는 인접해 있어야 한다.
각 마을 주민 수와 마을 사이의 길에 대한 정보가 주어졌을 때, 주어진 조건을 만족하도록 '우수 마을'을 선정하는 프로그램을 작성하시오.
Comment: 2213 + 2533...
커버를 무조건 해야 한다는 점에 주목...
부모의 상태까지 저장하면 되지 않을까?
근데 생각을 해보니 낚임.
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
            ans += max(t0, t1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> val[i];
    for(int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        input[x].push_back(y);
        input[y].push_back(x);
    }
    dfs(1, 0);
    memset(memo, -1, sizeof(memo));
    int t0 = DP(1, 0);
    int t1 = DP(1, 1);
    cout << max(t0, t1);
    return 0;
}

