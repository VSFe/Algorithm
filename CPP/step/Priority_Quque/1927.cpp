/*
Problem: 최소 힙 (1927)
Tier: Silver 1
Detail: 널리 잘 알려진 자료구조 중 최소 힙이라는 것이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
    배열에 자연수 x를 넣는다.
    배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
Comment: 아.
*/

#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 0) {
            if(pq.size() == 0) printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else pq.push(tmp);
    }
    return 0;
}