#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long double a, b, c;
    cin >> a >> b >> c;
    long double ans[5];
    long double s = (a + b + c) / 2;
    ans[0] = sqrt(s * (s - a) * (s - b) * (s - c));
    ans[1] = a * b * c / (4 * ans[0]);
    ans[2] = 2 * ans[0] / (a + b + c);
    ans[3] = max((long double)(0.0), sqrt(ans[1] * (ans[1] - 2 * ans[2])));
    ans[4] = ans[1] + ans[2];
    cout << fixed;
    cout.precision(20);
    for(int i = 0; i < 5; i++) cout << ans[i] << '\n';
}