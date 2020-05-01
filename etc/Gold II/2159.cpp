/*
Problem: 케익 배달 (2159)
Tier: Gold 2
Detail: 프랑스에서 공부를 하고 돌아온 선아는 자신이 그렇게도 되고 싶어 했던 파티셰가 되었다.
케익 배달 전문업체 보나뻬띠에 취직한 선아는 친절하게도 자신이 만든 케익을 고객들에게 직접 배달을 하려 한다.
N명의 고객에게 케익을 배달하는데 주문이 들어온 순서대로 배달하기를 원하며 고객이 케익을 받을 수 있을 만큼 충분히 가까이까지 배달한다.
N명의 고객의 위치는 순서대로 100,000×100,000 격자의 정수 좌표로 주어지고 처음 출발하게 되는 보나뻬띠의 위치도 정수 좌표로 주어진다.
선아는 격자 위에서 상하좌우로만 움직이며 고객에게 케익을 전달하기 위해서는 그 고객의 위치까지 가거나 고객의 상하좌우 인접 격자점에 가야 한다.
이때 선아가 최단거리를 이동하여 입력된 순서대로 배달을 끝낼 수 있는 거리를 계산하는 프로그램을 작성하시오. 여기서 거리는 격자 상의 칸 수를 말한다.
위의 예에서 선아는 11칸을 움직여서 세 명의 고객에게 배달을 마칠 수 있다.
선아는 반드시 고객들에게 순서대로 배달을 하며 순서에 어긋난 사람에게 배달을 할 수 있는 위치에 있더라도 케익을 주지 않고 순서대로 배달을 한다. 고객의 위치는 중복이 될 수도 있다.
Comment: 5가지 위치를 모두 고려한 2차원 DP.
오랜만에 DP를 보텀업으로 풀었다.
*/


#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll N, dist[100001][5], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
pair<int, int> pos[100001][5];
const ll INF = 1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        pos[i][0] = {x, y};
        for(int j = 0; j < 4; j++) {
            pos[i][j + 1] = {x + dx[j], y + dy[j]};
        }
    }
    fill(&dist[0][0], &dist[100000][4], INF);
    for(int i = 0; i < 5; i++) dist[N][i] = 0;
    for(int i = N - 1; i > 0; i--) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                dist[i][j] = min(dist[i][j], dist[i + 1][k] + abs(pos[i][j].first - pos[i + 1][k].first) + abs(pos[i][j].second - pos[i + 1][k].second));
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i < 5; i++) {
        ans = min(ans, dist[1][i] + abs(pos[0][0].first - pos[1][i].first) + abs(pos[0][0].second - pos[1][i].second));
    }
    cout << ans;
}