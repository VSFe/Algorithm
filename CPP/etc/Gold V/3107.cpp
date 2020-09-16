#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(string s) {
    vector<string> answers;
    int prevIdx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ':') continue;
        if(s[i + 1] == ':') {
            if(i != 0) {
                answers.push_back(s.substr(prevIdx, i - prevIdx));  
            }
            answers.push_back("-1");
            i++;
            prevIdx = i + 1;
        } else {
            answers.push_back(s.substr(prevIdx, i - prevIdx));  
            prevIdx = i + 1;
        }
    }
    if(prevIdx < s.size()) answers.push_back(s.substr(prevIdx));

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] != "-1") {
            int size = 4 - answers[i].size();
            for(int j = 0; j < size; j++) {
                answers[i] = '0' + answers[i];
            }
            cout << answers[i];
        }
        else {
            int size = 9 - answers.size();
            for(int i = 0; i < size; i++) {
                cout << "0000";
                if(i != size - 1) cout << ":";
            }
        }
        if(i != answers.size() - 1) cout << ':';         
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    solution(s);
}