/*
Problem: 부분수열의 합 2 (1208)
Tier: Gold 2
Detail: N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
Comment: Meet in the Middle 문제. 이런 유형이 처음이어서 엄청 헤메긴 했는데, 문제를 쪼개서 해결할 수 있는 방법을 고민해보자.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, S, sizeFirst, sizeSecond;
int dt[40];
vector<int> dtFirst, dtSecond;

void dfsFirst(int idx, int sum) {
    if(idx == sizeFirst) dtFirst.push_back(sum);
    else {
        dfsFirst(idx + 1, sum + dt[idx]);
        dfsFirst(idx + 1, sum);
    }
}

void dfsSecond(int idx, int sum) {
    if(idx == sizeSecond) dtSecond.push_back(sum);
    else {
        dfsSecond(idx + 1, sum + dt[sizeFirst + idx]);
        dfsSecond(idx + 1, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> dt[i];
    sizeFirst = N / 2, sizeSecond = N - sizeFirst;
    dfsFirst(0, 0);
    dfsSecond(0, 0);
    sort(dtFirst.begin(), dtFirst.end(), greater<int>());
    sort(dtSecond.begin(), dtSecond.end(), less<int>());
    int idxFirst = 0, idxSecond = 0;
    ll ans = 0;
    while(idxFirst < dtFirst.size() && idxSecond < dtSecond.size()) {
        if(dtFirst[idxFirst] + dtSecond[idxSecond] == S) {
            ll tmpFirst = 0, tmpSecond = 0;
            while(idxFirst + tmpFirst != dtFirst.size() && dtFirst[idxFirst] == dtFirst[idxFirst + tmpFirst]) tmpFirst++;
            while(idxSecond + tmpSecond != dtSecond.size() && dtSecond[idxSecond] == dtSecond[idxSecond + tmpSecond]) tmpSecond++;
            ans += (tmpFirst) * (tmpSecond);
            idxFirst += tmpFirst;
            idxSecond += tmpSecond;
        }
        if(dtFirst[idxFirst] + dtSecond[idxSecond] < S) idxSecond++;
        if(dtFirst[idxFirst] + dtSecond[idxSecond] > S) idxFirst++;
    }
    if(!S) ans--;
    cout << ans;
}