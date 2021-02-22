#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<long long, bool> number[10];
int N;
int selected[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) {
            int idx = s[j] - 'A';
            number[idx].first += pow(10, s.size() - 1 - j);
            if(j == 0) number[idx].second = true;
        }
    }

    sort(number, number + 10);
    long long answer = 0;
    for(auto node: number) {
        for(int i = 0; i < 10; i++) {
            if(node.second && i == 0) continue;
            if(!selected[i]) {
                answer += i * node.first;
                selected[i] = true;
                break;
            }
        }
    }
    cout << answer;
}