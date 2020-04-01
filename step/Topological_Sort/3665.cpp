/*
Problem: 최종 순위 (3665)
Tier: Gold 1
Detail: 올해는 인터넷 예선 본부에서는 최종 순위를 발표하지 않기로 했다. 그 대신에 작년에 비해서 상대적인 순위가 바뀐 팀의 목록만 발표하려고 한다. (작년에는 순위를 발표했다)
예를 들어, 작년에 팀 13이 팀 6 보다 순위가 높았는데, 올해 팀 6이 팀 13보다 순위가 높다면, (6, 13)을 발표할 것이다.
창영이는 이 정보만을 가지고 올해 최종 순위를 만들어보려고 한다. 작년 순위와 상대적인 순위가 바뀐 모든 팀의 목록이 주어졌을 때, 올해 순위를 만드는 프로그램을 작성하시오.
하지만, 본부에서 발표한 정보를 가지고 확실한 올해 순위를 만들 수 없는 경우가 있을 수도 있고, 일관성이 없는 잘못된 정보일 수도 있다. 이 두 경우도 모두 찾아내야 한다.
Comment:
주어진 정보에 맞춰 간선을 개선하고, 위상 정렬을 때리면 해결.
?가 나오는 경우: 갈림길이 나오는 경우
그으으으은데 서로 바뀐다고 ?가 나오긴 할까 ㅋㅋㅋㅋ...
IMPOSSIBLE이 나오는 경우: 사이클!!!
*/

#include <iostream>
#include <queue>
using namespace std;

int TC;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        int N, M, in[501] = {0}, rank[501] = {0};
        queue<int> q;
        int graph[501][501];
        cin >> N;
        for(int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            rank[tmp] = i;
        }
        for(int i = 1; i <= N; i++) {
            for(int j = i + 1; j <= N; j++) {
                if(rank[i] < rank[j]) {
                    graph[i][j] = 1;
                    in[j]++;
                }
                else {
                    graph[j][i] = 1;
                    in[i]++;
                }
            }
        }
        cin >> M;
        for(int tc = 0; tc < M; tc++) {
            int x, y;
            cin >> x >> y;
            if(rank[x] < rank[y]) {
                graph[x][y] = 0;
                graph[y][x] = 1;
                in[x]++; in[y]--;
            }
            else {
                graph[x][y] = 1;
                graph[y][x] = 0;
                in[x]--; in[y]++;
            }
        }
        for(int i = 1; i <= N; i++) {
            if(!in[i]) q.push(i);
        }
        int cnt = 0, answer[501] = {0}; 
        while(!q.empty()) {
            int dt = q.front(); q.pop();
            answer[cnt++] = dt;
            for(int i = 1; i <= N; i++) {
                if(graph[dt][i]) {
                    in[i]--;
                    if(!in[i]) q.push(i);
                }
            }
        }
        if(cnt != N) cout << "IMPOSSIBLE" << '\n';
        else { for(int i = 0; i < N; i++) cout << answer[i] << " "; cout << '\n'; } 
    }
    return 0;
}
