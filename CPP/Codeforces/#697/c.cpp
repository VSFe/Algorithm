#include <bits/stdc++.h>
using namespace std;

void solution() {
    int a, b, t;
    cin >> a >> b >> t;
    vector<long long> A(a + 1);
    vector<long long> B(b + 1);
    vector<int> as, bs;
    for(int i = 0; i < t; i++) {
        int tmp; cin >> tmp;
        A[tmp]++;
        as.push_back(tmp);
    }
    for(int i = 0; i < t; i++) {
        int tmp; cin >> tmp;
        B[tmp]++;
        bs.push_back(tmp);
    }

    long long answer = 0;

    for(int i = 0; i < t; i++) {
        answer += t - A[as[i]] - B[bs[i]] + 1;
    }

    cout << answer / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}