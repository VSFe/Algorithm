#include <bits/stdc++.h>
using namespace std;


string solution(vector<int> &numbers) {
    string answer = "";
    
    vector<pair<string, int>> strs;
    for(int i = 0; i < numbers.size(); i++) {
        string s = to_string(numbers[i]);
        int size = s.size();
        while(s.size() < 10) s += s;
        strs.push_back({s.substr(0, 10), size});
    }
    
    sort(strs.begin(), strs.end(), greater<pair<string, int>>());
    for(pair<string, int> p : strs) answer += p.first.substr(0, p.second);
    while(answer.size() != 1 && answer[0] == '0') answer = answer.substr(1);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];

    cout << solution(vec);
}