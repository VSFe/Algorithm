/*
Problem: 연산자 끼워넣기 (14888)
Tier: Silver 1
Detail: N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다.
또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
이 때, 해당 식의 최댓값과 최솟값을 구하시오.
Comment: C++ 알고리즘 솔빙 본격적 돌입... 집중합시다.
*/

#include <stdio.h>
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

const int MAX = 1000000000 + 1;

int N;
int number[12], oper[4];
int maxResult = -MAX, minResult = MAX;

void DFS(int plus, int minus, int multiply, int divide, int cnt, int sum) {
    if(cnt == N) {
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
    }

    if(plus > 0)
        DFS(plus - 1, minus, multiply, divide, cnt + 1, sum + number[cnt]);
    if(minus > 0)
        DFS(plus, minus - 1, multiply, divide, cnt + 1, sum - number[cnt]);
    if(multiply > 0)
        DFS(plus, minus, multiply - 1, divide, cnt + 1, sum * number[cnt]);
    if(divide > 0)
        DFS(plus, minus, multiply, divide - 1, cnt + 1, sum / number[cnt]);
        
}


int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &number[i]);
    for(int i = 0; i < 4; i++) scanf("%d", &oper[i]);
    
    DFS(oper[0], oper[1], oper[2], oper[3], 1, number[0]);

    cout << maxResult << endl;
    cout << minResult << endl;
    return 0;
}