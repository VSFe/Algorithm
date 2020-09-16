/*
Problem: 친구비 (16562)
Tier: Gold 3
Detail: 19학번 이준석은 학생이 N명인 학교에 입학을 했다. 준석이는 입학을 맞아 모든 학생과 친구가 되고 싶어한다.
하지만 준석이는 평생 컴퓨터랑만 대화를 하며 살아왔기 때문에 사람과 말을 하는 법을 모른다. 그런 준석이에게도 희망이 있다. 바로 친구비다!
학생 i에게 Ai만큼의 돈을 주면 그 학생은 1달간 친구가 되어준다! 준석이에게는 총 k원의 돈이 있고 그 돈을 이용해서 친구를 사귀기로 했다.
막상 친구를 사귀다 보면 돈이 부족해질 것 같다는 생각을 하게 되었다. 그래서 준석이는 “친구의 친구는 친구다”를 이용하기로 했다.
준석이는 이제 모든 친구에게 돈을 주지 않아도 된다!
위와 같은 논리를 사용했을 때, 가장 적은 비용으로 모든 사람과 친구가 되는 방법을 구하라.
Comment: 어쨌든... 유니언 파인드.
솔직히 첫번째 풀이가 왜 잘 못 된건지는 아직 감을 못 잡고 있음 퓨ㅠㅠㅠㅠ
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int price[10001], uf[10001], ans = 0;

int find(int i) {
    return (uf[i] == i) ? i : (uf[i] = find(uf[i]));
}

void un(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if(pi == pj) return;
    if(price[pi] < price[pj]) uf[pj] = pi;
    else uf[pi] = pj;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        cin >> price[i];
        uf[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        un(x, y);
    }
    for(int i = 1; i <= N; i++) {
        if(uf[i] == i) ans += price[i];
    }
    if(ans > K) cout << "Oh no";
    else cout << ans;
}


