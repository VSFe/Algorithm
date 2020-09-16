/*
Problem: 제로 (10773)
Tier: Silver 4
Detail:재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!
Comment: 진짜 진짜 너무 쉽다...
*/

#include <stdio.h>
#include <stack>
using namespace std;

int N;
stack<int> s;

int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 0) s.pop();
        else s.push(tmp);
    }
    int result = 0;
    while(s.size() != 0) {
        result += s.top();
        s.pop();
    }
    printf("%d", result);
    return 0;
}

