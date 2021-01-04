#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int dist[101][101];
int path[101][101];
int N, M;

void check(vector<int> &vec, int x, int y) {
    if(path[x][y] == 0) return;
    if(path[x][y] == y) {
        vec.push_back(y);
        return;
    }
    check(vec, x, path[x][y]);
    check(vec, path[x][y], y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(i != j) dist[i][j] = INF;        

    for(int i = 0; i < M; i++) {
        int x, y, d; cin >> x >> y >> d;
        if(dist[x][y] > d) {
            dist[x][y] = d;    
            path[x][y] = y;        
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }         
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(dist[i][j] != INF) cout << dist[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }

    vector<int> route;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            route.clear();
            check(route, i, j);
            if(route.empty()) cout << 0;
            else {
                cout << route.size() + 1<< ' ';
                cout << i << ' ';
                for(int i : route) cout << i << ' ';
            }
            cout << '\n';

        }
    }
}