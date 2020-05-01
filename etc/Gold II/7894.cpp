/*
Problem: 큰 수 (7894)
Tier: Gold 2
Detail: 많은 어플리케이션은 매우 큰 수를 사용한다. 이러한 어플리케이션은 데이터를 안전하게 전송하고, 암호화하기 위해서 수를 키로 사용한다.
수가 주어지면, 그 수의 팩토리얼의 자리수를 구하는 프로그램을 작성하시오.
Comment: log 10의 합
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC, N;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        double ans = 0;
        cin >> N;
        for(int i = 1; i <= N; i++) {
            ans += log10(i);
        }
        cout << int(ans) + 1 << '\n';
    }
}