/*
Problem: 히스토그램 (1725)
Tier: Gold 1
Detail: 각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.
이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.
주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.
Comment: 히스토그램에서 가장 큰 직사각형 (6549) 와 완전히 동일한 문제.
이번엔 스택으로 해봅시다.
각각의 막대 x를 높이를 하면서 만들 수 있는 가장 큰 직사각형을 찾는다.
즉 x의 왼쪽 막대 중 x보다 높이가 작고, 오른쪽 막대 중 x보다 높이가 작은 첫번째 막대 right를 찾아야 함.
*/

#define ll long long
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
ll dt[100000];
ll ans = 0;
stack<ll> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> dt[i];
    st.push(0);
    for(int i = 1; i < N; i++) {
        while(!st.empty() && dt[i] < dt[st.top()]) {
            ll tmp = st.top(); st.pop();
            ll left = (st.empty()) ? -1 : st.top();
            ans = max(ans, (i - left - 1) * dt[tmp]);
        }
        st.push(i);
    }
    while(!st.empty()) {
        ll tmp = st.top(); st.pop();
        ans = max(ans, (N - tmp) * dt[tmp]);
    }
    cout << ans;
}