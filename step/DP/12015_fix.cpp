/*
Problem: 가장 긴 증가하는 부분 수열 2 (12015)
Tier: Gold 2
Detail: 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은
A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
Comment: lower_bound를 사용하지 않고 하다보니, 함수 오버로드 때문에 조금 시간적으로 손해를 많이 봐서...
+ scanf보다 cin이 빠르더라????
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp;
int IDX = 0, result[1000001];
int *p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    p = new int[N];
    for(int i = 0; i < N; i++) cin >> *(p + i);
    for(int i = 0; i < N; i++) {
        tmp = lower_bound(result, result + IDX, p[i]) - result;
        if(tmp == IDX) IDX++;
        result[tmp] = p[i];
    }
    cout << IDX;
    return 0;
}