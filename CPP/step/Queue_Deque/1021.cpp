/*
Problem: 회전하는 큐(1021)
Tier: Silver 4
Detail: 큐에 처음에 포함되어 있던 수 N이 주어진다.
그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.
Comment: 왼쪽 이동, 오른쪽 이동, 첫번째 원소 뽑기 구현 부터 하자.
*/

#include <deque>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int N, M;
int cnt = 0;
deque<int> d;

int moving(int c) {
    deque<int> case1, case2;
    int cnt1 = 0, cnt2 = 0;
    case1 = d;
    case2 = d;
    while(case1.front() != c) {
        int tmp = case1.front();
        case1.pop_front();
        case1.push_back(tmp);
        cnt1++;
    }
    while(case2.front() != c) {
        int tmp = case2.back();
        case2.pop_back();
        case2.push_front(tmp);
        cnt2++;
    }
    if(cnt1 < cnt2) {
        d = case1;
        d.pop_front();
        return cnt1;
    }
    else {
        d = case2;
        d.pop_front();
        return cnt2;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) d.push_back(i+1);
    for(int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt += moving(tmp);
    }
    printf("%d", cnt);
}