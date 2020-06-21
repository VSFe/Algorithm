#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 500000;
int bfs[MAX + 1][2];
int N, K, add = 0, ans = MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    memset(bfs, -1, sizeof(bfs));
    bfs[N][0] = 0;

    queue<pair<int, int>> q;
    q.push({N, 0});

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;

        if(x + 1 <= MAX && bfs[x + 1][(y + 1) % 2] == -1) {
            bfs[x + 1][(y + 1) % 2] = bfs[x][y] + 1;
            q.push({x + 1, (y + 1) % 2});
        } 
        if(x - 1 >= 0 && bfs[x - 1][(y + 1) % 2] == -1) {
            bfs[x - 1][(y + 1) % 2] = bfs[x][y] + 1;
            q.push({x - 1, (y + 1) % 2});
        }
        if(x * 2 <= MAX && bfs[x * 2][(y + 1) % 2] == -1) {
            bfs[x * 2][(y + 1) % 2] = bfs[x][y] + 1;
            q.push({x * 2, (y + 1) % 2});
        }
    }

    while(K <= MAX) {
        if(bfs[K][add % 2] <= add) {
            int tmp = max(bfs[K][add % 2], add);
            ans = min(ans, tmp);
        }
        add++;
        K += add;
    }

    if(ans == MAX) cout << -1;
    else cout << ans;
} 