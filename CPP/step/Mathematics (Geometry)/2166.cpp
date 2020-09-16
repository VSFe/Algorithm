/*
Problem: 다각형의 면적 (2166)
Tier: Gold 5
Detail: 2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.
Comment: 유사 행렬식으로 풀면 됨.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct point {
    double x; double y;
    point(double x, double y) : x(x), y(y) { }
};

vector<point> vec;
double answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        vec.push_back(point(x, y));
    }
    vec.push_back(vec[0]);
    for(int i = 0; i < N; i++) {
        answer += vec[i].x * vec[i+1].y;
        answer -= vec[i+1].x * vec[i].y;
    }
    cout << fixed << setprecision(1) << fabs(answer) / 2;
}