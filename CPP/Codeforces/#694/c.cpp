#include <bits/stdc++.h>
using namespace std;

void solution() {
    int N, M; cin >> N >> M;
    vector<int> friends(N);
    for(int i = 0; i < N; i++) cin >> friends[i];
    vector<int> prices(M);
    for(int i = 0; i < M; i++) cin >> prices[i];
    sort(friends.begin(), friends.end(), greater<int>());
    
    long long answer = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(friends[i] > cnt) {
            answer += prices[cnt++];
        } else {
            answer += prices[friends[i] - 1];
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}