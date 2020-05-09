/*
Problem: 크리스마스 트리 (1234)
Tier: Gold 1
Detail: 오민식은 오늘이 크리스마스라고 생각해서, 크리스마스 트리를 만들려고 한다. 트리는 N개의 레벨로 이루어져 있다.
위에서부터 레벨1, ... 레벨 N이다. 또, 민식이는 빨강, 파랑, 초록색의 장난감을 가지고 있다. 그리고 민식이는 이 장난감을 일정한 규칙에 의해서 장식하려고 한다.
레벨 K에는 딱 K개의 장난감이 있어야 한다. 또, 각 레벨에 놓으려고 선택한 색이 있으면, 그 색의 장난감의 수는 서로 같아야 한다.
예를 들어, 레벨 3에 장난감을 놓으려고 할 때, 빨강 2, 파랑 1과 같이 놓으면, 빨강과 파랑의 수가 다르기 때문에 안 된다. 하지만, 레벨 4에 빨강 2, 파랑 2와 같이 놓으면, 가능하다.
N과, 장난감의 수가 주어질 때, 트리를 장식하는 경우의 수를 출력하는 프로그램을 작성하시오.
Comment: 조합론으로 접근하면 쉽게 해결...
*/

#include <iostream>
using namespace std;

int N, R, G, B;
long long dp[101][101][101][11], comb[11][11], fac[11];

void preprocess() {
    fac[0] = 1;
    for(int i = 1; i < 11; i++) fac[i] = fac[i - 1] * i;
    for(int i = 0; i < 11; i++) for(int j = 0; j < i; j++) comb[i][j] = fac[i] / fac[j] / fac[i - j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> R >> G >> B;
    dp[R][G][B][0] = 1;
    preprocess();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= R; j++) {
            for(int k = 0; k <= G; k++) {
                for(int l = 0; l <= B; l++) {
                    if(!dp[j][k][l][i]) continue;
                    if(j >= i + 1) dp[j - i - 1][k][l][i + 1] += dp[j][k][l][i];
                    if(k >= i + 1) dp[j][k - i - 1][l][i + 1] += dp[j][k][l][i];
                    if(l >= i + 1) dp[j][k][l - i - 1][i + 1] += dp[j][k][l][i];
                    if((i + 1) % 2 == 0) {
                        int size = (i + 1) / 2;
                        long long add = dp[j][k][l][i] * comb[i + 1][size];
                        if(j >= size) {
                            if(k >= size) dp[j - size][k - size][l][i + 1] += add;
                            if(l >= size) dp[j - size][k][l - size][i + 1] += add;
                        }
                        if(k >= size && l >= size) dp[j][k - size][l - size][i + 1] += add;
                    }
                    if((i + 1) % 3 == 0) {
                        int size = (i + 1) / 3;
                        if(j >= size && k >= size && l >= size) dp[j - size][k - size][l - size][i + 1] += (dp[j][k][l][i] * comb[i + 1][size] * comb[i + 1 - size][size]);
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int j = 0; j <= R; j++) for(int k = 0; k <= G; k++) for(int l = 0; l <= B; l++) ans += dp[j][k][l][N];
    cout << ans;
}