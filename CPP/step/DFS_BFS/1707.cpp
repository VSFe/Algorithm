#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20001];
int visited[20001];

bool dfs(int x, int flag) {
    visited[x] = flag;
    for(int next: graph[x]) {
        if(visited[next] == flag) return false;
        if(visited[next] == 0 && !dfs(next, 3 - flag)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC; cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int N, M; cin >> N >> M;

        for(int i = 0; i < N; i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                if(!dfs(i, 1)) {
                    flag = false;
                    break;
                }                
            }
        }
        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }    
}