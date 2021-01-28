#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long N, X; cin >> N >> X;
    long long mini = 0, maxi = 0, total = 0;
    for(long long i = 0; i < N; i++) {
        long long tmp; cin >> tmp;
        total += tmp;
        maxi += tmp / X;
        if(tmp % X) maxi++;
    }

    mini += total / X;
    if(total % X) mini += 1;

    cout << mini << ' ' << maxi << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}