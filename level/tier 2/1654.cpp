/*
Problem: 랜선 자르기 (1654)
Tier: Silver 3
Detail: 이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다.
박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다.
예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm 은 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)
Comment: 행렬 곱셈에서 아이디어 얻음.
분할정복이 은근 유용하네...
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long int N, K;
vector<long long int> vec;

long long int cal_cnt(int sd) {
    long long int result = 0;
    for(int i = 0; i < N; i++) {
        result += vec[i] / sd;
    }
    return result;
}

int find_val(int start, int end) {
    int mid = (start + end) / 2;
    if(cal_cnt(mid) >= K) {
        if(cal_cnt(mid+1) < K) return mid;
        else find_val(mid, end);
    }
    else find_val(start, mid);
}

int main() {
    scanf("%d %d", &N, &K);
    int inter = K / N;
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int val = vec.front();
    if(N == 1) {
        printf("%lld", val / K);
        return 0;
    }
    for(int i = 1; i <= inter; i++) {
        int maxi = val / i;
        int mini = val / (i+1); + 1;
        if(cal_cnt(mini) >= K) {
            printf("%d", find_val(mini, maxi));
            break;
        } 
    }
    return 0;
}