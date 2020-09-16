/*
Problem: 2048(Easy) (12100)
Tier: Gold 2
Detail: 2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다.
이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. (실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)
이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
Comment: 빡구현...
*/

#include <iostream>
using namespace std;

int N, graph[20][20];

int dfs(int graph[][20]) {
    int max = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(max < graph[i][j]) max = graph[i][j];
        }
    }
    return max;
}

void process(int graph[][20], int cs) {
    int idx;
    bool prev_add = false;
    switch(cs) {
        case 1: // 위
            for(int i = 0; i < N; i++) {
                idx = 0;
                for(int j = 0; j < N; j++) {
                    if(idx != 0 && !prev_add && graph[i][idx-1] == graph[i][j]) {
                        graph[i][idx-1] *= 2;
                        graph[i][j] = 0;
                        prev_add = true;
                    }
                    else if(graph[i][j]) {
                        if(idx == j) idx++;
                        else {
                            graph[i][idx] = graph[i][j];
                            graph[i][j] = 0;
                            idx++;
                        }
                        prev_add = false;
                    }
                }
            }
            break;
        case 2: //아래
            for(int i = 0; i < N; i++) {
                idx = N - 1;
                for(int j = N - 1; j >= 0; j--) {
                    if(idx != N - 1 && !prev_add && graph[i][idx+1] == graph[i][j]) {
                        graph[i][idx+1] *= 2;
                        graph[i][j] = 0;
                        prev_add = true;
                    }
                    else if(graph[i][j]) {
                        if(idx == j) idx--;
                        else {
                            graph[i][idx] = graph[i][j];
                            graph[i][j] = 0;
                            idx--;
                        }
                        prev_add = false;
                    }
                }
            }
            break;
        case 3: // 위
            for(int i = 0; i < N; i++) {
                idx = 0;
                for(int j = 0; j < N; j++) {
                    if(idx != 0 && !prev_add && graph[idx-1][i] == graph[j][i]) {
                        graph[idx-1][i] *= 2;
                        graph[j][i] = 0;
                        prev_add = true;
                    }
                    else if(graph[j][i]) {
                        if(idx == j) idx++;
                        else {
                            graph[idx][i] = graph[j][i];
                            graph[j][i] = 0;
                            idx++;
                        }
                        prev_add = false;
                    }
                }
            }
            break;
        case 4: //아래
            for(int i = 0; i < N; i++) {
                idx = N - 1;
                for(int j = N - 1; j >= 0; j--) {
                    if(idx != N - 1 && !prev_add && graph[idx+1][i] == graph[j][i]) {
                        graph[idx+1][i] *= 2;
                        graph[j][i] = 0;
                        prev_add = true;
                    }
                    else if(graph[j][i]) {
                        if(idx == j) idx--;
                        else {
                            graph[idx][i] = graph[j][i];
                            graph[j][i] = 0;
                            idx--;
                        }
                        prev_add = false;
                    }
                }
            }
            break;
    }
}

int get_ans(int cnt, int graph[][20]) {
    int copy[20][20];
    int ans = 0;
    if(cnt == 5) return ans = max(ans, dfs(graph));
    for(int tc = 1; tc <= 4; tc++) {
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) copy[i][j] = graph[i][j];
        process(copy, tc);
        /*cout << "Process(" << cnt << ", " << tc << "): " << endl;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << copy[i][j] << " ";
            }
            cout << '\n';
        }*/
        ans = max(ans, get_ans(cnt + 1, copy));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];
    cout << get_ans(0, graph);
}