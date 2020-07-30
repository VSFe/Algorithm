#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int x, y, n;
        cin >> x >> y >> n;
        int md = n % x;
        if(md < y) md += x;
        if(md > y) n -= (md - y);
        cout << n << '\n';
    }
}