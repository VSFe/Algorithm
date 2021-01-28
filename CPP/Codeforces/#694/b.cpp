#include <bits/stdc++.h>
using namespace std;

void solution() {
    vector<pair<long long, long long>> vec;
    long long N, x; cin >> N >> x;
    for(long long i = 0; i < N; i++) {
        long long tmp; cin >> tmp;
        vec.push_back({tmp, 1});
    }

    long long cnt = 0;
    long long answer = 0;
    bool flag = true;
    while(cnt != vec.size()) {
        pair<long long, long long> p = vec[cnt];
        if(p.first % x == 0) {
            if(flag) {
                vec.push_back({p.first / x, p.second * x});
            }
        } else {
            flag = false;
        }

        answer += p.first * p.second;
        cnt++;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}