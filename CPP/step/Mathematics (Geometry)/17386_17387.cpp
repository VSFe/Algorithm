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
    long long x, y;

    bool operator >= (const point &p) {
        if(x == p.x) return y >= p.y;
        return x >= p.x;
    }
};

int CCW(point &a, point &b, point &c) {
    long long X1 = b.x - a.x, X2 = c.x - a.x;
    long long Y1 = b.y - a.y, Y2 = c.y - a.y;
    long long result = X1 * Y2 - X2 * Y1;

    if(result > 0) return 1;
    else if(result) return -1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    point points[4];

    for(int i = 0; i < 4; i++) {
        long long x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    int t0 = CCW(points[0], points[1], points[2]) * CCW(points[0], points[1], points[3]);
    int t1 = CCW(points[2], points[3], points[0]) * CCW(points[2], points[3], points[1]);
 
    if(t0 == 1 || t1 == 1) cout << 0;
    else {
        if(t0 == 0 && t1 == 0) {
            if(points[0] >= points[1]) swap(points[0], points[1]);
            if(points[2] >= points[3]) swap(points[2], points[3]);
            if(points[3] >= points[0] && points[1] >= points[2]) cout << 1;
            else cout << 0;
        }
        else cout << 1;
    }
}