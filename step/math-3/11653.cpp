/*
Problem: 소인수분해 (11653)
Tier: Silver 3
Detail: 정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.
Comment: 루트 씌운 값 까지만
*/

#include <stdio.h>
#include <cmath>

int N;
bool is_end = true;

int main() {
    scanf("%d", &N);
    int tmp = sqrt(N);
    while(true) {
        for(int i = 2; i < tmp+1; i++) {
            if(N % i == 0) {
                printf("%d \n", i);
                N /= i;
                is_end = false;
                break;
            }
        }
        if(is_end) {
            if(N != 1) printf("%d", N);
            break;
        }
        else is_end = true;
    }
    return 0;
}