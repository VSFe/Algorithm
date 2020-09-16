/*
Problem: 오름세 (3745)
Tier: Gold 3
Detail: 주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.
정인이는 n일 동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.
n일 동안의 주가를 p1, p2, ..., pn이라고 했을 때, 오름세란 부분수열 pi1 < pi2 < ... < pik (i1 < i2 < ... ik)을 말한다.
n일 동안 주가가 주어졌을 때, 가장 긴 오름세를 찾는 프로그램을 작성하시오.
Comment: LIS네.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp;
int IDX = 0, result[100001];
int *p, *res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N) {
        p = new int[N];
        IDX = 0;
        for(int i = 0; i < N; i++) result[i] = 0;
        for(int i = 0; i < N; i++) cin >> *(p + i);
        for(int i = 0; i < N; i++) {
            tmp = lower_bound(result, result + IDX, p[i]) - result;
            if(tmp == IDX) IDX++;
            result[tmp] = p[i];
        }
        cout << IDX << '\n';
        delete p;        
    }
    return 0;
}