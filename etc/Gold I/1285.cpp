#include <iostream>
using namespace std;

int N;
int dt[20];
char tmp;

int solve() {
    int ans = 400, MAX = 1 << N;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < N; i++) {
            if(i & (1 << j))
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num = 0;
        for(int j = 0; j < N; j++) {
            cin >> tmp;
            if(tmp == 'T') num |= (1 << j);
        }
        dt[i] = num;
    }


}