/*
Problem: 좋은 친구 (3078)
Tier: Gold 3
Detail: 상근이네 반의 N명 학생들의 이름이 성적순으로 주어졌을 때, 좋은 친구가 몇 쌍이나 있는지 구하는 프로그램을 작성하시오.
좋은 친구는 등수의 차이가 K보다 작거나 같으면서 이름의 길이가 같은 친구이다.
Comment: 배열에 글자의 길이만큼 저장.
*/

#include <iostream>
#include <string>
using namespace std;

int dt[300001], len[21], N, K;
long long ans = 0;
string st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cin >> N >> K;
    K++;
    for(int i = 0; i < N; i++) {
        cin >> st;
        dt[i] = st.size();
    }
    for(int i = 0; i < K; i++) {
        len[dt[i]]++;
    }
    int stand = N - K;
    for(int i = 0; i < stand; i++) {
        ans += --len[dt[i]];
        len[dt[i + K]]++;
    }
    for(int i = stand; i < N; i++) {
        ans += --len[dt[i]];
    }
    cout << ans;
}