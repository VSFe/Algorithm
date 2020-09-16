/*
Problem: CCW (11758)
Tier: Gold 5
Detail: 2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.
Comment: 처음에 공부할 때는 어디다 써먹냐 했는데 기하에서 너무너무 중요한 부분이었다...
꼭 기억하자!
*/

#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x; int y;
    point() {}
    point(int x, int y) : x(x), y(y) { }
};

int CCW(point &x, point &y, point &z) {
    int cal = (y.x - x.x) * (z.y - x.y) - (y.y - x.y) * (z.x - x.x);
    if(cal == 0) return 0;
    else if(cal > 0) return 1; //CCW
    else return -1; //CW
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<point> points(3);
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = point(x, y);
    }
    cout << CCW(points[0], points[1], points[2]);
    return 0;
}