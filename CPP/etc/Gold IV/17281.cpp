#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> stat[10];
int N;
int answer = 0;

void stage(int &out, int base[], int player, int inning) {
    switch (stat[player][inning]) {
        case 0:
            out++;
            break;
        case 1:
            base[3] += base[2];
            base[2] = base[1];
            base[1] = base[0];
            base[0] = 1;
            break;
        case 2:
            base[3] += base[2] + base[1];
            base[2] = base[0];
            base[1] = 1;
            base[0] = 0;
            break;
        case 3:
            base[3] += base[2] + base[1] + base[0];
            base[2] = 1;
            base[1] = base[0] = 0;
            break;
        case 4:
            base[3] += base[2] + base[1] + base[0] + 1;
            base[2] = base[1] = base[0] = 0;
            break; 
    }
}

int cal(int order[]) {
    int new_order[9];
    for(int i = 0; i < 3; i++) new_order[i] = order[i];
    new_order[3] = 1;
    for(int i = 4; i < 9; i++) new_order[i] = order[i - 1];

    int inning = 0;
    int base[4] = {0, 0, 0, 0};
    int out = 0;
    int player = 0;
    int score = 0;
    
    while(inning < N) {
        stage(out, base, new_order[player] - 1, inning);
        if(out == 3) {
            inning++;
            score += base[3];
            for(int i = 0; i < 4; i++) base[i] = 0;
            out = 0;
        }
        player = (player + 1) % 9;
    }

    return score;
}

void solve() {
    int order[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    do {
        answer = max(cal(order), answer);
    } while(next_permutation(order, order + 8));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
            int tmp; cin >> tmp;
            stat[j].push_back(tmp);
        }
    }

    solve();
    cout << answer;
}