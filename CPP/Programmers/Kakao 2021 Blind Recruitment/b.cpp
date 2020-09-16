#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> order, vector<int> course) {
    vector<string> answer;
    map<string, int> stat[11];

    for(string s: order) {
        sort(s.begin(), s.end());
        for(int i = 2; i <= s.size(); i++) {
            vector<int> ok;
            for(int j = 0; j < s.size() - i; j++) ok.push_back(0);
            for(int j = 0; j < i; j++) ok.push_back(1);

            do {
                string newS;
                for(int idx = 0; idx < ok.size(); idx++) {
                    if(ok[idx]) newS += s[idx]; 
                }

                map<string, int>::iterator iter = stat[i].find(newS);

                if(iter == stat[i].end()) stat[i].insert({newS, 1});
                else iter->second++;

            } while(next_permutation(ok.begin(), ok.end()));
        }
    }

    for(int i: course) {
        int MAX = 2;
        vector<string> vec;
        for(pair<string, int> p: stat[i]) {
            if(p.second == MAX) vec.push_back(p.first);
            else if(p.second > MAX) {
                MAX = p.second;
                vec.clear();
                vec.push_back(p.first);
            }
        }

        for(string s: vec) answer.push_back(s);
    }

    sort(answer.begin(), answer.end());
    return answer;
}

// Driver
int main() {
    int order_size, course_size;
    cin >> order_size >> course_size;
    vector<string> order(order_size);
    vector<int> course(course_size);
    for(int i = 0; i < order_size; i++)
        cin >> order[i];
    for(int j = 0; j < course_size; j++)
        cin >> course[j];

    vector<string> result = solution(order, course);

    for(string s: result) cout << s << ' ';
}