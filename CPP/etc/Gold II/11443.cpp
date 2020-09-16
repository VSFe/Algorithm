/*
Problem: 짝수번째 피보나치 수의 합 (11085)
Tier: Gold 2
Detail: 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다. n=17일때 까지 피보나치 수를 써보면 다음과 같다.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
n이 주어졌을 때, 0번째 피보나치 수부터 n번째 피보나치 수 중에서 짝수번째 피보나치 수의 합을 구하는 프로그램을 작성하시오.
Comment: sum(F2i) = F2n+1 - 1
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mx;

const ll divide = 1e9+7;

ll N, ans = 1;
mx matrix = {{1, 1}, {1, 0}}, multiple= {{1, 1}, {1, 0}};

mx operator *(const mx &x, const mx &y) {
    int n = x.size();
    mx z(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                z[i][j] += x[i][k] * y[k][j];
                z[i][j] %= divide;
            }
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    if(N%2) N--;
    while(N) {
        if(N % 2) {
            matrix = matrix * multiple;
        }
            multiple = multiple * multiple;
        N/=2;
    }
    cout << matrix[0][1] - 1;
}