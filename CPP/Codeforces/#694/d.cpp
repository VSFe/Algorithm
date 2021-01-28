#include <bits/stdc++.h>
using namespace std;


void solution() {
    int N;    cin >> N;
    vector<long long> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];

    for(int j = 0; j < vec.size(); j++) {
        for(int i = sqrt(vec[j]) + 2; i >= 2; i--) {
            int mod = i * i;
            if(vec[j] % mod == 0) vec[j] /= mod;    
        }
    }

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        m.insert({vec[i], 0});
        m[vec[i]]++;
    }

    int first_answer = 0;
    int second_answer = 0;

    for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if(iter->first == 1) second_answer += iter->second;
        else if(iter->second % 2 == 0) second_answer += iter->second;
        first_answer = max(first_answer, iter->second);
    }

    int Q; cin >> Q;
    for(int i = 0; i < Q; i++) {
        long long tmp; cin >> tmp;
        if(tmp == 0) cout << first_answer << '\n';
        else cout << max(first_answer, second_answer) << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}