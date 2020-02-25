/*
Problem: ATM (12865)
Tier: Silver 3
Detail: 
인하은행에는 ATM이 1대밖에 없다. 지금 이 ATM앞에 N명의 사람들이 줄을 서있다. 사람은 1번부터 N번까지 번호가 매겨져 있으며,
i번 사람이 돈을 인출하는데 걸리는 시간은 Pi분이다.
줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때,
각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 
식을 정리해보면
n * P[i1] + (n-1) * P[i2] ... 니까
걍 정렬해서 세워버리면 끝!
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> gap;
int result = 0;

int main() {
    scanf("%d", &N);
    gap.reserve(N);
    int tmp;
    for (int i =0; i < N; i++) {
        scanf("%d", &tmp);
        gap.push_back(tmp);
    }
    sort(gap.begin(), gap.end());
    for (int i=0; i< N; i++) result += gap[i] * (N-i);
    printf("%d", result);
    return 0;
}