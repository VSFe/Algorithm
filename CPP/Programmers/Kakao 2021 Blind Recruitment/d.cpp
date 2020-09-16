#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[17];
int dist[17][17];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 0; i < 17; i++)
        for(int j = 0; j < 17; j++)
            dist[i][j] = 6e8;

    for(vector<int> edge: fares) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }

    for(int i = 0; i <= n; i++) dist[i][i] = 0;

    for(int k = 0; k <= n; k++) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    int answer = 6e8;

    for(int i = 0; i <= n; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }

    return answer;
}


// Driver
int main() {
    int N, S, A, B, size;
    cin >> N >> S >> A >> B >> size;

    vector<vector<int>> fares(size, vector<int>(3));
    for(int i = 0; i < size; i++)
        cin >> fares[i][0] >> fares[i][1] >> fares[i][2];

    cout << solution(N, S, A, B, fares);
}