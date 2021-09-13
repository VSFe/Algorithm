#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull power(ull x, ull y, ull mod) {
    ull res = 1;
    x %= mod;
    while (y) {
        if (y % 2) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }

    return res;
}

bool is_prime_using_miller(ull n, ull a) {
    if (a % n == 0) return false;
    ull k = n - 1;
    while (1) {
        ull tmp = power(a, k, n);
        if (tmp == n - 1) return true; // a ^ k = -1 (mod n)
        if (k % 2) return (tmp == 1 || tmp == -1);
        k /= 2;
    }
}

bool is_prime(ull n) {
    ull tester[3] = {2, 7, 61};
    for (int i = 0; i < 3; i++) {
        if (tester[i] == n) return true; 
        if (!is_prime_using_miller(n, tester[i])) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("tc", "r", stdin);

    int N; cin >> N;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        ull tmp; cin >> tmp;
        tmp *= 2;
        tmp++;
        answer += is_prime(tmp);
    }

    cout << answer;
}