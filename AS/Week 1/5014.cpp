/*
Problem: 이진수 (2226)
Tier: Gold 5
Detail: 스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.
보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다. U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다.
(만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)
강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.
Comment: 너무나 간단한 1차원 BFS 문제
*/

#include <stdio.h>
#include <queue>
using namespace std;

int bfs[1000001];
queue<int> q;
int main() {
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    q.push(S);
    bfs[S] = 1;
    while(!q.empty()) {
        int i = q.front(); q.pop();
        if(i + U <= F && bfs[i + U] == 0) {
            bfs[i + U] = bfs[i] + 1;
            q.push(i + U);
        }
        if(i - D > 0 && bfs[i - D] == 0) {
            bfs[i - D] = bfs[i] + 1;
            q.push(i - D);
        }

    }
    if(bfs[G] == 0) printf("use the stairs");
    else printf("%d", bfs[G] - 1);
    return 0;
}

