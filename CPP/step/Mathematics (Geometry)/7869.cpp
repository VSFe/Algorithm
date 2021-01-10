#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double diff = (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    if(r1 < r2) swap(r1, r2);
    if(r1 + r2 <= diff) {
        printf("0.000\n");
        return 0;
    }
    
    if(abs(r1 - r2) >= diff) {
        printf("%.3f\n", acos(-1) * min(r1 * r1, r2 * r2));
        return 0;
    }
    
    double A = acos((diff * diff + r2 * r2 - r1 * r1) / (2 * diff * r2));
    double B = acos((diff * diff + r1 * r1 - r2 * r2) / (2 * diff * r1));
    double s = (r1 + r2 + diff) / 2;
    
    s = sqrt(s * (s - r1) * (s - r2) * (s - diff));
    double area = r1 * r1 * B + r2 * r2 * A - 2 * s;

    printf("%.3f\n",area);
}