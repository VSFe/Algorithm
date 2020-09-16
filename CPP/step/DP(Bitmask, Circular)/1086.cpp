/*
Problem: 박성원 (1086)
Tier: Platinum V
Detail: 박성원은 이 문제를 풀지 못했다.
서로 다른 정수로 이루어진 집합이 있다. 이 집합의 순열을 합치면 큰 정수 하나를 만들 수 있다. 예를 들어, {5221,40,1,58,9}로 5221401589를 만들 수 있다.
합친수가 정수 K로 나누어 떨어지는 순열을 구하는 프로그램을 작성하시오.
하지만, 박성원은 이 문제를 풀지 못했다.
따라서 박성원은 그냥 랜덤하게 순열 하나를 정답이라고 출력하려고 한다. 이 문제에는 정답이 여러 개 있을 수도 있고, 박성원이 우연히 문제의 정답을 맞출 수도 있다.
박성원이 우연히 정답을 맞출 확률을 분수로 출력하는 프로그램을 작성하시오.
Comment: 곱하기도 모듈러 공식이 성립하는지 방금 알았다.....
정수론을 공부해야 하는 것인가 ㅋㅋㅋㅋㅋ;;;;
*/

#define ll long long
#include <iostream>
#include <string>
using namespace std;

struct dt {
    ll num, size;
    dt() {}
    dt(int a, int b) : num(a), size(b) {}
};

int N, K;
ll dp[1<<16 + 1][101], mod_10[51], fac[16];
string str[15];
dt dts[15];

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b,a%b);
}

dt preprocess(string s) {
    int size = s.size();
    int tmp = (s[0] - '0') % K;
    for(int i = 1; i < size; i++) {
        tmp *= 10;
        tmp += (s[i] - '0');
        tmp %= K;
    }
    return dt(tmp, size);
}

ll cal_dp(int visited, int mod) {
    ll &ret = dp[visited][mod];
    if(ret != -1) return ret;
    if(visited == (1 << N) - 1) {
        if(mod) return ret = 0;
        else return ret = 1;
    }
    ret = 0;
    for(int i = 0; i < N; i++) {
        if(!(visited & (1 << i))) {
            ll tmp = (mod * mod_10[dts[i].size] + dts[i].num) % K;
            ret += cal_dp(visited | (1 << i), tmp);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(&dp[0][0], &dp[1<<16][100], -1);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> str[i];
    cin >> K;
    for(int i = 0; i < N; i++) dts[i] = preprocess(str[i]);
    mod_10[0] = 1 % K, fac[0] = 1;
    for(int i = 1; i < 51; i++) mod_10[i] = (mod_10[i-1] * 10) % K;
    for(int i = 1; i <= 15; i++) fac[i] = fac[i-1] * i;
    ll ret = cal_dp(0, 0), divide = gcd(ret, fac[N]);
    cout << ret/divide << '/' << fac[N]/divide << '\n';
    return 0;
}