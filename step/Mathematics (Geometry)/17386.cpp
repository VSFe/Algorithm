/*
Problem: 선분 교차 (17386)
Tier: Gold 4
Detail: 2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.
L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.
Comment: 직선의 방정식을 만들어서 대소관계 비교!
*/
#define delta 0.0000001
#include <iostream>
#include <cmath>
using namespace std;

struct point {
    double x, y;
    point() : x(0), y(0) {}
    point(double x, double y) : x(x), y(y) {}
};

struct line{
    double a, b, c;
    line() : a(0), b(0), c(0) {}
    line(point p1, point p2) {
        if(p1.x == p2.x) {
            a = 1; b = 0;
            c = -p1.x;
        }
        else {
            b = 1;
            a = (p2.y - p1.y) / (p1.x - p2.x);
            c = -(a * p1.x + p1.y);
        }
    }
};

double value(line &li, point &po) {
    return (li.a * po.x + li.c) / -(li.b);
}

int main() {
    point points[4];
    line standard[2];
    for(int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = point(x, y);
    }
    standard[0] = line(points[0], points[1]), standard[1] = line(points[2], points[3])
    standard = line(points[0], points[1]);
    if(value(standard, points[2]) < points[0].y ^ value(standard, points[3]) < points[1].y) cout << 1;
    else cout << 0;
    return 0;
}