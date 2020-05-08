/*
Problem: 볼록 껍질 (1708)
Tier: Gold 1
Detail: 다각형의 임의의 두 꼭짓점을 연결하는 선분이 항상 다각형 내부에 존재하는 다각형을 볼록 다각형이라고 한다. 아래 그림에서 (a)는 볼록 다각형이며, (b)는 볼록 다각형이 아니다.
조금만 생각해 보면 다각형의 모든 내각이 180도 이하일 때 볼록 다각형이 된다는 것을 알 수 있다. 편의상 이 문제에서는 180도 미만인 경우만을 볼록 다각형으로 한정하도록 한다.
2차원 평면에 N개의 점이 주어졌을 때, 이들 중 몇 개의 점을 골라 볼록 다각형을 만드는데, 나머지 모든 점을 내부에 포함하도록 할 수 있다. 이를 볼록 껍질 (CONVEX HULL) 이라 한다.
점의 집합이 주어졌을 때, 볼록 껍질을 이루는 점의 개수를 구하는 프로그램을 작성하시오.
Comment: 그라함 스캔 알고리즘.
1LL*q*O.p != 1LL*p*O.q의 의미를 잘 생각해두자.
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct point{
    int x, y; // 실제 위치
    int p, q; // 기준점으로부터의 상대 위치
    point(): point(0, 0, 1, 0){}
    point(int x1, int y1): point(x1, y1, 1, 0){}
    point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
    // p, q 값을 기준으로 정렬하기 위한 관계연산자
    bool operator <(const point& O){
        if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
} points[100000];

stack<int> st;
int N;

int CCW(point &x, point &y, point &z) {
    long long cal = (y.x - x.x) * (z.y - x.y) - (y.y - x.y) * (z.x - x.x);
    if(cal == 0) return 0;
    else if(cal > 0) return 1; //CCW
    else return -1; //CW
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = point(x, y);
    }
    sort(points, points + N);
    for(int i = 1; i < N; i++) {
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
    sort(points + 1, points + N);
    st.push(0);
    st.push(1);
    int next = 2;
    while(next < N) {
        while(st.size() >= 2) {
            int first = st.top(); st.pop();
            int second = st.top();
            if(CCW(points[second], points[first], points[next]) > 0) {
                st.push(first);
                break;
            }
        }
        st.push(next++);
    }
    cout << st.size();
}