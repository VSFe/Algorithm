#include <bits/stdc++.h>
using namespace std;

int data[200001];
int N;
int dp[200001][2];
vector<int> tree[200001];
vector<int> participants[2];

int cal_dp(int idx, int pos) {
    if(dp[idx][pos] != INT_MIN) return dp[idx][pos];

    dp[idx][pos] = 0;

    if(pos) {
        for(int next: tree[idx]) {
            dp[idx][pos] += cal_dp(next, 0);
        } dp[idx][pos] += data[idx];
    } else {
        for(int next: tree[idx]) {
            int x1 = cal_dp(next, 1);
            int x2 = cal_dp(next, 0);

            dp[idx][pos] += max(x1, x2);
        }
    }

    return dp[idx][pos];
}

void get_participants(int idx, int pos, int is_boss) {
    if(pos) {
        for(int next: tree[idx]) {
            get_participants(next, 0, is_boss);
        } participants[is_boss].push_back(idx);
    } else {
        for(int next: tree[idx]) {
            if(dp[next][1] >= dp[next][0]) {
                get_participants(next, 1, is_boss);
            }
            else {
                get_participants(next, 0, is_boss);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> data[i];

    for(int i = 2; i <= N; i++) {
        int tmp; cin >> tmp;
        tree[tmp].push_back(i);
    }

    for(int i = 1; i <= N; i++)
        for(int j = 0; j < 2; j++)
            dp[i][j] = INT_MIN;

    cout << cal_dp(1, 1) << ' ' << cal_dp(1, 0) << '\n';

    get_participants(1, 0, 0);
    get_participants(1, 1, 1);

    for(int i = 1; i >= 0; i--) {
        sort(participants[i].begin(), participants[i].end());
        for(int node: participants[i]) {
            cout << node << ' ';
        }
        cout << -1 << '\n';
    }
}