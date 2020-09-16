/*
Problem: 가장 큰 증가 부분 수열
Tier: Silver 2
Detail: 수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
Comment: 
각각의 원소에 대하여,
dp[n] = max(dp[1...n-1 (단, vec[1]...vec[n-1] 중 본 값보다 작은 값.) + n-1])
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

vector<int> vec, dt;
int N;

int main() {
    scanf("%d", &N);
    vec.reserve(N);
    dt.reserve(N);
    for(int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        vec.push_back(data);
    }
    for(int i = 0; i < N; i++) {
        int MAX = vec[i];
        for(int j = 0; j < i; j++) {
            if(vec[j] < vec[i]) {
                MAX = max(MAX, dt[j] + vec[i]);
            }
        }
        dt.push_back(MAX);
    }
    sort(dt.begin(), dt.end());
    printf("%d", dt.back());
    return 0;
}