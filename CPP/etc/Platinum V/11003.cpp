#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L; cin >> N >> L;

    int tmp; cin >> tmp;
    dq.push_front({tmp, 1});
    cout << tmp << ' ';

    for(int i = 2; i <= L; i++) {
        cin >> tmp;
        if(dq.front().first >= tmp) dq.push_front({tmp, i});
        else dq.push_back({tmp, i});
        cout << dq.front().first << ' ';
    }

    for(int i = L + 1; i <= N; i++) {
        while(dq.front().second <= i - L) {
            dq.pop_front();
        }
        cin >> tmp;
        if(dq.front().first >= tmp) dq.push_front({tmp, i});
        else dq.push_back({tmp, i});
        cout << dq.front().first << ' ';
    }
}