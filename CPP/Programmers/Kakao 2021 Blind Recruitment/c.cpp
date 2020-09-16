#include <bits/stdc++.h>
using namespace std;

map<string, int> finder[4];

void initial() {
    finder[0]["cpp"] = 0;
    finder[0]["java"] = 1;
    finder[0]["python"] = 2;

    finder[1]["backend"] = 0;
    finder[1]["frontend"] = 1;

    finder[2]["junior"] = 0;
    finder[2]["senior"] = 1;

    finder[3]["chicken"] = 0;
    finder[3]["pizza"] = 1;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> score[25];

    initial();

    for(string s: info) {
        int idx = 0;
        vector<string> preprocessed;

        int prevIdx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                preprocessed.push_back(s.substr(prevIdx, i - prevIdx));
                prevIdx = i + 1;
            }
        }
        int point = stoi(s.substr(prevIdx));

        for(int i = 0; i < 4; i++) {
            int tmp = finder[i].find(preprocessed[i])->second;
            idx += pow(2, (3 - i)) * tmp;
        }

        score[idx].push_back(point);
    }

    for(int i = 0; i < 25; i++) sort(score[i].begin(), score[i].end());

    for(string s: query) {
        int restricted[4] = {-1, -1, -1, -1};
        vector<string> preprocessed;
        int sum = 0;

        int prevIdx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                string tmp = s.substr(prevIdx, i - prevIdx);
                if(tmp != "and")
                    preprocessed.push_back(s.substr(prevIdx, i - prevIdx));
                prevIdx = i + 1;
            }
        }
        int point = stoi(s.substr(prevIdx));

        for(int i = 0; i < 4; i++) {
            if(preprocessed[i] == "-") continue;
            restricted[i] = finder[i].find(preprocessed[i])->second;
        }

        for(int i = 0; i < 24; i++) {
            bool isOk = true;
            int idx = i;
            for(int j = 0; j < 4; j++) {
                if(restricted[j] != -1) {
                    if(int(idx / pow(2, 3 - j)) != restricted[j]) {
                        isOk = false;
                        break;
                    } 
                }
                idx = int(idx % int(pow(2, 3 - j)));
            }

            if(isOk) {
                sum += score[i].size() - int(lower_bound(score[i].begin(), score[i].end(), point) - score[i].begin());
            }
        }

        answer.push_back(sum);
        /*
        전부 검색 가능한 구조??
        */
    }

    return answer;
}


// Driver
int main() {
    int info_size, query_size;
    cin >> info_size >> query_size;

    vector<string> info(info_size);
    vector<string> query(query_size);

    cin.ignore();
    for(int i = 0; i < info_size; i++) {
        getline(cin, info[i]);
    }

    cin.ignore();
    for(int j = 0; j < query_size; j++) {
        getline(cin, query[j]);
    }

    vector<int> answer = solution(info, query);
    for(int i : answer) cout << i << ' '; 
}