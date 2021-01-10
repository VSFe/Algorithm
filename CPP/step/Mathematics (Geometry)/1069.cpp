#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, d, t; cin >> x >> y >> d >> t;
    double answer = sqrt(x * x + y * y);
    double path = answer;
    
    int cnt = path / d;
    path -= cnt * d;

    if(cnt == 0) {
        answer = min(answer, t + d - path);
        answer = min(answer, 2.0 * t);
    } else {
        answer = min(answer, cnt * t + path);
        answer = min(answer, (cnt + 1) * t);
    }

    cout.precision(15);
    cout << answer;
}