/*
Problem: 경찰차 (2618)
Tier: Platinum V
Detail: 어떤 도시의 중심가는 N개의 동서방향 도로와 N개의 남북방향 도로로 구성되어 있다.
모든 도로에는 도로 번호가 있으며 남북방향 도로는 왼쪽부터 1에서 시작하여 N까지 번호가 할당되어 있고 동서방향 도로는 위부터 1에서 시작하여 N까지 번호가 할당되어 있다. 또한 동서방향 도로 사이의 거리와 남 북방향 도로 사이의 거리는 모두 1이다.
동서방향 도로와 남북방향 도로가 교차하는 교차로의 위치는 두 도로의 번호의 쌍인 (동서방향 도로 번호, 남북방향 도로 번호)로 나타낸다. N이 6인 경우의 예를 들면 다음과 같다.
이 도시에는 두 대의 경찰차가 있으며 두 차를 경찰차1과 경찰차2로 부른다. 처음에는 항상 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, N)의 위치에 있다.
경찰 본부에서는 처리할 사건이 있으면 그 사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려 주고, 연락 받은 경찰차는 그 위치로 가장 빠른 길을 통해 이동하여 사건을 처리한다.
(하나의 사건은 한 대의 경찰차가 처리한다.) 그리고 사건을 처리 한 경찰차는 경찰 본부로부터 다음 연락이 올 때까지 처리한 사건이 발생한 위치에서 기다린다. 경찰 본부에서는 사건이 발생한 순서대로 두 대의 경찰차에 맡기려고 한다. 처리해야 될 사건들은 항상 교차로에서 발생하며 경찰 본부에서는 이러한 사건들을 나누어 두 대의 경찰차에 맡기되, 두 대의 경찰차들이 이동하는 거리의 합을 최소화 하도록 사건을 맡기려고 한다.
예를 들어 앞의 그림처럼 N=6인 경우, 처리해야 하는 사건들이 3개 있고 그 사건들이 발생된 위치 를 순서대로 (3, 5), (5, 5), (2, 3)이라고 하자. (3, 5)의 사건을 경찰차2에 맡기고 (5, 5)의 사건도 경찰차2에 맡기며, (2, 3)의 사건을 경찰차1에 맡기면 두 차가 이동한 거리의 합은 4 + 2 + 3 = 9가 되 고, 더 이상 줄일 수는 없다.
처리해야 할 사건들이 순서대로 주어질 때, 두 대의 경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램을 작성하시오.
Comment: DP 테이블을 구상하는데 쓸데없이 많이 걸렸다. 왜 그랬지...
dp[x][y] = 첫번째 경찰차가 x번째, 두번째 경찰차가 y번째 사건을 해결했을 때의 남은 최소거리.
dp[x][y] = min(dp[prev][y] + dist(prev, x), dp[x][prev] + dist(prev, y))
그러면 dist를 구해야 하네...
abs 때문에 쓸데없이 틀리긴 했지만 사실상 일반적인 dp의 응용
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1001][1001], N, W;
pair<int, int> position[1001];

inline int cal_dist(int x, int y) {
    pair<int, int> p1 = position[x], p2 = position[y];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int cal_dp(int x, int y) {
    if(x == W || y == W) return 0;
    int &ret = dp[x][y], k = max(x, y) + 1, t1, t2;
    if(ret != -1) return ret;
    ret = 0;
    if(x == 0) t1 = abs(position[k].first - 1) + abs(position[k].second - 1);
    else t1 = cal_dist(x, k);
    if(y == 0) t2 = 2 * N - position[k].first - position[k].second;
    else t2 = cal_dist(y, k);
    ret = min(cal_dp(k, y) + t1, cal_dp(x, k) + t2);
    return ret;
}

void tracking(int x, int y) {
    if(x == W || y == W) return;
    int k = max(x, y) + 1, t1, t2;
    if(x == 0) t1 = abs(position[k].first - 1) + abs(position[k].second - 1);
    else t1 = cal_dist(x, k);
    if(y == 0) t2 = 2 * N - position[k].first - position[k].second;
    else t2 = cal_dist(y, k);
    if(dp[k][y] + t1 > dp[x][k] + t2) {
        cout << 2 << '\n';
        tracking(x, k);
    }
    else {
        cout << 1 << '\n'; 
        tracking(k, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> W;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= W; i++) {
        int a, b;
        cin >> a >> b;
        position[i] = {a, b};
    }
    cout << cal_dp(0, 0) << '\n';
    tracking(0, 0);
    return 0;
}