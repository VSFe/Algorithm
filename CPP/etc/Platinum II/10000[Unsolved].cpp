#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

stack<pair<pair<int, int>, bool>> st;
int N, ans = 0;
vector<pair<int, int>> vec;
vector<int> compress;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first; 
}

void preprocess() {
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for(int i = 0; i < N; i++) {
        vec[i].first = lower_bound(compress.begin(), compress.end(), vec[i].first) - compress.begin();
        vec[i].second = lower_bound(compress.begin(), compress.end(), vec[i].second) - compress.begin();
    }
    sort(vec.begin(), vec.end());
}

void solve() {
    int idx = 0;
    for(int i = 0; i < compress.size(); i++) {
        while(!st.empty()) {
            pair<int, int> p = st.top().first;
            if(p.second == i) {
                if(st.top().second) ans += 2;
                else ans += 1;
                st.pop();
            }
            else break;
        }
        while(idx != N) {
            if(vec[idx].first == i) {
                if(!st.empty()) st.top().second = true;
                st.push({vec[idx], false});
                idx++;
            }
            else break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back({x - y, x + y});
        compress.push_back(x - y), compress.push_back(x + y);
    }
    preprocess();
    solve();
    cout << ans;
}