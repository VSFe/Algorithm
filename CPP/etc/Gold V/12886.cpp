#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> visited;
int x, y, z;

pair<int, int> check(int x, int y) {
    if (x == y) return {x, y};
    if (x > y) return {x - y, y + y};
    return {x + x, y - x};
}

bool solve() {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited.insert({x, y});

    while (q.size()) {
        auto p = q.front(); q.pop();
        int datas[3] = {p.first, p.second, z - p.first - p.second};

        if (datas[0] == datas[1] && datas[1] == datas[2]) return true;

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                auto tmp = check(datas[i], datas[j]);

                swap(tmp.first, datas[i]); swap(tmp.second, datas[j]);
                if (visited.find({datas[i], datas[j]}) == visited.end()) {
                    q.push({datas[i], datas[j]});
                    visited.insert({datas[i], datas[j]});
                }
                swap(tmp.first, datas[i]); swap(tmp.second, datas[j]);
            }
        }

    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y >> z;

    z += x + y;
    cout << solve();
}