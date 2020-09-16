#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        map<int, int> m;
        long long n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            int mod = (k - tmp % k) % k;
            if(mod) {
                map<int, int>::iterator iter = m.find(mod);
                if(iter == m.end()) {
                    m.insert({mod, 1});
                } else {
                    (iter->second)++;
                }
            }
        }
        long long cycle = 0, num = 0;
        for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second > cycle) {
                cycle = iter->second;
                num = iter->first;
            } else if(iter->second == cycle && iter->first > num) {
                num = iter->first;
            }
        }
        if(!cycle) cout << 0 << '\n';
        else cout << (cycle - 1) * k + num + 1 << '\n';
    }
}