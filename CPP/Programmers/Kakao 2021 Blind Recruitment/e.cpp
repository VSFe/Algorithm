#include <bits/stdc++.h>

using namespace std;

int convertTime(string s) {
    int time = 0;
    time += stoi(s.substr(0, 2)) * 3600;
    time += stoi(s.substr(3, 2)) * 60;
    time += stoi(s.substr(6, 2));

    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playTime = convertTime(play_time), advTime = convertTime(adv_time);
    vector<int> isPlay(playTime + 2, 0);
    vector<long long> totalViewer(playTime + 1, (long long)(0));

    for(string s: logs) {
        int startTime = convertTime(s.substr(0, 8));
        int endTime = convertTime(s.substr(9));

        isPlay[startTime]++;
        isPlay[endTime]--;
    }

    long long view = isPlay[0];
    totalViewer[0] = view;

    for(int i = 1; i <= playTime; i++) {
        view += isPlay[i];
        totalViewer[i] = totalViewer[i - 1] + view;
    }

    long long MAX = totalViewer[advTime];
    int MAX_idx = 0;
    int size = playTime - advTime;
    for(int i = 1; i <= size; i++) {
        if(MAX < totalViewer[i + advTime - 1] - totalViewer[i - 1]) {
            MAX = totalViewer[i + advTime - 1] - totalViewer[i - 1];
            MAX_idx = i;
        }
    }

    int startTime = MAX_idx;
    string answer = "";
    vector<int> answers;
    for(int i = 0; i < 3; i++) {
        answers.push_back(startTime / pow(60, 2 - i));
        startTime = startTime % int(pow(60, 2 - i));
    }

    for(int j = 0; j < 3; j++) {
        if(answers[j] / 10 == 0) answer += "0";
        answer += to_string(answers[j]);
        if(j != 2) answer += ":";
    }

    return answer;
}

// Driver
int main() {
    string play_time, adv_time;
    cin >> play_time >> adv_time;
    int size; cin >> size;

    vector<string> logs(size);
    for(int i = 0; i < size; i++) cin >> logs[i];

    cout << solution(play_time, adv_time, logs);
}