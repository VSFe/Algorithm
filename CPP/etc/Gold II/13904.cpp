/*
Problem: 과제 (13904)
Tier: Gold 2
Detail: 웅찬이는 과제가 많다. 하루에 한 과제를 끝낼 수 있는데, 과제마다 마감일이 있으므로 모든 과제를 끝내지 못할 수도 있다.
과제마다 끝냈을 때 얻을 수 있는 점수가 있는데, 마감일이 지난 과제는 점수를 받을 수 없다.
웅찬이는 가장 점수를 많이 받을 수 있도록 과제를 수행하고 싶다. 웅찬이를 도와 얻을 수 있는 점수의 최댓값을 구하시오.
Comment: DP인 줄 알고 삽질했는데 그리디...
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans[1001];
pair<int, int> pp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pp[i] = {y, x};
    }
    sort(pp, pp + N, greater<pair<int, int>>());
    for(int i = 0; i < N; i++) {
        pair<int, int> p = pp[i];
        for(int j = p.second; j >= 1; j--) {
            if(!ans[j]) {
                ans[j] = p.first;
                break;
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= 1000; i++) answer += ans[i];
    cout << answer;
}