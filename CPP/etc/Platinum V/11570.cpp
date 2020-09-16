/*
Problem: 환상의 듀엣 (11570)
Tier: Platinum V
Detail: 상덕이와 희원이는 소문난 환상의 듀엣으로, 노래방에 가서 노래를 자주 부르곤 한다. 어느 날 상덕이는 백준이에게 선물 받은 악보를 가져왔다.
악보에는 그 노래를 표현하는데 필요한 음의 높이가 순서대로 N개 적혀져 있었다. 둘은 악보에 적혀 있는 모든 음들을 노래해야 하며, 각 음은 둘 중 한 사람에 의해서만 불러져야 한다.
예를 들어 악보에 {3, 6, 2, 5, 4}가 적혀져 있을 때, 상덕이가 {3, 2, 4}을 노래하면 희원이는 {6, 5}를 노래할 것이고, 상덕이가 {6, 2, 5}을 노래하면 희원이는 {3, 4}를 노래할 것이다.
노래를 부르다 음의 높이를 변경하는 것은 힘든 일이다. 예를 들어 {4, 6}을 부르는 것은 {4, 4}를 부르는 것에 비해서 음의 변경이 발생하기 때문에 더 힘들다고 볼 수 있다.
희원이는 {a1, a2, ..., ak}라는 음들의 집합을 노래할 때 힘든 정도를 |a1 - a2| + |a2 - a3| + ... + |ak-1 - ak|로 정의했다.
노래를 부르는 사람은 상덕이와 희원이 둘 뿐이므로, 음들을 집합은 두 개가 있을 것이다. 따라서 두 사람이 해당 악보를 노래를 할 때 힘든 정도는 두 집합의 힘든 정도의 합으로 표현될 수 있다.
상덕이와 희원이는 해당 악보를 노래할 때 힘든 정도를 최소화하고 싶다. 상덕이와 희원이를 위해서 해당 악보를 노래할 때 힘들 수 있는 정도의 최솟값을 알려주는 프로그램을 작성해보자.
Comment: 경찰차 (26618)과 사실상 동일한 문제!!
근데 역추적이 없으니 오히려 더 쉽네.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[2001][2001], note[2001], N, W;

int cal_dp(int x, int y) {
    if(x == N || y == N) return 0;
    int &ret = dp[x][y], k = max(x, y) + 1, t1, t2;
    if(ret != -1) return ret;
    ret = 0;
    if(x == 0) t1 = 0;
    else t1 = abs(note[x] - note[k]);
    if(y == 0) t2 = 0;
    else t2 = abs(note[y] - note[k]);
    ret = min(cal_dp(k, y) + t1, cal_dp(x, k) + t2);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++) cin >> note[i];
    cout << cal_dp(0, 0) << '\n';
    return 0;
}