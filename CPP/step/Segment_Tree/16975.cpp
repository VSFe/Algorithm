/*
Problem: 수열과 쿼리 21
Tier: Platinum 4
Comment: 이런식으로 도출할 수 있을지는 몰랐는데...
값은 따로 빼고, 유사 구간합을 활용해서 문제를 해결함.
카카오 블라인드 5번 문제에서 사용했던 접근 방식이네.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> tree;
vector<ll> data;
int N, M, K;

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
    int height = ceil(log2(N+1)) + 1;
    tree.resize(1 << height);
    data.resize(N + 2);
}

void doQuery() {
    for(int i = 0; i < M; i++) {
		int x; cin >> x;
		if(x == 1) {
			int y, z, diff; cin >> y >> z >> diff;
			update(1, y-1, diff, 0, N-1);
			update(1, z, -diff, 0, N-1);
		} else {
			int y; cin >> y;
			cout << find_tree(1, 0, y-1, 0, N-1) + data[y-1] << '\n';
		}   
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        data.push_back(tmp);
    }
	cin >> M;

    init();
    doQuery();
}