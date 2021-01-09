/*
Problem: CCW (11758)
Tier: Gold 5
Detail: 2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.
Comment: 처음에 공부할 때는 어디다 써먹냐 했는데 기하에서 너무너무 중요한 부분이었다...
꼭 기억하자!
*/

#include <iostream>
using namespace std;

int CCW(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
    int x1 = y.first - x.first, x2 = z.first - x.first;
    int y1 = y.second - x.second, y2 = z.second - x.second;
    return x1 * y2 - x2 * y1;
}

int main() {
    pair<int, int> x, y, z;
    cin >> x.first >> x.second;
    cin >> y.first >> y.second;
    cin >> z.first >> z.second;

    int result = CCW(x, y, z);
    if(result > 0) cout << 1;
    else if (result == 0) cout << 0;
    else cout << -1;
}