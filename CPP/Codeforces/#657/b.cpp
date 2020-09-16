#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int l, r, m;
        cin >> l >> r >> m;
        int MAX = m + r - l;
        int MIN = m + l - r;
        for(int a = l; a <= r; a++) {
            if(MAX / a != MIN / a) {
                int n = MIN / a + 1;
                int ans = m - n * a;
                cout << a << ' ' << r + ans << ' ' << r << '\n';
                break;
            }
            else if(MIN / a == 0) {
                int n = MIN / a;
                int ans = m - n * a;
                cout << a << ' ' << r + ans << ' ' << r << '\n';
                break;
            }
        }
    }
}