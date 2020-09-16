/*
Problem: 숫자 카드(10816)
Tier: Silver 4
Detail: 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.
Comment: STL upper_bound나 lower_bound를 쓰면 될 수도 있겠지만 이번 문제에서는 그냥 구현해보는걸로!!
해서 이진탐색 두번 돌리는걸로 쉽게 컷.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> vec;

int get_cnt(int obj) {
    int start = 0, end = vec.size();
    int cnt;
    while(start != end) {
        int mid = (start + end) / 2;
        if(vec[mid] >= obj) end = mid;
        else start = mid + 1;
    }
    if(vec[start] != obj) return 0;
    int start_bound = 0, end_bound = vec.size();
    obj += 1;
    while(start_bound != end_bound) {
        int mid = (start_bound + end_bound) / 2;
        if(vec[mid] >= obj) end_bound = mid;
        else start_bound = mid + 1;
    }
    return start_bound - start;
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
        printf("%d ", get_cnt(tmp));
    }
    return 0;
}