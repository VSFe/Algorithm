#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> alice, bob, both;

    int tmp;
    bool is_alice, is_bob;

    for(int i = 0; i < n; i++) {
        cin >> tmp >> is_alice >> is_bob;
        if(is_alice && is_bob) both.push_back(tmp);
        else if(is_alice) alice.push_back(tmp);
        else if(is_bob) bob.push_back(tmp);
    }

    if(both.size() + min(alice.size(), bob.size()) < k) {
        cout << -1;
        return 0;
    }

    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    int both_iter = 0, alice_iter = 0, bob_iter = 0;
    int ans = 0;

    while(k > 0) {
        if(both_iter >= both.size()) {
            for(int i = 0; i < k; i++) {
                ans += alice[alice_iter] + bob[bob_iter];
                alice_iter++;
                bob_iter++;
            }
            break;
        }
        if(alice_iter >= alice.size() || bob_iter >= bob.size()) {
            for(int i = 0; i < k; i++) {
                ans += both[both_iter];
                both_iter++;
            }
            break;
        }
        if(both[both_iter] > alice[alice_iter] + bob[bob_iter]) {
            ans += alice[alice_iter] + bob[bob_iter];
            alice_iter++;
            bob_iter++;
        }
        else {
            ans += both[both_iter];
            both_iter++;
        }
        k--;
    }
    
    cout << ans;
}