/*
Problem: 개미 (14942)
Tier: Platinum 5
Detail: 개미집은 n개의 방으로 구성되어 있으며 n개의 방은 1번부터 n번 까지 번호가 부여되어 있다. 그 중에서 1번 방은 지면에 바로 연결되어 있는 방이다.
각 방들은 서로 굴을 통해 연결되어 있다. 각 굴을 이동하기 위해서는 굴의 길이만큼 에너지가 소모된다.
개미는 집짓기의 달인이기 때문에 불필요한 굴은 짓지 않는다. 그래서 굴을 타고 한 방에서 다른 방으로 갈 수 있는 경로는 항상 존재하며 유일하다.
임의의 두 방 사이의 거리는 두 개의 방을 연결하는 경로를 구성하는 굴의 길이의 합이다.
겨울잠을 자던 개미들은 겨울잠에서 깨어나 지면으로 올라가 햇살을 보고 싶어한다. 그렇기 때문에 지면과 연결된 1번 방으로 이동을 하려고 한다.
하지만 불행하게도 개미는 긴 겨울잠을 자느라 축적해 놓은 에너지가 적다. 그래서 개미는 에너지를 1번 방에 도달하기 전에 모두 소모 할 수도 있다.
이렇게 에너지가 0이 된 개미는 더 이상 움직일 수 없다. 또한 1번 방에 도착한 개미는 더 이상 움직이지 않는다.
현재 모든 방에는 개미가 한 마리씩 있고 각각의 개미는 각자 축적된 에너지를 가지고 있다. 잠에서 깨어난 모든 개미는 1번 방을 향해서 이동한다.
이때 각각의 개미에 대해 도달할 수 있는 방 중에서 가장 1번 방에 가까운 방의 번호를 출력하시오.
Comment: 결과적으로 구간합을 구하는 문제라고 해석할 수 있음
-> 세그먼트 트리 or 스파스 테이블인데 갱신하는 부분이 없기 때문에 스파스 테이블로 채택.
무조건 1로 향하기 때문에 전체적으로 트리 구조를 이루고 있다고 볼 수 있는데, 우리에게 중요한 것은 부모로 향하는 길이기 때문에, 역트리를 생성함.
*/

#include <iostream>
#include <vector>
using namespace std;

int pending[100001];
pair<int, int> table[17][100001];
vector<pair<int, int>> graph[11], tree[11];

void make_tree(int now, int prev) {
    for(auto next : graph[now]) {
        if(next.first ^ prev) {
            tree[next.first].push_back({now, next.second});
            make_tree(next.first, now);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> pending[i];
    for(int i = 0; i < N-1; i++) {
        int x, y, weight; cin >> x >> y >> weight;
        graph[x].push_back({y, weight});
        graph[y].push_back({x, weight});
    }
    make_tree(1, 0);
    for(int i = 1; i <= N; i++) table[0][i] = (tree[i].size()) ? tree[i][0] : pair<int, int>(0, 0);
    for(int i = 1; i <= 16; i++) {
        for(int j = 1; j <= N; j++) {
            pair<int, int> t = table[i-1][j];
            table[i][j] = pair<int, int>(table[i-1][t.first].first, t.second + table[i-1][t.first].second);
        }
    }
    for(int i = 0; i < N; i++) {
        int tmp = pending[i];
    }
    return 0;
}