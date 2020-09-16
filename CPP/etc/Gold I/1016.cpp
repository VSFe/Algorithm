/*
Problem: 제곱 ㄴㄴ 수 (1016)
Tier: Gold 1
Detail: 어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다.
min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.
Comment: 에라토스테네스의 체 응용.
소수가 아니라 제곱수를 걸러내보자.
*/

#define ll long long
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1001;

vector<ll> square;
ll N, M;
int ans = 0;

void findPrime(ll start, ll end) {
    bool is_nono[end - start + 1];
    fill(is_nono, is_nono + (end - start + 1), 1);
    for(int i = 0; i < square.size(); i++) {
        ll divide = square[i];
        ll stand = (start % divide) ? start - start % divide + divide : start;
        for(ll j = stand; j <= end; j += divide) {
            is_nono[j - start] = false;
        }
    }
    int len = end - start + 1;
    for(int i = 0; i < len; i++) {
        if(is_nono[i]) ans++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    ll sqrtM = sqrt(M);
    for(ll i = 2; i <= sqrtM; i++) {
        square.push_back(i * i);
    }
    findPrime(N, M);
    cout << ans;
}

