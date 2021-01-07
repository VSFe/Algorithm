/*
Problem: 수 고르기 (3988)
Tier: Platinum 4
Detail: 수열이 주어졌을 때, M을 수열의 모든 두 원소의 차이 중 가장 큰 값이라고 한다.
m은 그 차이 중 가장 작은 값이라고 한다.
크기가 N인 수열 V가 주어진다. 여기서 K개 수를 적절히 제거해서 M+m을 가능한 작게 만드는 프로그램을 작성하시오.
Comment: 어차피 정렬하면 M은 쉽게 나옴.
그러면 m을 구해야 하는데... 어떻게 할까?
예전에 풀었던 최솟값 구하는 문제와 유사함.
이걸 Monotone Prority Queue라고 하는데, 내부에 순차적으로 정렬하는 방식으로 구현.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int answer = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    K = N - K;
    deque<int> dq;

    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int left = 0, right = 1;
    while(left != N - K) {
        while(!dq.empty() && dq.front() < left) dq.pop_front();

        while(right != left + K) {
            while(!dq.empty() && vec[right] - vec[right - 1] < vec[dq.back()] - vec[dq.back() - 1])
                dq.pop_back();

            dq.push_back(right++);
        }

        int m = vec[dq.front()] - vec[dq.front() - 1];
        int M = vec[left + K - 1] - vec[left];

        answer = min(answer, m + M);

        left++;
    }
    cout << answer;
}