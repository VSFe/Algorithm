/*
Problem: 놀이 공원
Tier: Gold 2
Detail: N명의 아이들이 한 줄로 줄을 서서 놀이공원에서 1인승 놀이기구를 기다리고 있다. 이 놀이공원에는 총 M종류의 1인승 놀이기구가 있으며, 1번부터 M번까지 번호가 매겨져 있다.
모든 놀이기구는 각각 운행 시간이 정해져 있어서, 운행 시간이 지나면 탑승하고 있던 아이는 내리게 된다. 놀이 기구가 비어 있으면 현재 줄에서 가장 앞에 서 있는 아이가 빈 놀이기구에 탑승한다.
만일 여러 개의 놀이기구가 동시에 비어 있으면, 더 작은 번호가 적혀 있는 놀이기구를 먼저 탑승한다고 한다.
놀이기구가 모두 비어 있는 상태에서 첫 번째 아이가 놀이기구에 탑승한다고 할 때, 줄의 마지막 아이가 타게 되는 놀이기구의 번호를 구하는 프로그램을 작성하시오.
Comment: 대체 언제 애들이 다 타는지 구하는 것 부터 막막함 -> 아분탐색으로 구함.
해당 시간을 찾으면 그 시간에 몇명이나 더 받아야 하는지 구해야 하니 맞춰서 구하면 끝.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int N, M, play[10001];

ll cal_kids(ll time) {
    ll ans = 0;
    time--;
    for(int i = 0; i < M; i++) {
        ans += time / play[i] + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("/root/debug/input.txt", "r", stdin);
    #endif
    cin >> N >> M;
    if(N <= M) {
        cout << N;
        return 0;
    }
    for(int i = 0; i < M; i++) {
        cin >> play[i];
    }
    ll left = 0, right = 6e10;
    while(left != right) {
        ll mid = (left + right) / 2;
        if(cal_kids(mid) >= N) right = mid;
        else left = (mid + 1);
    }
    int size = N - cal_kids(left - 1);
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if((left - 1) % play[i] == 0) size--;
        if(!size) {
            ans = i;
            break;
        }
    }
    cout << ans + 1;
}