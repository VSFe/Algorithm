#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int visited[100][100];
pair<int, int> b, r, finish;
char dt[10][10];

void print(char graph[][10]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << graph[i][j];
        }
        cout << '\n';
    }
}

int find_ans(pair<int, int> blue, pair<int, int> red, char graph[][10]) {
    int &ret = visited[red.first * 10 + red.second][blue.first * 10 + blue.second];
    if(ret != -1) return ret;
    ret = 10000;
    char tmp[10][10];
    bool red_first, is_answer;
    pair<int, int> f, s;

    //up
    red_first = (red.first < blue.first);
    if(red_first) f = red, s = blue;
    else f = blue, s = red;
    is_answer = false;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) tmp[i][j] = graph[i][j];
    tmp[f.first][f.second] = '.';
    while(f.first != 0) {
        if(tmp[f.first - 1][f.second] == '.') f.first--;
        else break;
    }
    if(f.first != 0 && tmp[f.first - 1][f.second] == 'O') is_answer = true;
    else tmp[f.first][f.second] = (red_first) ? 'R' : 'B';
    if(!(is_answer && !red_first)) {
        tmp[s.first][s.second] = '.';
        while(s.first != 0) {
            if(tmp[s.first - 1][s.second] == '.') s.first--;
            else break;
        }
        if(s.first != 0 && tmp[s.first - 1][s.second] == 'O') {
            if(!red_first) return ret = 1;
        }
        else if(is_answer && red_first) return ret = 1;
        else tmp[s.first][s.second] = red_first ? 'B' : 'R';
    }
    print(tmp);
    if(!is_answer) {
        if(red_first) ret = min(ret, find_ans(s, f, tmp) + 1);
        else ret = min(ret, find_ans(f, s, tmp) + 1);
    }

    //down
    red_first = (red.first > blue.first);
    if(red_first) f = red, s = blue;
    else f = blue, s = red;
    is_answer = false;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) tmp[i][j] = graph[i][j];
    tmp[f.first][f.second] = '.';
    while(f.first != N - 1) {
        if(tmp[f.first + 1][f.second] == '.') f.first++;
        else break;
    }
    if(f.first != N - 1 && tmp[f.first + 1][f.second] == 'O') is_answer = true;
    else tmp[f.first][f.second] = (red_first) ? 'R' : 'B';
    if(!(is_answer && !red_first)) {
        tmp[s.first][s.second] = '.';
        while(s.first != N - 1 ) {
            if(tmp[s.first + 1][s.second] == '.') s.first++;
            else break;
        }
        if(s.first != N - 1 && tmp[s.first + 1][s.second] == 'O') {
            if(!red_first) return ret = 1;
        }
        else if(is_answer && red_first) return ret = 1;
        else tmp[s.first][s.second] = red_first ? 'B' : 'R';
    }
    print(tmp);
    if(!is_answer) {
        if(red_first) ret = min(ret, find_ans(s, f, tmp) + 1);
        else ret = min(ret, find_ans(f, s, tmp) + 1);
    }

    //left
    red_first = (red.second < blue.second);
    if(red_first) f = red, s = blue;
    else f = blue, s = red;
    is_answer = false;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) tmp[i][j] = graph[i][j];
    tmp[f.first][f.second] = '.';
    while(f.second != 0) {
        if(tmp[f.first][f.second - 1] == '.') f.second--;
        else break;
    }
    if(f.second != 0 && tmp[f.first][f.second - 1] == 'O') is_answer = true;
    else tmp[f.first][f.second] = (red_first) ? 'R' : 'B';
    if(!(is_answer && !red_first)) {
        tmp[s.first][s.second] = '.';
        while(s.second != 0) {
            if(tmp[s.first][s.second - 1] == '.') s.second--;
            else break;
        }
        if(s.second != 0 && tmp[s.first][s.second - 1] == 'O') {
            if(!red_first) return ret = 1;
        }
        else if(is_answer && red_first) return ret = 1;
        else tmp[s.first][s.second] = red_first ? 'B' : 'R';
    }
    print(tmp);

    if(!is_answer) {
        if(red_first) ret = min(ret, find_ans(s, f, tmp) + 1);
        else ret = min(ret, find_ans(f, s, tmp) + 1);
    }

    //right
    red_first = (red.second > blue.second);
    if(red_first) f = red, s = blue;
    else f = blue, s = red;
    is_answer = false;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) tmp[i][j] = graph[i][j];
    tmp[f.first][f.second] = '.';
    while(f.second != M - 1) {
        if(tmp[f.first][f.second + 1] == '.') f.second++;
        else break;
    }
    if(f.second != M - 1 && tmp[f.first][f.second + 1] == 'O') is_answer = true;
    else tmp[f.first][f.second] = (red_first) ? 'R' : 'B';
    if(!(is_answer && !red_first)) {
        tmp[s.first][s.second] = '.';
        while(s.second != 0) {
            if(tmp[s.first][s.second + 1] == '.') s.second++;
            else break;
        }
        if(s.second != M - 1 && tmp[s.first][s.second + 1] == 'O') {
            if(!red_first) return ret = 1;
        }
        else if(is_answer && red_first) return ret = 1;
        else tmp[s.first][s.second] = red_first ? 'B' : 'R';
    }
    print(tmp);

    if(!is_answer) {
        if(red_first) ret = min(ret, find_ans(s, f, tmp) + 1);
        else ret = min(ret, find_ans(f, s, tmp) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < M; j++) {
            dt[i][j] = s[j];
            if(dt[i][j] == 'O') finish = {i, j};
            else if(dt[i][j] == 'R') r = {i, j};
            else if(dt[i][j] == 'B') b = {i, j};
        }
    }
    fill(&visited[0][0], &visited[99][99], -1);
    int answer = find_ans(b, r, dt);
    if(answer == 10000) cout << -1;
    else cout << answer;
}