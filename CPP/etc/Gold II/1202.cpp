/*
Problem: 보석 도둑
Tier: Gold 2
Detail: 세계적인 도둑 상덕이는 보석점을 털기로 결심했다. 상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다.
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.
상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.
Comment: multiset을 활용한 그리디.
활용법을 잘 몰라서 고생하긴 했다...
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
long long ans = 0;
vector<pair<int, int>> vec;
multiset <int> ms;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        vec.push_back({y, x});
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    for(int i = 0; i < K; i++) {
        int tmp; cin >> tmp;
        ms.insert(tmp);
    }
    for(int i = 0; i < N; i++) {
        pair<int, int> p = vec[i];
        multiset<int>::iterator iter = ms.lower_bound(p.second);
        if(iter != ms.end()) {
            ms.erase(iter);
            ans += p.first;
        }
    }
    cout << ans;
}