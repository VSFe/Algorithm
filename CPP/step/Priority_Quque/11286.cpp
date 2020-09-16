/*
Problem: 절댓값 힙 (11286)
Tier: Silver 1
Detail: 절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.
    1. 배열에 정수 x (x ≠ 0)를 넣는다.
    2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
Comment: compair만 만들자.
*/

#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;

struct yee {
    int compare_val;
    int x;
    yee(int x) : x(x), compare_val(abs(x)) {}
};

struct cmp {
    bool operator() (const yee &a, const yee &b) {
        if(a.compare_val == b.compare_val) return a.x > b.x;
        return a.compare_val > b.compare_val;
    }
};

int main() {
    priority_queue<yee, vector<yee>, cmp> pq;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 0) {
            if(pq.size() == 0) printf("0\n");
            else {
                printf("%d\n", pq.top().x);
                pq.pop();
            }
        }
        else pq.push(yee(tmp));
    }
    return 0;
}