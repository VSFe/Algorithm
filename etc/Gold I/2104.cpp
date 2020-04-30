/*
Problem: 부분배열 고르기 (2104)
Tier: Gold 1
Detail: 크기가 N(1≤N≤100,000)인 1차원 배열 A[1], …, A[N]이 있다. 어떤 i, j(1≤i≤j≤N)에 대한 점수는, (A[i]+…+A[j])×Min{A[i], …, A[j]}가 된다.
즉, i부터 j까지의 합에다가 i부터 j까지의 최솟값을 곱한 것이 점수가 된다.
배열이 주어졌을 때, 최대의 점수를 갖는 부분배열을 골라내는 프로그램을 작성하시오.
Comment: 히스토그램 문제와 유사하나, 실수가 너무 잦아서 스스로에게 열받았음...
*/


#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll ans = 0;
ll dt[100001], subsum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> dt[i];
    for(int i = 1; i <= N; i++) subsum[i] = subsum[i-1] + dt[i];
    stack<int> st;
    st.push(1);
    for(int i = 2; i <= N; i++) {
        while(!st.empty() && dt[i] < dt[st.top()]) {
            ll tmp = st.top(); st.pop();
            ll left = (st.empty()) ? 0 : st.top();
            ans = max(ans, (subsum[i-1] - subsum[left]) * dt[tmp]);
        }
        st.push(i);
    }
    while(!st.empty()) {
        ll tmp = st.top(); st.pop();
        ll left = (st.empty()) ? 0 : st.top();
        ans = max(ans, (subsum[N] - subsum[left]) * dt[tmp]);
    }
    cout << ans;
} 