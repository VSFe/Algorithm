/*
Problem: ACM Craft (1005)
Tier: Gold 3
Detail: ACM크래프트는 다이나믹한 게임 진행을 위해 건물을 짓는 순서가 정해져 있지 않다. 즉, 첫 번째 게임과 두 번째 게임이 건물을 짓는 순서가 다를 수도 있다.
매 게임시작 시 건물을 짓는 순서가 주어진다. 또한 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 Delay가 존재한다.
프로게이머 최백준은 애인과의 데이트 비용을 마련하기 위해 서강대학교배 ACM크래프트 대회에 참가했다!
최백준은 화려한 컨트롤 실력을 가지고 있기 때문에 모든 경기에서 특정 건물만 짓는다면 무조건 게임에서 이길 수 있다.
그러나 매 게임마다 특정건물을 짓기 위한 순서가 달라지므로 최백준은 좌절하고 있었다.
백준이를 위해 특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램을 작성해주자.
Comment: 문제를 계속 곱씹어 봤는데 솔직히 딴거 안 짓고 해당 루트에 있는것만 다 지으면 그냥 해결되는거였다.
대체?
따라서 위상정렬 돌려서 풀면 되긴 할듯....
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++) {
        int N, M, OBJ, pre[1001] = {0}, price[1001], result[1001] = {0};
        vector<int> vec[1001];
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++) scanf("%d", &price[i]);
        for(int i = 0; i < M; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec[x].push_back(y);
            pre[y]++;
        }
        scanf("%d", &OBJ);
        queue<int> Q;
        for(int i = 1; i <= N; i++) {
            if(!pre[i]) Q.push(i);
        }
        while(pre[OBJ] > 0) {
            int u = Q.front(); Q.pop();
            for(int next : vec[u]) {
                result[next] = max(result[next], result[u] + price[u]);
                if(--pre[next] == 0) Q.push(next);
            }
        }
        printf("%d\n", result[OBJ] + price[OBJ]);
    }

    return 0;
}
