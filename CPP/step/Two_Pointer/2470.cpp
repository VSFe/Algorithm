/*
Problem: 두 용액 (2470)
Tier: Gold 5
Detail: KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.
산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.
같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다. 
산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.
Commant: 투포인터 입문 문제. 계속 값을 갱신하는 것과 별개로 두 합이 양수면 right를 줄이고, 음수면 left를 올려주면 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int data[100001];
int N;
int answer = 2e9;
int answer_left, answer_right;

void solve() {
    int left = 0, right = N - 1;
    while(left < right) {
        if(answer > abs(data[right] + data[left])) {
            answer = abs(data[right] + data[left]);
            answer_left = data[left];
            answer_right = data[right];
        }
        if(data[right] + data[left] > 0) right--;
        else left++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> data[i];
    sort(data, data + N);
    solve();
    cout << answer_left << ' ' << answer_right;
}