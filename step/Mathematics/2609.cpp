/*
Problem: 최대공약수와 최소공배수 (2609)
Tier: Silver 5
Detail: 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
Comment: 리스트를 두개 만들어서 하나씩 소인수분해해서 쳐 넣을 수도 있을 듯 함...
근데 그거 구현이 쪼금 귀찮아서 걍 GCD 알고리즘 쳐서 하는걸로...

*/

#include <stdio.h>

int Eucl(int, int); //유클리드 알고리즘을 구현한 함수의 정의

int main(void){
    int a, b, big; // a, b는 입력받을 두 정수, big은 두 수를 비교할 때 사용할 변수
    int gcm, gld; // 유클리드 알고리즘 함수의 반환값을 받기 위한 변수
    scanf("%d %d", &a, &b); // a, b 두수를 입력 받는다.
    if (a>b){ // a, b를 비교해서 b쪽에 큰 수가 오도록 정렬하는 조건문
        big = a;
        a = b;
        b = big;
    }
    gcm = Eucl(a, b);
    gld = a * b / gcm;
    printf("%d\n%d", gcm, gld);
    return 0;
}

int Eucl(int a, int b){
    int remain; // 나머지를 받기 저장하기 위한 변수
    remain = b%a;
    if (remain == 0) // remain이 0이라는 것은 a가 a, b의  최대공약수라는 것을 의미한다.
        return a;
    else
    return Eucl(remain, a); // 최대공약수를 찾지 못했으므로 유클리드 알고리즘을 반복한다.
}