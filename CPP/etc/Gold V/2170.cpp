/*
Problem: 선 긋기 (2170)
Tier: Gold 5
Detail: 매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다.
선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.
이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.
Comment: 가벼운 스위핑 문제. 단 한번 훑어서 끝낼 수 있도록 정렬을 하는건 필수.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    bool operator < (point &a) {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
};

int N;
point points[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(x >= y) points[i] = {y, x};
        else points[i] = {x, y};
    }
    sort(points, points + N);
    int start = -1000000000, end = -1000000000, ans = 0;
    for(int i = 0; i < N; i++) {
        if(points[i].x > end) {
            ans += (end - start);
            start = points[i].x;
            end = points[i].y;
        }
        else {
            end = max(end, points[i].y);
        }
    }
    cout << ans + (end - start);
}