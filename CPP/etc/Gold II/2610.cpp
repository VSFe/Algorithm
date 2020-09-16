/*
Problem: 회의 준비 (2610)
Tier: Gold 2
Detail: KOI 준비를 위해 회의를 개최하려 한다. 주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다. 위원회를 구성하는 방식은 다음과 같다.
    서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
    효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다. 그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다.
대표에게 의견을 전달하는 경로가 여러 개 있을 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며 이때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.
위원회에서 모든 참석자들의 의사전달시간 중 최댓값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.
예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 서로 알고 있다고 하자. 1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서 2번을 거쳐야만 한다. 반대로 3번이 대표가 되어도 1번이 대표인 3번에게 의견을 전달하려면 2번을 거쳐야만 한다.
하지만 2번이 대표가 되면 1번과 3번 둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 따라서 이와 같은 경우 2번이 대표가 되어야 한다.
Comment: Union-Find + BFS 조합으로 해결.
플로이드 워셜 알고리즘도 되는구나...
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;
int uf[101], cnt_travel[101], visited[101];
vector<int> graph[101], vec[101], ans;

int uf_find(int x) {
    return (uf[x] == -1) ? x : uf[x] = uf_find(uf[x]);
}

void uf_union(int x, int y) {
    int dx = uf_find(x), dy = uf_find(y);
    if(dx != dy) uf[dy] = dx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    fill(uf, uf + 101, -1);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        uf_union(x, y);
    }
    for(int i = 1; i <= N; i++) {
        if(uf[i] == -1) {
            vec[i].push_back(i);
        }
        else vec[uf_find(i)].push_back(i);
    }
    for(int i = 1; i <= N; i++) {
        if(vec[i].empty()) continue;
        int MIN = 10000, MIN_IDX;
        for(int j = 0; j < vec[i].size(); j++) {
            for(int k = 0; k < vec[i].size(); k++) {
                visited[vec[i][k]] = 0;
            }
            queue<int> q;
            int tmp_cnt = 0;
            q.push(vec[i][j]);
            visited[vec[i][j]] = 1;
            while(!q.empty()) {
                bool is_travel = false;
                int size = q.size();
                for(int idx = 0; idx < size; idx++) {
                    int tmp = q.front(); q.pop();
                    for(int next : graph[tmp]) {
                        if(!visited[next]) {
                            visited[next] = 1;
                            q.push(next);
                            is_travel = 1;
                        }
                    }
                }
                if(is_travel) tmp_cnt++;
            }
            if(MIN > tmp_cnt) {
                MIN = tmp_cnt;
                MIN_IDX = vec[i][j];
            }
        }
        ans.push_back(MIN_IDX);
    } 
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}