#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll MAX = 0;
ll dt[100001], subsum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> dt[i];
    for(int i = 1; i <= N; i++) subsum[i] = subsum[i-1] + dt[i];
    stack<pair<int, int>> st;
    st.push({dt[1], 1});
    for(int i = 2; i <= N; i++) {
        pair<int, int> p = st.top();
        while(p.first > dt[i]) {
            st.pop();
            int start = (st.empty()) ? 0 : st.top().second, end = i - 1;
            MAX = max(MAX, (subsum[end] - subsum[start]) * (ll)(p.first));
            if(st.empty()) break;
            p = st.top();
        }
        st.push({dt[i], i});
    }
    int start, end = N;
    while(!st.empty()) {
        pair<int, int> p = st.top(); st.pop();
        start = (st.empty()) ? 0 : st.top().second;
        MAX = max(MAX, (subsum[end] - subsum[start]) * (ll)(p.first));
        end = p.second - 1;
    }
    cout << MAX;
}