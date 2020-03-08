/*
Problem: 숫자 카드(10816)
Tier: Silver 4
Detail: 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.
Comment: STL upper_bound나 lower_bound를 쓰면 될 수도 있겠지만 이번 문제에서는 그냥 구현해보는걸로!!
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> vec;

int get_cnt(int obj) {
    
}

int main() {
    scanf("%d", &N);
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        int tmp;
        scanf("%d", &tmp);

    }
    return 0;
}