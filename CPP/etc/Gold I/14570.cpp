#include <bits/stdc++.h>
using namespace std;

int tree[200001][2];
int size[200001];
int N;
long long M;

int solve(int node, long long remain) {
    if (tree[node][0] == -1 && tree[node][1] == -1) return node;
    if (tree[node][0] == -1) return solve(tree[node][1], remain);
    if (tree[node][1] == -1) return solve(tree[node][0], remain);

    if (remain % 2) return solve(tree[node][0], remain / 2 + 1);
    return solve(tree[node][1], remain / 2);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x, y; cin >> tree[i][0] >> tree[i][1];
    }

    cin >> M;

    cout << solve(1, M);
}