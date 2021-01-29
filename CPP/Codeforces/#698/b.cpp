#include <bits/stdc++.h>
using namespace std;
 
void solution() {
    int q, d; cin >> q >> d;
    set<int> s;
    for(int i = 0; i < d; i++) {
        int tmp = i * 10 + d;
        while(tmp < d * 10) {
            s.insert(tmp);
            tmp += d;
        }
    }
 
    for(int i = 0; i < q; i++) {
        int tmp; cin >> tmp;
        if(tmp >= 10 * d) cout << "YES\n";
        else if(s.find(tmp) != s.end()) cout << "YES\n";
        else cout << "NO\n";
    }
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}