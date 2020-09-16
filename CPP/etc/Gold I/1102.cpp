/*
Problem: 발전소 (1102)
Tier: Gold 1
Detail:  은진이가 회사에서 잠깐 잘 때마다, 몇몇 발전소가 고장이난다. 게다가, 지금 은진이의 보스 형택이가 은진이의 사무실로 걸어오고 있다.
만약 은진이가 형택이가 들어오기 전까지 발전소를 고쳐놓지 못한다면, 은진이는 해고당할 것이다.
발전소를 고치는 방법은 간단하다. 고장나지 않은 발전소를 이용해서 고장난 발전소를 재시작하면 된다. 하지만, 이때 비용이 발생한다.
이 비용은 어떤 발전소에서 어떤 발전소를 재시작하느냐에 따라 다르다.
Comment: 외판원 문제에 갖혀있다보니 당해버린 문제...
외판원과 비슷할 수 있어도, 모든 곳을 방문하는 것이 아니기 때문에 카운트 변수와 방문 인자를 어떤 방식으로 활용하냐가 중점이 되는 문제.
*/

#define INF 10000000
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int dt[17][17], cache[1 << 17];
int N, ob;
int visited = 0;
int cnt = 0;
queue<pair<int, pair<int, int>>> q;

int travel(int visited) {
    int &ret = cache[visited];
    if(ret != -1) return ret;
    if(cnt >= ob) return ret = 0;
    ret = INF; cnt++;
    for(int i = 0; i < N; i++) {
        if(visited & (1 << i)) {
            for(int j = 0; j < N; j++) {
                if(!(visited & (1 << j))) ret = min(ret, travel(visited | (1 << j)) + dt[i][j]);
            }
        }
    }
    cnt--; return ret;
}

int main() {
    fill(cache, cache + (1 << 17), -1);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) { scanf("%d", &dt[i][j]); }
    } getchar();
    for(int i = 0; i < N; i++) {
        char t;
        scanf("%c", &t);
        if(t == 'Y') { visited |= (1 << i); cnt++; }
    }
    scanf(" %d", &ob);
    int result = travel(visited);
    printf("%d", (result == INF ? -1 : result));
    return 0;
}