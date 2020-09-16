/*
Problem: 헨리 (10253)
Tier: Gold 2
Detail: 생략
Comment: gcd를 활용해 x를 반복적으로 계산하는 식을 생성함.
전처리가 중요한 문제라고 생각되네...
*/

#include <iostream>
using namespace std;

int N;

long long get_gcd(long long x, long long y) {
    return (x % y) ? get_gcd(y, x % y) : y;
}

long long get_ans(long long x, long long y) {
    while(x != 1) {
        long long t = y/x + 1;
        long long gcd = get_gcd(y, t);
        long long lcm = y * t / gcd;
        x = lcm/y * x - lcm/t;
        y = lcm;
        long long tmp = get_gcd(x, y);
        if(tmp != 1) {
            x /= tmp;
            y /= tmp;
        }
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long x, y; cin >> x >> y;
        cout << get_ans(x, y) << '\n';
    }
}