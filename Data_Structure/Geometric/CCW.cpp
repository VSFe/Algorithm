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

int main() { //driver
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