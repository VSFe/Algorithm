/*
Problem: 오르막 수(11057)
Tier: Silver 1
Detail: 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
Comment: 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.
수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.
맨 끝에 해당하는 수열만 만들어 주면 될 것 같은데.
*/

#include <stdio.h>

int result[10];
int len;

int main() {
    int sum = 0;
    scanf("%d", &len);
    result[0] = 1;
    for(int i = 0; i < len; i++) {
        for(int j = 1; j < 10; j++) {
            result[j] = (result[j] + result[j-1]) % 10007;
        }
    }
    for(int i = 0; i < 10; i++) {
        sum += result[i];
    }
    printf("%d", sum % 10007);
    return 0;
}