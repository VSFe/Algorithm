#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long a, b; cin >> a >> b;
    if(a > b) {
        int answer = 1;
        if(a % b) answer++;
        cout << answer << '\n';
        return;
    }
    long long answer = b / a;
    if(b % a) answer++;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}