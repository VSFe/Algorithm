/*
Problem: 관악산 등산 (14699)
Tier: Gold 5
Detail: 서울대학교에는 “누가 조국의 미래를 묻거든 고개를 들어 관악을 보게 하라”라는 유명한 문구가 있다. 어느 날 Unused는 Corea에게 조국의 미래를 물었고, Corea는 직접 관악산에 올라가 조국의 미래를 보고 답해 주기로 했다.
관악산의 등산로는 1부터 N까지의 서로 다른 번호가 붙어 있는 N개의 쉼터와 두 쉼터 사이를 오갈 수 있는 M개의 길들로 이루어져 있다. Corea는 지면에서부터 산을 오르는 것은 너무 귀찮다고 생각했기 때문에,
케이블카를 타고 임의의 쉼터에서 내린 다음 등산을 시작하기로 했다. Corea는 항상 더 높은 곳을 지향하기 때문에, 쉼터에 도착하면 그 쉼터와 직접 연결된 더 높은 쉼터로 향하는 길들 중 하나를 골라서 그 길을 따라 이동한다. 만약 그런 길이 없다면 등산을 마친다.
관악산의 쉼터들에는 조국의 미래를 볼 수 있는 전망대가 하나씩 설치되어 있다. Corea는 최대한 많은 쉼터를 방문해서 조국의 미래를 많이 보고 Unused에게 전해 주기로 했다.
관악산의 지도가 주어질 때, Corea가 각각의 쉼터에서 출발해서 산을 오를 때 최대 몇 개의 쉼터를 방문할 수 있는지 구하여라.
Comment: DAG 만들어서 BFS로 풀면 될 것 같은데?
그래도 시간 절약을 위해 메모이제이션을 써봄.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int visited[5001], height[5001], N, M;
vector<int> graph[5001];

int dfs(int idx) {
    if(visited[idx] != 0) return visited[idx];
    int &ret = visited[idx], MAX = 0;
    ret = 1;
    for(int next : graph[idx]) {
        MAX = max(MAX, dfs(next));
    }
    return ret += MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> height[i];
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        if(height[x] < height[y]) graph[x].push_back(y);
        else if(height[x] > height[y]) graph[y].push_back(x);
    }
    for(int i = 1; i <= N; i++) {
        cout << dfs(i) << '\n';
    }
}


