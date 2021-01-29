#include <bits/stdc++.h>
using namespace std;

void solution() {
    int data[200] = {0, };
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int k; cin >> k;
        data[k]++;
    }

    int answer = 0;
    for(int i = 1; i <= 150; i++) {
        answer = max(answer, data[i]);
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}