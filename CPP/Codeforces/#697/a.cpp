#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long x; cin >> x;
    while(x != 1) {
        if(x % 2 == 1) {
            cout << "YES\n";
            return;
        }
        x /= 2;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}