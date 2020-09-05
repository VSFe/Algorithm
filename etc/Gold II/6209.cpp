#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d, n, m, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> n >> m;
    ans = d;

    vector<int> stones(n + 2);
    for(int i = 0; i < n; i++) cin >> stones[i];
    stones[n] = 0;
    stones[n + 1] = d;

    sort(stones.begin(), stones.end());

    int left = 0, right = ans;

    while(left < right) {
        ans = (left + right + 1) / 2;
        int cnt = 0, idx = 0;
        for(int i = 0; i <= n; i++) {
            if(stones[i + 1] - stones[idx] < ans) {
                cnt++;
            } else {
                idx = i + 1;
            }
        }

        if(cnt > m) right = ans - 1;
        else left = ans;
    }

    int mini = d;
    int cnt = 0, idx = 0;
    for(int i = 0; i <= n; i++) {
        if(stones[i + 1] - stones[idx] >= ans) {
            mini = min(mini, stones[i + 1] - stones[idx]);
            idx = i + 1;
        }
    }

    cout << mini;
}