#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int SIZE = 100001;

int N, M;
int infected[SIZE];
int initial_infected[SIZE];
int numbers[SIZE];
bool isGroupInfected[SIZE];
bool isOk;
vector<int> group[SIZE];
vector<int> indivisualGroup[SIZE];

void solve() {
    memset(initial_infected, -1, sizeof(initial_infected));
    isOk = true;
    for(int i = M; i >= 1; i--) {
        bool flag = true;
        vector<int> candi;

        for(int idx : group[i]) {
            if(initial_infected[idx] == 1)
                candi.push_back(idx);

            if(initial_infected[idx] == -1) {
                if(numbers[i] == 0) {
                    initial_infected[idx] = 1;
                }
                else if(infected[idx]) {
                    isOk = false;
                    return;
                }
                else {
                    initial_infected[idx] = 0;
                }
            }
            else {
                if(numbers[i] != 0) {
                    initial_infected[idx] = 0;
                } else if(initial_infected[idx] == 0) {
                    flag = false;
                }
            }
        }

        if(!flag)
            for(int idx: candi) initial_infected[idx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int size; cin >> size;
        numbers[i] = size;
        for(int j = 0; j < size; j++) {
            int tmp; cin >> tmp;
            group[i].push_back(tmp);
            indivisualGroup[tmp].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        cin >> infected[i];
        if(infected[i]) {
            for(int idx : indivisualGroup[i]) {
                numbers[idx]--;
            }
        }
    }
    solve();
    if(!isOk) cout << "NO";
    else {
        cout << "YES\n";
        for(int i = 1; i <= N; i++) {
            if(initial_infected[i] == -1) cout << infected[i] << ' ';
            else cout << initial_infected[i] << ' ';
        }
    }
}