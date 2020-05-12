#include <iostream>
using namespace std;

int N, MAX = 0, visited[10][10];

void cal(int cnt) {
    int tmp[10][10];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) {
                cnt++;
                MAX = max(MAX, cnt);
                for(int x = 0; x < N; x++) for(int y = 0; y < N; y++) tmp[x][y] = visited[x][y];
                int size = i + j;
                for(int k = 0; k < size; k++) {
                    if(size - k >= N || k >= N) continue;
                    visited[k][size - k] = 0;
                }
                if(i > j) {
                    int size = N - (i - j);
                    for(int k = 0; k < size; k++) visited[k + i - j][k] = 0;
                }
                else {
                    int size = N - (j - i);
                    for(int k = 0; k < size; k++) {
                        visited[k + j - i][k] = 0;  
                    } 
                }
                cal(cnt);
                for(int x = 0; x < N; x++) for(int y = 0; y < N; y++) visited[x][y] = tmp[x][y];
                cnt--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> visited[i][j];
        }
    }
    cal(0);
    cout << MAX;
}