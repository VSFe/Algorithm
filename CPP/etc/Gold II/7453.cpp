/*
Problem: 합이 0인 네 정수 (7453)
Tier: Gold 2
Detail: 정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.
A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.
Comment: 반 갈 죽
네개의 합을 구하는 방법은 사실상 없으니, 두개의 합으로 바꿔서 푸는 것이 핵심 아이디어.
해싱을 하면 더 빠르게 풀 수 있다던데 아직은 모르겠다...
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[4000], b[4000], c[4000], d[4000];
int ab[16000000], cd[16000000];
int N;
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ab[i + N * j] = a[i] + b[j];
            cd[i + N * j] = c[i] + d[j];
        }
    }
    int size = N * N;
    sort(cd, cd + size);
    for(int i = 0; i < size; i++) {
        ans += (upper_bound(cd, cd + size, ab[i] * -1) - lower_bound(cd, cd + size, ab[i] * -1));
    }
    cout << ans;
}