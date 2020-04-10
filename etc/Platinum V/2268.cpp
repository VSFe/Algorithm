/*
Problem: 수들의 합
Tier: Platinum 5
Detail: N개의 수 A[1], A[2], …, A[N] 이 주어졌을 때, 함수 Sum(i, j)는 A[i]+A[i+1]+…+A[j]를 구하는 함수이다. (i>j일 경우에는 A[j]+A[j+1]+...+A[i]) A가 주어졌을 때, Sum(i, j)를 구하는 것은 매우 쉬운 문제이다. 이러한 (i, j)가 여러 개 주어졌을 때도 별로 어려운 문제는 아니다.
Sum함수와 더불어 Modify라는 함수를 정의하자. Modify(i, k)를 수행하면 A[i]=k가 되는 함수이다. Sum함수와 Modify 함수의 사용 목록이 주어졌을 때, 이에 해당하는 연산을 하는 프로그램을 작성하시오. 두 함수를 섞어서 사용할 수도 있다.
Comment: 평범한 구간합 - 평범한 세그먼트..
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
    cin >> N >> M;
    int tree_height = (int)(ceil(log2(N)));
    sgtree.assign((1 << (tree_height + 1)), 0);
    arr.assign(N, 0);
    for(int i = 0; i < M; i++) {
        ll x, y, z; cin >> x >> y >> z;
        if(x == 1) {
            ll diff = z - arr[y-1];
            arr[y-1] = z;
            update(1, 0, N-1, y-1, diff);
        }
        else {
            if(y > z) cout << sum(1, 0, N-1, z-1, y-1) << '\n';
            else cout << sum(1, 0, N-1, y-1, z-1) << '\n';
        }
    }
}