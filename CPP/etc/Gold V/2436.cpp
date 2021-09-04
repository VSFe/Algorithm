#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int gcd, lcm;
int x = INF, y = INF;

int get_gcd(int x, int y) {
    if (x % y == 0) return y;
    return get_gcd(y, x % y);
}

int main() {
    cin >> gcd >> lcm;

    int x_y = lcm / gcd;
    int size = sqrt(x_y) + 1;

    for (int i = 1; i <= size; i++) {
        if (x_y % i == 0) {
            if (get_gcd(i, x_y / i) != 1) continue;

            int tmp_X = i * gcd;
            int tmp_Y = x_y / i * gcd;
            if (tmp_X + tmp_Y < x + y) {
                x = tmp_X;
                y = tmp_Y;
            }
        }
    }

    cout << x << ' ' << y;
}