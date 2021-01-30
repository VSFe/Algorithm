#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long n;
    double k; cin >> n >> k;
    vector<long long> vec(n + 1);
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        long long tmp; cin >> tmp;
        vec[i + 1] = vec[i] + tmp;
    }

    for(int i = 2; i <= n; i++) {
        long long left = (vec[i] - vec[i - 1]) * 100;
        long long right = (vec[i - 1] + answer) * k;
        double diff = left - right;
        if(diff < 0) continue;
        answer += ceil(diff / k);
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}