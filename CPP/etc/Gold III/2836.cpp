/*
Problem: 수상 택시 (2836)
Tier: Gold 3
Detail: 상근이가 살고 있는 도시에는 큰 강이 흐르고 있고, 모든 사람의 집은 이 강 근처에 있다.
집은 0번부터 M번까지 강을 따라서 번호가 매겨져 있고, 인접한 집 사이의 거리는 모두 1 킬로미터이다.
상근이는 0번 집에 살고 있고, 보트를 이용해서 사람들을 운송하는 일을 하고 있다. 오늘은 저녁때까지 M번 집으로 가야한다. 상근이는 M번 집으로 가는 길에 사람들을 태워주려고 한다.
오늘 상근이의 수상 택시를 타려고 하는 사람은 총 N명이다. 상근이는 각 사람들이 탑승할 위치와 목적지를 알고 있다. 상근이의 보트는 매우 커서 N명 모두 보트에 태울 수 있다.
예를 들어, 사람 A가 2번 집에서 8번으로 가려고 하고, B가 6에서 4로 가려고 하는 경우를 생각해보자. 상근이는 0번 집에서 시작해서, 2번에서 A를 태우고, 6번에서 B를 태울 것이다.
그 다음 4로 돌아가 B를 내려주고, 8번에서 A를 내려다준다. 그 다음에 원래 상근이가 가려고 했던 M번 집으로 가면 된다.
상근이가 모든 사람을 데려다주고, M번 집으로 가기 위해서 이동해야 하는 거리의 최솟값을 구하는 프로그램을 작성하시오.
Comment: 조금 생각이 필요한 스위핑 문제.
문제가 스위핑이라는 생각이 들면 정확한 구현 방식을 고민해보고 건드릴 것.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
pair<int, int> direc[300001];
const int INF = 1e9;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/root/debug/rijeka.in.9", "r", stdin);
    #endif
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        direc[i] = {x, y};
    }
    sort(direc, direc + N, compare);
    long long ans = 0;
    int start = 0, end = 0;
    for(int i = 0; i < N; i++) {
        if(direc[i].first > direc[i].second) {
            if(direc[i].second > end) {
                ans += (end - start);
                start = direc[i].second;
                end = direc[i].first;
            }
            else {
                end = max(end, direc[i].first);
            }
        }
    }
    ans += (end - start);
    cout << M + ans * 2;
}