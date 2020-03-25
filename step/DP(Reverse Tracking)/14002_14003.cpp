/*
Problem: 가장 긴 증가하는 부분 수열 4, 5 (14002, 14003)
Tier: Gold 4, 1
Detail: 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은
A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
Comment: lower_bound를 잘 쓰고, 이전 인덱스에 대한 메모이제이션만 잘 하면 쉽게 푸는 보너스 문제.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, tmp, findway;
int IDX = 0, result[2][1000001], dt[2][1000000];
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> dt[0][i];
    for(int i = 0; i < N; i++) {
        tmp = lower_bound(result[0], result[0] + IDX, dt[0][i]) - result[0];
        if(tmp == IDX) IDX++;
        result[0][tmp] = dt[0][i];
        result[1][tmp] = i;
        dt[1][i] = result[1][tmp-1];
    }
    cout << IDX << "\n";
    vec.reserve(IDX);
    findway = result[1][IDX-1];
    for(int i = 0; i < IDX; i++) {
        vec.push_back(findway);
        findway = dt[1][findway];
    }
    for(int i = vec.size() - 1; i >= 0; i--) cout << dt[0][vec[i]] << " ";
    return 0;
}