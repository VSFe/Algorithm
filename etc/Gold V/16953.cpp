/*
Problem: A → B (16953)
Tier: Gold 5
Detail: 정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.
    2를 곱한다.
    1을 수의 가장 오른쪽에 추가한다. 
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
Comment: 사실 끝이 1인 경우엔 1을 빼면 되는지라... 역으로 그리디 연산하면 끝!!
*/

#include <stdio.h>

int main() {
    int a, b, cnt = 1;
    scanf("%d %d", &a, &b);
    while(a < b) {
        if(b % 10 == 1) b /= 10;
        else if(b % 2 == 0) b /= 2;
        else {
            printf("-1");
            return 0;
        }
        cnt++;
    }
    if(a == b) printf("%d", cnt);
    else printf("-1");
    return 0;
}