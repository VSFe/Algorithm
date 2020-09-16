/*
Problem: 스택 수열 (1874)
Tier: Silver 3
Detail: 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
이를 계산하는 프로그램을 작성하라.
Comment: 먼저 계산부터 하면 NO를 띄우기가 애매하니 1차 검사부터 하자...
*/

#include <stack>
#include <stdio.h>
using namespace std;

int N;
int MAX = 0;
int idx = 0, cnt = 1;
int yee[100000];
stack<int> s;

int main () {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &yee[i]);
    MAX = yee[0];
    for(int i = 1; i < N; i++) {
        if(yee[i] > yee[i-1]) {
            if(yee[i] > MAX) MAX = yee[i];
            else { 
                printf("NO");
                return 0;
            }
        }
    }
    while(idx != N) {
        if(s.size() == 0 || s.top() != yee[idx]) {
            s.push(cnt++);
            printf("+\n");
        }
        else {
            s.pop();
            printf("-\n");
            idx++;
        }
    }
    return 0;
}