/*
Problem: 요세푸스 문제 0 (11866)
Tier: Silver 4
Detail: 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다.
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
Comment: 시간복잡도는 O(NK). 이거 0번인 이유는 나중엔 이렇게 못 풀게 하려고 그러는 것 같음...
*/
#include <stdio.h>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) q.push(i+1);
    printf("<");
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < K-1; j++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int tmp = q.front();
        q.pop();
        printf("%d, ", tmp);
    }
    int tmp = q.front();
    printf("%d", tmp);
    printf(">");
    return 0;
}