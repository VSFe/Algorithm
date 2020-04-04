/*
Problem: KCM Travel (10217)
Tier: Gold 1
Detail: 각고의 노력 끝에 찬민이는 2014 Google Code Jam World Finals에 진출하게 되었다. 구글에서 온 초대장을 받고 기뻐했던 것도 잠시, 찬찬히 읽어보던 찬민이는 중요한 사실을 알아차렸다.
최근의 대세에 힘입어 구글 역시 대기업답게 비용 감축에 열을 내고 있었던 것이다.
초대장 내용에 의하면 구글은 찬민에게 최대 M원까지의 비용만을 여행비로써 부담해주겠다고 한다.
인천에서 LA행 직항 한 번 끊어주는게 그렇게 힘드냐고 따지고도 싶었지만, 다가올 결승 대회를 생각하면 대회 외적인 곳에 마음을 쓰고 싶지 않은 것 또한 사실이었다.
그래서 찬민은 인천에서 LA까지 M원 이하로 사용하면서 도착할 수 있는 가장 빠른 길을 차선책으로 택하기로 하였다.
각 공항들간 티켓가격과 이동시간이 주어질 때, 찬민이 인천에서 LA로 갈 수 있는 가장 빠른 길을 찾아 찬민의 대회 참가를 도와주자.
Comment: 굳이 최단거리라고 다익스트라나 그런거에 얽매일 필요가 없다...
*/

#define INF 16000001
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct inform {
    int dest, price, time;
    inform() {}
    inform(int a, int b, int c) : dest(a), price(b), time(c) {}
};

int dp[101][10001];
int MIN = INF;
vector<inform> graph[101];

int travel(int idx, int balance) {
    if(balance < 0) return INF;
    if(dp[idx][balance] != -1) return dp[idx][balance];
    int &ret = dp[idx][balance];
    ret = INF;
    for(auto next : graph[idx]) {
        ret = min(ret, travel(next.dest, balance - next.price) + next.time);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) {
        for(int i = 0; i < 101; i++) graph[i].clear();
        fill(&dp[0][0], &dp[100][10000], -1);
        int N, M, K; cin >> N >> M >> K;
        for(int i = 0; i <= M; i++) dp[N][i] = 0;
        for(int i = 0; i < K; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            graph[a].push_back(inform(b, c, d));
        }
    int ans = travel(1, M);
    if(ans == INF) cout << "Poor KCM" << '\n';
    else cout << ans << '\n';
    }
    return 0;
}
