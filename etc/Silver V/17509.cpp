/*
Problem: And the Winner is... Ourselves! (17509)
Tier: Silver 5
Detail: Let us remind you about how the total penalties are calculated for this contest:
    When you solve a problem at T iminutes, T + 20V is added to your penalty, where V is the number of incorrect verdicts (except compile errors) received on that problem.
    If you do not solve a problem before the contest ends, the incorrect verdicts on that problem are not counted as penalties.
Here is a bad news for all of you: we, the problem setters, are planning to join the competition and solve our own problems!
We know our problems really well, so we can solve all the problems before the contest ends. Furthermore, we can precisely predict how long it takes to solve each problem,
and how many incorrect verdicts (except compile errors) we get in each problem.
Depending on the order of the problems we solve, our total penalty might differ. What is the minimum penalty if we solve all problems?
Comment: 오답 페널티는 따로 계산하고, 시간 더하는 건 당연히 가중치가 붙으니 작은 것 부터 더하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0, D, V;
    vector<int> vec(11);
    for(int i = 0; i < 11; i++) {
        cin >> D >> V;
        ans += V * 20;
        vec[i] = D;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < 10; i++) vec[i+1] += vec[i];
    for(int i = 0; i < 11; i++) ans += vec[i];
    cout << ans;
    return 0;
}