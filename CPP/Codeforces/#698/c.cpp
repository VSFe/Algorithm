#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long N; cin >> N;
    set<long long> s;
    long long size = 2 * N;
    bool flag = true;
    for(long long i = 0; i < size; i++) {
        long long tmp; cin >> tmp;
        if(tmp % 2) flag = false;
        s.insert(tmp / 2);
    }
    if(!flag || s.size() != N) {
        cout << "NO\n";
        return;
    }
    long long prev = 0;
    long long counter = 0;
    long long sum = 0;
    for(set<long long>::iterator iter = s.begin(); iter != s.end(); iter++) {
        if(iter == s.begin()) {
            prev = *iter;
        }
        else {
            if((*iter - prev) % counter) {
                flag = false;
                break;
            }
            sum += ((*iter - prev) / counter) * (N - counter);
        }
        prev = *iter;
        counter++;
    }
    if(flag) {
        if(sum >= *s.begin()) {
            flag = false;
        } else {
            long long tmp = *s.begin();
            tmp -= sum;
            if(tmp == 0 || tmp % N) {
                flag = false;
            }
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}