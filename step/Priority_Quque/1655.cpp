/*
Problem: 가운데를 말해요 (1655)
Tier: Gold 2
Detail: 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다.
만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다.
수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.
Comment: 우선순위 큐를 한개만 쓸 필요는 없잖아?
최대0와 최소 사이에는 가운데라는걸 생각했어야 했다...
pq_min: 최소힙. 루트 값이 최솟값을 담고 있다. → 최대힙 보다 큰 값을 가져야겠다.
pq_max: 최대힙. 루트 값이 최댓값을 담고 있다.
*/

#include <stdio.h>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;

int main() {
    scanf("%d", &N);
    int tmp;
    scanf("%d", &tmp);
    pq_max.push(tmp);
    printf("%d\n", pq_max.top());
    for(int i = 1; i < N; i++) {
        int data;
        scanf("%d", &data);
        if(i % 2 == 0) {
            if(pq_min.top() < data) {
                int tmp = pq_min.top();
                pq_min.pop();
                pq_min.push(data);
                pq_max.push(tmp); 
            } else pq_max.push(data);
        } else {
            if(pq_max.top() > data) {
                int tmp = pq_max.top();
                pq_max.pop();
                pq_max.push(data);
                pq_min.push(tmp); 
            } else pq_min.push(data);
        }
        printf("%d\n", pq_max.top());
    }
    return 0;
}