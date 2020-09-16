/*
Problem: 프린터 큐(1966)
Tier: Silver 3
Detail: 여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다.
예를 들어 위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄되게 된다.
Comment: 배열 초기화는 fill_n (iostream 내에 있음.)
*/

#include <stdio.h>
#include <queue>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        queue<int> q;
        int x, y;
        int dat[100], prio[10];
        fill_n(dat, 100, 0);
        fill_n(prio, 10, 0);
        scanf("%d %d", &x, &y);
        for(int j = 0; j < x; j++) {
            int tmp;
            scanf("%d", &tmp);
            q.push(j);
            dat[j] = tmp;
            prio[tmp]++;
        }
        while(q.size() != 0) {
            int tmp = q.front();
            bool sus = true;
            q.pop();
            for(int j = 9; j > dat[tmp]; j--) {
                if(prio[j] > 0) {
                    q.push(tmp);
                    sus = false;
                    break;
                }
            }
            if(sus) {
                prio[dat[tmp]]--;
                if(tmp == y) {
                    printf("%d\n", x - q.size());
                    break;
                }
            }
        }
    }
    return 0;
}