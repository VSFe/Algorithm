/*
Problem: 약수 (1037)
Tier: Silver 5
Detail: 양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때,
N을 구하는 프로그램을 작성하시오.
Comment: 시간 제한이 2초인 이유가 있겠지... 라고 생각했는데 걍 맨 앞이랑 맨 끝 값만 곱하면 되는거였음 ㅋㅋㅋ ㅅㅂ
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int tmp;
vector<int> yak;

int main() {
    scanf("%d", &N);
    yak.reserve(N);    
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        yak.push_back(tmp);
    }
    sort(yak.begin(), yak.end());
    if(N % 2 == 0) printf("%d", yak.front() * *(yak.end()-1));
    else printf("%d", yak[N/2] * yak[N/2]);
    return 0;
}