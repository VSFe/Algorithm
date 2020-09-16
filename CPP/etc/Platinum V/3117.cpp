/*
Problem: YouTube (3117)
Tier: Platinum 5
Detail: YouTube에는 K개의 동영상이 있고, 1번부터 K번까지 번호가 매겨져 있다. 동영상을 볼 때, 우측에는 추천 동영상이 떠있다.
모든 학생은 메인 페이지에서 동영상 하나를 시청한다. 동영상을 시청하고 1분이 지나면, 추천 동영상 중 가장 위에 있는 동영상을 시청한다. (모든 동영상은 정확히 1분만 시청한다)
각 학생이 처음에 시청한 동영상 번호와, 각 동영상의 추천 동영상 중 가장 위에 있는 동영상의 번호가 주어졌을 때, M분에 각 학생이 시청한 동영상 번호를 출력하는 프로그램을 작성하시오.
Comment: 합성함수와 쿼리 (17435)와 사실상 완전히 동일한 문제. 수가 커서 난이도가 오른건가 봐...
*/

#include <iostream>
using namespace std;

int table[32][100001];
int pending[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K, M;
    cin >> N >> K >> M;
    for(int i = 1; i <= N; i++) cin >> pending[i];
    for(int i = 1; i <= K; i++) cin >> table[0][i];
    for(int i = 1; i <= 31; i++) {
        for(int j = 1; j <= K; j++) {
            int t = table[i-1][j];
            table[i][j] = table[i-1][t];
        }
    }
    M--;
    for(int idx = 1; idx <= N; idx++) {
        int x = pending[idx], tmp = M;
        for(int i = 0; tmp; i++) {
            if(tmp & 1) x = table[i][x];
            tmp >>= 1;
        }
        cout << x << ' ';
    }
    return 0;
}