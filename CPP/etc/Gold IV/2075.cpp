#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    int size = N * N;
    for(int i = 0; i < size; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);

        if(pq.size() == N + 1)
            pq.pop();
    }

    while(pq.size() == 1) pq.pop();
    cout << pq.top();
}