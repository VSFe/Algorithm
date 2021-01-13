#include <iostream>
using namespace std;

long long N, B, C;
long long ramen[3][1000001];

long long solve() {
	long long result = 0;

	ramen[1][1] = min(ramen[0][1], ramen[0][0]);
	ramen[0][1] -= ramen[1][1];

	for(int i = 2; i < N; i++) {
		ramen[1][i] = min(ramen[0][i], ramen[0][i - 1]);
		ramen[0][i] -= ramen[1][i];
		ramen[2][i] = min(ramen[0][i], ramen[1][i - 1]);
		ramen[0][i] -= ramen[2][i];
	}

	for(int i = 0; i < N; i++) {
		result += ramen[0][i] * B + ramen[1][i] * C + ramen[2][i] * C;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> B >> C;
	if(C >= B) C = B;
	for(int i = 0; i < N; i++) {
		cin >> ramen[0][i];
	}

	cout << solve();
}