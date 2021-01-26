#include <bits/stdc++.h>
using namespace std;

void solution() {
    int x, y; cin >> x >> y;
    vector<int> one, two, data;
    int cal = 0;
    for(int i = 0; i < x; i++) {
        int tmp; cin >> tmp;
        cal += tmp;
        data.push_back(tmp);
    }

    for(int i = 0; i < x; i++) {
        int tmp; cin >> tmp;
        if(tmp == 1) one.push_back(data[i]);
        else two.push_back(data[i]);
    }

    if(y > cal) {
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < 3; i++) {
        one.push_back(0);
        two.push_back(0);
    }

    sort(one.begin(), one.end(), greater<int>());
    sort(two.begin(), two.end(), greater<int>());

    int one_pos = 0, two_pos = 0, point = 0;
    while(point < y) {
        if(one[one_pos] + one[one_pos + 1] > two[two_pos]) {
            point += one[one_pos];
            one_pos++;
        } else if(one[one_pos] + point >= y) {
            point += one[one_pos];
            one_pos++;
        } else {
            point += two[two_pos];
            two_pos++;
        }
    }

    cout << one_pos + two_pos * 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}