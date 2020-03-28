/*
Problem: 선분 교차 1, 2 (17386. 17387)
Tier: Gold 4, 3
Detail: 2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.
L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.
Comment: CCW를 활용!
(CCW 계산 과정에서 int 범위를 너무 가볍게 초과하는데, 이 부분에 한 해 long long을 박아줘야 정상적으로 작동됨.)
*/

#include <iostream>
using namespace std;

struct point {
    int x; int y;
    point() {}
    point(int x, int y) : x(x), y(y) { }
    bool operator >= (point& p2) {
        if(x == p2.x && y == p2.y) return true;
        else if(x == p2.x) return (y >= p2.y);
        return (x >= p2.x);
    } 
    bool operator == (point& p2) {
        return (x == p2.x && y == p2.y);
    }
};

int CCW(point &x, point &y, point &z) {
    long long cal = (long long)(y.x - x.x) * (long long)(z.y - x.y) - (long long)(y.y - x.y) * (long long)(z.x - x.x);
    if(cal == 0) return 0;
    else if(cal > 0) return 1; //CCW
    else return -1; //CW
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    point points[4];
    for(int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = point(x, y);
    }
    long long t1 = CCW(points[0], points[1], points[2]) * CCW(points[0], points[1], points[3]);
    long long t2 = CCW(points[2], points[3], points[0]) * CCW(points[2], points[3], points[1]);
    if(t1 <= 0 && t2 <= 0) {
        if(t1 == 0 && t2 == 0) {
            if(points[0] == points[2] || points[0] == points[3] || points[1] == points[2] || points[1] == points[3] ) cout << 1;
            else if(points[0] >= points[3]) cout << (points[2] >= points[1]) ? 0 : 1; 
            else cout << (points[1] >= points[2]) ? 0 : 1;
        } else cout << 1;
    } else cout << 0;
    return 0;
}