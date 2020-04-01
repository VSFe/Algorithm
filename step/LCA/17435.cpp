/*
Problem: 합성함수와 쿼리 (17435)
Tier: Gold 1
Detail: 함수 f : {1, 2, ..., m}→{1, 2, ..., m}이 있다. 이때 fn : {1, 2, ..., m}→{1, 2, ..., m}을 다음과 같이 정의하자.
    f1(x) = f(x)
    fn+1(x) = f(fn(x))
예를 들어 f4(1) = f(f(f(f(1))))이다.
n과 x가 주어질 때 fn(x)를 계산하는 쿼리를 수행하는 프로그램을 작성하시오.
Comment: Sparse Table의 활용. 이거 풀고 이왕이면 Sparse Table 문제를 더 풀어봐야겠다...
Sparse Table의 특성인 갱신 없음 + 반복활용을 생각하면 될 것 같음.
*/

#include <iostream>
using namespace std;

int table[19][200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> table[0][i];
    for(int i = 1; i <= 18; i++) {
        for(int j = 1; j <= N; j++) {
            int t = table[i-1][j];
            table[i][j] = table[i-1][t];
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int n, x;
        cin >> n >> x;
		for (int i = 0; n; i++) {
			if (n & 1) x = table[i][x];
			n >>= 1;
		}
        cout << x << '\n';
    }
}