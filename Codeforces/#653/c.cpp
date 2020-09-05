#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int size, ans = 0, tmp = 0;
        string s;
        cin >> size >> s;
        for(int i = 0; i < size; i++) {
            if(s[i] == '(') tmp++;
            else {
                if(tmp) tmp--;
                else ans++;
            }
        }
        cout << ans << '\n';
    }
}