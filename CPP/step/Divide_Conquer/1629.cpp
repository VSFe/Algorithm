/*
Problem: 곱셈(1629)
Tier: Silver 1
Detail: 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
Comment: 예제로 봤었지 ㅋㅋ
a^n = a^n/2 * a^n/2 이런식으로 하면
O(n) 을 O(logn)으로 팍 줄일 수 있음....
*/

#include <stdio.h>

long long int multiple(int a, int b, int c) {
    if(b == 0) return 1; 
    long long int half = multiple(a, b/2, c);
    long long int tmp = (half * half) % c;
    if(b % 2 == 1) return (a * tmp) % c;
    else return tmp;
}

int main () {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", multiple(a, b, c));
    return 0;
}