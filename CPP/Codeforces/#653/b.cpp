#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int n, cnt = 0; cin >> n;
        bool success = true;
        while(n != 1) {
            if(n % 6 == 0) {
                cnt++;
                n /= 6;
            }
            else if(n % 3 == 0) {
                cnt++;
                n *= 2;
            }
            else {
                success = false;
                break;
            }
        }
        if(success) cout << cnt << '\n';
        else cout << -1 << '\n';
    }
}