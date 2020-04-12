/*
Problem: 소수의 곱
Tier: Gold 2
Detail: K개의 소수가 있다. 이때, 이 소수들 중에서 몇 개를 곱해서 얻게 되는 수들이 있을 것이다. 소수들을 선택할 때에는 같은 수를 선택해도 되며, 주어지는 소수 자체도 포함시키자.
예를 들어 세 소수가 2, 5, 7이었다면, 이러한 곱들을 오름차순으로 나타내 보면, 2, 4, 5, 7, 8, 10, 14, 16, 20, 25, 28, 32, 35, 등이 된다.
K개의 소수가 주어졌을 때, 이러한 소수의 곱들 중에서 N번째 수를 구해 보자. 단 정답은 231보다 작은 자연수이다.
Comment: 우큐에 계속 넣자.
메모리 터지는 것 때문에 계속 고생했는데 생각을 해보니 뭐... 적당히 잘 컷팅하면 되는 문제였다.
*/

#define ll long long
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

unordered_set<ll> um;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int primes[100], N, M, cnt = 1, MAX = 0;
int prev_num = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> primes[i];
        pq.push(primes[i]);
        um.insert(primes[i]);
    }
    MAX = primes[N-1];
    while(cnt != M) {
        ll t = pq.top(); pq.pop();
        um.erase(t);
        cnt++;
        for(int i = 0; i < N; i++) {
            ll tmp = (ll)(primes[i]) * t;
            if(tmp < 0 || (pq.size() >= M && tmp > MAX)) break;
            MAX = (MAX < tmp) ? tmp : MAX;
            if(um.find(tmp) == um.end()) {
                pq.push(tmp);
                um.insert(tmp);                
            }
        }
    }
    cout << pq.top();
}
