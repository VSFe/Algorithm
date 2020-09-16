/*
Problem: 구간 합 구하기
Tier: Platinum 5
Detail: 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다.
Comment: 세 그 먼 트 트 리
*/

#define ll long long
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M, K;
vector<ll> sgtree, arr;

ll make_tree(int node, int start, int end) {
    if(start == end) return sgtree[node] = arr[start];
    return sgtree[node] = make_tree(node * 2, start, (start + end)/2) + make_tree(node*2 + 1, (start + end)/2 + 1, end);
}

void update(int node, int start, int end, int index, ll diff) {
    if(index > end || index < start) return;
    sgtree[node] += diff;
    if(start != end) {
        update(node * 2, start, (start + end)/ 2, index, diff);
        update(node * 2 + 1, (start + end)/ 2 + 1, end, index, diff);        
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return sgtree[node];
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    int tree_height = (int)(ceil(log2(N)));
    sgtree.assign((1 << (tree_height + 1)), 0);
    arr.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    make_tree(1, 0, N-1);
    M += K;
    for(int i = 0; i < M; i++) {
        ll x, y, z; cin >> x >> y >> z;
        if(x == 1) {
            ll diff = z - arr[y-1];
            arr[y-1] = z;
            update(1, 0, N-1, y-1, diff);
        }
        else cout << sum(1, 0, N-1, y - 1, z - 1) << '\n';
    }
}