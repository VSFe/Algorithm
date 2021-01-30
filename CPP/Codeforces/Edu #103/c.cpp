#include <bits/stdc++.h>
using namespace std;

void solution() {

    long long n;
    vector<long long> elem;
    vector<long long> a, b;
    vector<pair<long long, long long>> p;
    cin >> n;long long tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        elem.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }    
    long long answer = 0;
    long long prev = elem[0];
    bool flag = true;

    for(int i = 1; i < n; i++) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(a[i] == b[i]) {
            prev = 1;
        }
        else {
            prev -= elem[i - 1];
            if(flag)  {
                prev += b[i] - a[i] + 1;
                flag = false;
            }
            else {
                prev += elem[i - 1] + 1 - (b[i] - a[i]);
                prev = max(prev, b[i] - a[i] + 1);
            }
        }
        answer = max(answer, prev + elem[i]); 
        prev += elem[i];
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}