/*
Problem: 환승 (5214)
Tier: Gold 1
Detail: 아주 먼 미래에 사람들이 가장 많이 사용하는 대중교통은 하이퍼튜브이다. 하이퍼튜브 하나는 역 K개를 서로 연결한다. 1번역에서 N번역으로 가는데 방문하는 최소 역의 수는 몇 개일까?
Comment: 일반적인 그래프 탐색 문제와 조금 다른 문제. 두개를 구분해서 visited 배열을 만들어 두면 충분히 BFS로 해결할 수 있다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tube[1001];
vector<int> pos[100001];
int visited_pos[100001], visited_tube[1001];
int N, K, M, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> M;

    for(int i = 0 ; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> tmp;
            tube[i].push_back(tmp);
            pos[tmp].push_back(i);
        }
    }
    queue<int> q;
    q.push(1);
    visited_pos[1] = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int t = q.front(); q.pop();
            for(auto next : pos[t]) {
                if(visited_tube[next]) continue;
                visited_tube[next] = 1;
                for(auto tmp : tube[next]) {
                    if(!visited_pos[tmp]) {
                        visited_pos[tmp] = visited_pos[t] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    if(!visited_pos[N]) cout << -1;
    else cout << visited_pos[N];
}