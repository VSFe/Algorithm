/*
Problem: 링 (3036)
Tier: Silver 3
Detail: 링의 반지름이 주어진다. 이때, 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 돌아가는지 구하는 프로그램을 작성하시오.
Comment: 나눗셈 문제.
a/b로 나타낸 다음에 gcd 구해서 각각 없애주면 끝.
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int N; 
int dat[100];

int Eucl(int a, int b);

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &dat[i]);
    int stand = dat[0];
    for(int i = 1; i < N; i++) {
        int tmp = Eucl(stand, dat[i]);
        printf("%d/%d\n", stand / tmp, dat[i] / tmp);
    }
    return 0;
}

int Eucl(int a, int b){
    int remain; 
    int tmp1 = max(a, b), tmp2 = min(a, b);
    remain = tmp1 % tmp2;
    if (remain == 0) 
        return tmp2;
    else
    return Eucl(remain, tmp2); 
}