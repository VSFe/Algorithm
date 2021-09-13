#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    while (y) {
        if (y % 2) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }

    return res;
}

bool is_prime_using_miller(ll n, ll a) {
    if (a % n == 0) return false;
    ll k = n - 1;
    while (1) {
        ll tmp = power(a, k, n);
        if (tmp == n - 1) return true; // a ^ k = -1 (mod n)
        if (k % 2) return (tmp == 1 || tmp == -1);
        k /= 2;
    }
}

bool is_prime(ll n) {
    ll tester[4] = {2, 7, 37, 61};
    for (int i = 0; i < 4; i++) if (!is_prime_using_miller(n, tester[i])) return false;
    return true;
}