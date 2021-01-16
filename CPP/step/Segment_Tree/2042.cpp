/*
Problem: 구간 합 구하기
Tier: Gold 1
Detail: 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다.
Comment: 세 그 먼 트 트 리
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> tree;
vector<ll> data;
int N, M, K;

ll make_tree(int idx, int start, int end) {
    if(start == end) return tree[idx] = data[start];
    return tree[idx] = make_tree(idx * 2, start, (start + end) / 2) + make_tree(idx * 2 + 1, (start + end) / 2 + 1, end);
}

ll find_tree(int idx, int left, int right, int start, int end) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[idx];
    return find_tree(idx * 2, left, right, start, (start + end) / 2) + find_tree(idx * 2 + 1, left, right, (start + end) / 2 + 1, end);
}

void update(int idx, int dest, ll diff, int start, int end) {
    if(dest > end || dest < start) return;
    tree[idx] += diff;
    if(start != end) {
        update(idx * 2, dest, diff, start, (start + end) / 2);
        update(idx * 2 + 1, dest, diff, (start + end) / 2 + 1, end);
    }
}

void init() {
    int height = ceil(log2(N)) + 1;
    tree.resize(1 << height);
    data.resize(N + 1);
    make_tree(1, 0, N - 1);
}

void doQuery() {
    int size = M + K;

    for(int i = 0; i < size; i++) {
        int x, y, z; cin >> x >> y >> z;
        if(x == 1) {
            ll diff = z - data[y - 1];
            update(1, y - 1, diff, 0, N - 1);
            data[y - 1] = z;
        } else {
            cout << find_tree(1, y - 1, z - 1, 0, N - 1) << '\n';
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        data.push_back(tmp);
    }

    init();
    doQuery();
}