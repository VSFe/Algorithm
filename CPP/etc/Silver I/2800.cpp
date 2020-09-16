#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    set<string> answers;
    stack<int> st;
    vector<pair<int, int>> pos;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')') {
            int tmp = st.top(); st.pop();
            pos.push_back({tmp, i});
        }
    }

    int size = pow(2, pos.size());
    for(int i = 0; i < size; i++) {
        string newStr = s;
        for(int j = 0; j < pos.size(); j++) {
            if(i & j) {
                newStr[pos[j].first] = ' ';
                newStr[pos[j].second] = ' ';
            }
        }
        answers.insert(newStr.erase(remove(newStr.begin(), newStr.end(), ' ')), newStr.end());
    }

}