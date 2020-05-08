/*
Problem: 격자점 컨벡스헐 (2699)
Tier: Gold 1
Detail: 정수좌표를 갖는 점을 격자점이라고 한다. 격자 다각형은 모든 꼭짓점이 격자점으로 이루어진 다각형이다.
만약, 다각형의 두 꼭짓점을 잇는 모든 선분이 다각형 내부(또는 경계)에 있다면, 이 다각형을 볼록 다각형이라고 한다. 즉, 다각형의 내부각이 모두 180도 보다 작은 것이다.
격자점으로 이루어진 집합 S가 주어졌을 때, S의 모든 격자점을 포함하는 가장 작은 볼록 (격자) 다각형을 컨벡스 헐이라고 한다. 컨벡스 헐의 꼭짓점은 모두 S에 포함된 격자점이어야 한다. 만약, 모든 점이 같은 일직선 상에 있다면, 컨벡스 헐은 선분이 될 것이다. (오른쪽 그림)
아래 그림에서 집합에 포함된 점은 굵은 점으로, 컨벡스 헐의 꼭짓점은 X로, 변은 선분으로 나타낸 그림이다.
격자 다각형의 꼭짓점의 일반적인 순서는 다음과 같다.
    첫 번째 꼭짓점은 y좌표가 가장 큰 점이다. 만약, 그러한 점이 2개라면, x가 작은 점이 첫 번째 점이다.
    그 다음 점부터는 시계방향 순서이다.
격자점의 집합이 주어졌을 때, 컨벡스 헐을 일반적인 순서로 출력하는 프로그램을 작성하시오.
Comment: 그라함 스캔 알고리즘.
어차피 컨벡스 헐 구할때 시계방향으로 돌리던 반시계방향으로 돌리던 하니 그거에 맞춰 스택에 있는 값을 잘 꺼내기만 하면 해결.
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
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
        if(y != O.y) return y > O.y;
        return x < O.x;
    }
};

int TC, N;

int CCW(point &x, point &y, point &z) {
    long long cal = (y.x - x.x) * (z.y - x.y) - (y.y - x.y) * (z.x - x.x);
    if(cal == 0) return 0;
    else if(cal > 0) return 1; //CCW
    else return -1; //CW
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
    cin >> N;
    point points[51];
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
    stack<int> st;
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
    int size = st.size() - 1;
    vector<point> vec(size);
    for(int i = 0; i < size; i++) {
        vec[i] = points[st.top()]; st.pop();
    }
    cout << size + 1 << '\n';
    cout << points[st.top()].x << ' ' << points[st.top()].y << '\n';
    for(int i = 0; i < size; i++) cout << vec[i].x << ' ' << vec[i].y << '\n';
    }
}