#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long D[1001][1001];

long long doComb(int n, int r){
    if (r == 0 || r == n)
        return D[n][r] = 1;
    if (D[n][r] != -1)
        return D[n][r];
    return D[n][r] = (doComb(n - 1, r) + doComb(n - 1, r - 1)) % MOD;
}

void solution() {
    int n, k; cin >> n >> k;
    vector<int> data(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end(), greater<int>());

    for(int i = 0; i < k; i++) {
        m.insert({data[i], 0});
        m[data[i]]++;
    }
    sort(data.begin(), data.end());

    long long answer = 1;
    for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        int number = iter->first, cnt = iter->second;
        int cnt_total = upper_bound(data.begin(), data.end(), number) - lower_bound(data.begin(), data.end(), number);
        answer *= doComb(cnt_total, cnt);
        answer %= MOD;
    }

    cout << answer % MOD <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(D, -1, sizeof(D));
    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}