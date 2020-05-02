/*
Problem: 피보나치 수와 최대공약수 (11778)
Tier: Gold 1
Detail: 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다. n=17일때 까지 피보나치 수를 써보면 다음과 같다.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
n과 m이 주어졌을 때, n번째 피보나치 수와 m번째 피보나치 수의 최대공약수를 구하는 프로그램을 작성하시오.
Comment: A번째 피보나치 수와 B번째 피보나치 수의 최대공약수는 F(gcd(A, B))이다.
그러니 바로 구해주면 됨.
*/

#include <iostream>
using namespace std;

typedef long long ll;
ll x1, x2;
ll A[2][2] = {{0, 1}, {1, 1}}, result[2][2] = {{1, 0}, {0, 1}}, tmp[2][2];
const int divide = 1e9 + 7;

ll gcd(ll x, ll y) {
    return (x % y) ? gcd(y, x % y) : y;
}

int cal_sum(int x, int y, ll A[2][2], ll B[2][2]) {
    int sum = 0;
    for(int i = 0; i < 2; i++) {
        sum+= (A[x][i] * B[i][y]) % divide;
    }
    return sum % divide;
}

void multiply(ll x[2][2], ll y[2][2]) {
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int sum = cal_sum(i, j, x, y);
            tmp[i][j] = sum;
        }
    }
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x1 >> x2;
    if(x1 < x2) swap(x1, x2);
    ll N = gcd(x1, x2);
    while(N != 0) {
        if(N % 2 == 0) {
            multiply(A, A);
            N /= 2;
        }
        else {
            multiply(result, A);
            N--;
        }
    }
    cout << result[0][1];
}