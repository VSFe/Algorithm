/*
Problem: 가운데를 말해요 (2696)
Tier: Gold 3
Detail: 어떤 수열을 읽고, 홀수번째 수를 읽을 때 마다, 지금까지 입력받은 값의 중앙값을 출력하는 프로그램을 작성하시오.
예를 들어, 수열이 1,5,4,3,2 이면, 홀수번째 수는 1번째 수, 3번째 수, 5번째 수이고, 1번째 수를 읽었을 때 중앙값은 1, 3번째 수를 읽었을 때는 4, 5번째 수를 읽었을 때는 3이다.
Comment: 우선순위 큐를 한개만 쓸 필요는 없잖아?
최대0와 최소 사이에는 가운데라는걸 생각했어야 했다...
pq_min: 최소힙. 루트 값이 최솟값을 담고 있다. → 최대힙 보다 큰 값을 가져야겠다.
pq_max: 최대힙. 루트 값이 최댓값을 담고 있다.
*/

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int TC; scanf("%d", &TC);
    for(int tc = 0; tc < TC; tc++) {
        int N;
        priority_queue<int, vector<int>, less<int>> pq_max;
        priority_queue<int, vector<int>, greater<int>> pq_min;
        vector<int> ans;
        scanf("%d", &N);
        int tmp;
        scanf("%d", &tmp);
        ans.push_back(tmp);
        pq_max.push(tmp);
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
                ans.push_back(pq_max.top());
            } else {
                if(pq_max.top() > data) {
                    int tmp = pq_max.top();
                    pq_max.pop();
                    pq_max.push(data);
                    pq_min.push(tmp); 
                } else {
                    pq_min.push(data);
                }
            }
        }
        int size = ans.size();
        printf("%d\n", size);
        for(int i = 0; i < size; i++) {
            if(i == size - 1) printf("%d\n", ans[i]);
            else if((i + 1) % 10) printf("%d ", ans[i]);
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}