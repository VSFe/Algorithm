/*
Problem: 사이클 게임 (20040)
Tier: Gold 4
Detail: 사이클 게임은 두 명의 플레이어가 차례대로 돌아가며 진행하는 게임으로, 선 플레이어가 홀수 번째 차례를, 후 플레이어가 짝수 번째 차례를 진행한다.
게임 시작 시 0 부터 n − 1 까지 고유한 번호가 부여된 평면 상의 점 n 개가 주어지며, 이 중 어느 세 점도 일직선 위에 놓이지 않는다.
매 차례 마다 플레이어는 두 점을 선택해서 이를 연결하는 선분을 긋는데, 이전에 그린 선분을 다시 그을 수는 없지만 이미 그린 다른 선분과 교차하는 것은 가능하다.
게임을 진행하다가 처음으로 사이클을 완성하는 순간 게임이 종료된다. 
문제는 선분을 여러 개 그리다 보면 사이클이 완성 되었는지의 여부를 판단하기 어려워 이미 사이클이 완성되었음에도 불구하고 게임을 계속 진행하게 될 수 있다는 것이다.
이 문제를 해결하기 위해서 게임의 진행 상황이 주어지면 몇 번째 차례에서 사이클이 완성되었는지, 혹은 아직 게임이 진행 중인지를 판단하는 프로그램을 작성하려 한다.
입력으로 점의 개수 n과 m 번째 차례까지의 게임 진행 상황이 주어지면 사이클이 완성 되었는지를 판단하고, 완성되었다면 몇 번째 차례에서 처음으로 사이클이 완성된 것인지를 출력하는 프로그램을 작성하시오.
Comment: uf로 묶이게 되면 같은 사이클은 당연하게 같은 그룹으로 묶일 수 밖에 없음.
-> 그러니까 Union 연산을 할 때 이미 두 노드가 같으면 그냥 종료 시켜버리면 됨.
*/

#include <iostream>
#include <cstring>
using namespace std;

int uf[500001];

int uf_find(int x) {
    return uf[x] == -1 ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int X = uf_find(x), Y = uf_find(y);
    if(X == Y) return 0;
    uf[X] = Y;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(uf, -1, sizeof(uf));
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        if(!uf_union(x, y)) {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}