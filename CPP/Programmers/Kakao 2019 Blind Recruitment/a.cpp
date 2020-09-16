#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<string, bool>> history;
    vector<string> result;
    map<string, string> m;
    
    for(string s: record) {
        int prevIdx = 0;
        vector<string> data;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') continue;
            string tmp = s.substr(prevIdx, i - prevIdx);
            data.push_back(tmp);
            prevIdx = i + 1;
         } data.push_back(s.substr(prevIdx));
        
        map<string, string>::iterator iter = m.find(data[1]);
        if(iter == m.end()) {
            m.insert({data[1], data[2]});
            iter = m.find(data[1]);
        }
        
        if(data[0] == "Enter") {
            history.push_back({data[1], 0});
            iter->second = data[2];
        } else if(data[0] == "Leave") {
            history.push_back({data[1], 1});
        } else{
            iter->second = data[2];
        }
    }
    
    for(pair<string, bool> p : history) {
        string tmp = m[p.first];
        if(p.second == 0) result.push_back(tmp + " 님이 들어왔습니다.");
        else result.push_back(tmp + " 님이 나갔습니다.");
    }
    
    return result;
}

// Driver
int main() {
    int N; cin >> N;
    vector<string> vec;
    string s; 
    getline(cin, s);
    for(int i = 0; i < N; i++) {
        getline(cin, s);
        vec.push_back(s);
    }

    vector<string> result = solution(vec);
    for(string str: result) cout << str << endl;
}