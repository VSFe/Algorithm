#include <iostream>
using namespace std;
#define ll long long

const int SIZE = 500001;
ll answer = 3e9;
ll mu[SIZE];

void preprocess() {
    mu[1] = 1;
    for (int i = 1; i < SIZE; i++) {
        for (int j = 2 * i; j < SIZE; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll cal(ll n) {
    ll cnt = 0;
    for(ll i = 1; i * i <= n; i++) cnt += mu[i] * (n / (i * i));
    return n - cnt;
}

int main() {
    preprocess();
	ll N; cin >> N;

	ll left = 0, right = 1e11;
	while(left < right) {
		ll mid = (left + right) / 2;
		if(cal(mid) < N) left = mid + 1;
		else {
			right = mid;
		}
	}

	cout << right;

    return 0;
}