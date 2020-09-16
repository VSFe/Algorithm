/*
Problem: 랜선 자르기 (1654)
Tier: Silver 3
Detail: 이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다.
박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다.
예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm 은 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)
Comment: 괜히 이진탐색에서 벗어나는 헛 짓거리 하지 말자...
*/

#include <stdio.h>
#include <vector>
using namespace std;

int N, K;
long long sum = 0;
vector<long long> vec;

int main() {
    scanf("%d %d", &K, &N);
    vec.reserve(K);
    for(long long i = 0; i < K; i++) {
        long long tmp;
        scanf("%lld", &tmp);
        sum += tmp;
        vec.push_back(tmp);
    }
    long long upper_bound = sum / N;
    long long lower_bound = 1;
    while(upper_bound != lower_bound) {
        long long st = (upper_bound + lower_bound) / 2;
        long long cnt = 0;
        for(long long i = 0; i < K; i++) {
            cnt += vec[i] / st;
        }
        if(cnt >= N) lower_bound = st + 1;
        else upper_bound = st;
    }
    long long cnt = 0;
    for(long long i = 0; i < K; i++) {
        cnt += vec[i] / lower_bound;
    }
    if(cnt < N) lower_bound--;
    printf("%lld", lower_bound);
    return 0;
}