#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
int n, m, times;
vector<int> graph[51];

ll get_sum(int i, int j, vector<vector<ll>> &A, vector<vector<ll>> &B) {
    ll result = 0;
    for(int x = 0; x < n; x++)
        result += (A[i][x] * B[x][j]) % MOD;
    return result % MOD;
}

void multi(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    vector<vector<ll>> tmp = vector<vector<ll>>(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = get_sum(i, j, A, B);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            B[i][j] = tmp[i][j];
}

int solve() {
    vector<vector<ll>> arr = vector<vector<ll>>(n, vector<ll>(n, 0));
    vector<vector<ll>> arr_multi = vector<vector<ll>>(n, vector<ll>(n, 0));
    
    arr[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(auto next: graph[i])
            arr_multi[i][next] = 1;

    while(times != 0) {
        if(times % 2 == 1) {
            multi(arr_multi, arr);
            times--;
        } else {
            multi(arr_multi, arr_multi);
            times /= 2;
        }
    }

    return arr[0][0];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cin >> times;
    cout << solve();
}