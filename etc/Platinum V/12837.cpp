/*
Problem: 가계부 (Hard)
Tier: Platinum 5
Detail: 작성될 가계부 프로그램은 두 가지 동작을 처리해야 한다. 첫 번째는 월곡이의 생후 p일에 수입/지출 내용을 추가하는 것이다.
수입은 양수, 지출은 음수의 형태로 입력이 들어온다. 두 번째는 월곡이의 생후 p일부터 q일까지 잔고가 변화한 값을 구하고 출력하는 것이다.
월곡이가 빚을 지고 있을 수도 있기에 어떤 i에 대해서 생후 i일의 잔고는 음수일 수 있다.
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
        if(x == 1) update(1, 0, N-1, y-1, z);
        else {
            ll x1 = sum(1, 0, N-1, y - 1, y - 1);
            ll x2 = sum(1, 0, N-1, z - 1, z - 1);
            cout << sum(1, 0, N-1, y-1, z-1) << '\n';
        }
    }
}