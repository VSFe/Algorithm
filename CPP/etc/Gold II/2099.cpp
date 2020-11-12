#include <bits/stdc++.h>
using namespace std;

int n, k, m;

bool isOk(int i, int j, vector<vector<bool>> &A, vector<vector<bool>> &B) {
    bool result = false;
    for(int x = 0; x < n; x++) {
        if(A[i][x] && B[x][j])
            result = true;
    }

    return result;
}

void multi(vector<vector<bool>> &A, vector<vector<bool>> &B) {
    vector<vector<bool>> tmp = vector<vector<bool>>(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = isOk(i, j, A, B);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            B[i][j] = tmp[i][j];
}

void deathOrLife(vector<vector<bool>> &arr) {
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if(arr[x - 1][y - 1]) cout << "death" << '\n';
        else cout << "life" << '\n';
    }
}

void solve() {
    vector<vector<bool>> arr = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<vector<bool>> arr_multi = vector<vector<bool>>(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++)
        arr[i][i] = true;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr_multi[i][x - 1] = 1;
        arr_multi[i][y - 1] = 1;
    }

    while(k != 0) {
        if(k % 2 == 1) {
            multi(arr_multi, arr);
            k--;
        } else {
            multi(arr_multi, arr_multi);
            k /= 2;
        }
    }

    deathOrLife(arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> m;
    solve();
}