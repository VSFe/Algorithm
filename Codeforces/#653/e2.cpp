#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> alice, bob, both, total;
    vector<bool> valid(n, true); 

    int tmp;
    bool is_alice, is_bob;

    for(int i = 0; i < n; i++) {
        cin >> tmp >> is_alice >> is_bob;
        if(is_alice && is_bob) both.push_back({tmp, i});
        else if(is_alice) alice.push_back({tmp, i});
        else if(is_bob) bob.push_back({tmp, i});
        total.push_back({tmp, i});
    }

    int both_size = max(0, 2 * k - m);

    if(both.size() + min(alice.size(), bob.size()) < k || both_size > both.size()) {
        cout << -1;
        return 0;
    }

    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    sort(total.begin(), total.end());

    int both_iter = 0, alice_iter = 0, bob_iter = 0;
    int ans = 0;
    vector<int> ans_idx;

    for(int i = 0; i < both_size; i++) {
        ans += both[both_iter].first;
        valid[both[both_iter].second] = false;
        ans_idx.push_back(both[both_iter++].second);
        k--;
    }

    while(k > 0) {
        if(both_iter >= both.size()) {
            for(int i = 0; i < k; i++) {
                ans += alice[alice_iter].first + bob[bob_iter].first;
                valid[alice[alice_iter].second] = false;
                valid[bob[bob_iter].second] = false;
                ans_idx.push_back(alice[alice_iter++].second);
                ans_idx.push_back(bob[bob_iter++].second);
            }
            break;
        }
        if(alice_iter >= alice.size() || bob_iter >= bob.size()) {
            for(int i = 0; i < k; i++) {
                ans += both[both_iter].first;
                valid[both[both_iter].second] = false;
                ans_idx.push_back(both[both_iter++].second);
            }
            break;
        }
        if(both[both_iter].first >= alice[alice_iter].first + bob[bob_iter].first) {
            ans += alice[alice_iter].first + bob[bob_iter].first;
            valid[alice[alice_iter].second] = false;
            valid[bob[bob_iter].second] = false;
            ans_idx.push_back(alice[alice_iter++].second);
            ans_idx.push_back(bob[bob_iter++].second);
        }
        else {
            ans += both[both_iter].first;
            valid[both[both_iter].second] = false;
            ans_idx.push_back(both[both_iter++].second);
        }
        k--;
    }
    
    int idx = 0;
    while(m > ans_idx.size()) {
        if(valid[total[idx].second]) {
            ans += total[idx].first;
            ans_idx.push_back(total[idx].second);
        }
        idx++;  
    }

    cout << ans << '\n';
    for(int i = 0; i < ans_idx.size(); i++) cout << ans_idx[i] + 1 << ' ';
}   