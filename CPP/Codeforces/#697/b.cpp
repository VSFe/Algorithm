#include <bits/stdc++.h>
using namespace std;

void solution() {
    int x; cin >> x;
    int asda = x / 2020;
    int mod = x % 2020;
    if(asda >= mod) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}