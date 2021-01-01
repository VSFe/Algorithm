/*
Problem: 최솟값 찾기(11003)
Tier: Platinum 5
Detail: N개의 수 A1, A2, ..., AN과 L이 주어진다.
Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.
Comment: 덱을 활용한 슬라이딩 윈도우.
슬라이딩 윈도우 자체가 시간복잡도가 O(N)인데, 구간 최솟값을 담기 위해 덱을 사용함.
쉽지 않네...
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L; cin >> N >> L;

    int tmp; cin >> tmp;
    dq.push_front({tmp, 1});
    cout << tmp << ' ';

    for(int i = 2; i <= N; i++) {
        cin >> tmp;
        while(!dq.empty() && dq.back().first > tmp)
            dq.pop_back();
        dq.push_back({tmp, i});
        if(dq.front().second + L - 1 < i)
            dq.pop_front();
        cout << dq.front().first << ' ';
    }
}