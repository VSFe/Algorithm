#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE = 1e6 + 1;
vector<int> primes;
bool isPrime[SIZE];

void find_primes() {
    primes.push_back(2);
    int size = sqrt(SIZE);
    for (int i = 2; i <= SIZE; i += 2) isPrime[i] = true;
    for (int i = 3; i <= size; i += 2) {
        if (isPrime[i]) continue;
        primes.push_back(i);

        for (int j = i * i; j <= SIZE; j += i) {
            isPrime[j] = true;
        }
    }
    for (int i = size + 1; i <= SIZE; i++)
        if (!isPrime[i]) primes.push_back(i);
}

void solve() {
    ll x, y; cin >> x >> y;

    vector<pair<ll, ll>> factorization;
    ll tmp = y;
    for (int num : primes) {
        ll cnt = 0;
        while (tmp % num == 0) {
            cnt++;
            tmp /= num;
        }
        if (cnt) factorization.push_back({num, cnt});
    }
    if (tmp != 1) factorization.push_back({tmp, 1});

    ll answer = 1e18;
    for (auto val : factorization) {
        ll cnt = 0;
        ll tmp = x / val.first;
        while (tmp) {
            cnt += tmp;
            tmp /= val.first;
        }
        answer = min(answer, cnt / val.second);
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    find_primes();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) solve();
}