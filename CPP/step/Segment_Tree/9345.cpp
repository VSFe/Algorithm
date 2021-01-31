/*
Problem: 디지털 비디오 디스크 (DVDs)
Tier: Platinum 3
Comment: 처음엔 부분합/최댓값/최솟값이 모두 일치해야 한다고 판단했는데, 결국 부분합은 별 의미 없었다...
구간 최댓값과 최솟값이 일치하는지 확인하면 되는 문제.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

vector<ll> minTree;
vector<ll> maxTree;
vector<int> data;
int N, M;

ll make_minTree(int idx, int start, int end) {
    if(start == end) return minTree[idx] = start;
    return minTree[idx] = min(make_minTree(idx * 2, start, (start + end) / 2), make_minTree(idx * 2 + 1, (start + end) / 2 + 1, end));
}

ll find_minTree(int idx, int left, int right, int start, int end) {
    if(left > end || right < start) return 1e9;
    if(left <= start && right >= end) return minTree[idx];
    return min(find_minTree(idx * 2, left, right, start, (start + end) / 2), find_minTree(idx * 2 + 1, left, right, (start + end) / 2 + 1, end));
}

ll update_minTree(int idx, int dest, ll diff, int start, int end) {
    if(dest > end || dest < start) return minTree[idx];
	if(start == end) return minTree[idx] = diff;
    return minTree[idx] = min(update_minTree(idx * 2, dest, diff, start, (start + end) / 2), update_minTree(idx * 2 + 1, dest, diff, (start + end) / 2 + 1, end));
}

ll make_maxTree(int idx, int start, int end) {
    if(start == end) return maxTree[idx] = start;
    return maxTree[idx] = max(make_maxTree(idx * 2, start, (start + end) / 2), make_maxTree(idx * 2 + 1, (start + end) / 2 + 1, end));
}

ll find_maxTree(int idx, int left, int right, int start, int end) {
    if(left > end || right < start) return -1;
    if(left <= start && right >= end) return maxTree[idx];
    return max(find_maxTree(idx * 2, left, right, start, (start + end) / 2), find_maxTree(idx * 2 + 1, left, right, (start + end) / 2 + 1, end));
}

ll update_maxTree(int idx, int dest, ll diff, int start, int end) {
    if(dest > end || dest < start) return maxTree[idx];
	if(start == end) return maxTree[idx] = diff;
    return maxTree[idx] = max(update_maxTree(idx * 2, dest, diff, start, (start + end) / 2), update_maxTree(idx * 2 + 1, dest, diff, (start + end) / 2 + 1, end));
}

void solve() {
	cin >> N >> M;
	data.assign(N, 0);

	for(int i = 1; i < N; i++) data[i] = i;
	int height = ceil(log2(N)) + 1;

	minTree.assign(1 << height, 0);
	maxTree.assign(1 << height, 0);
	make_minTree(1, 0, N - 1);
	make_maxTree(1, 0, N - 1);

	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		if(x == 0) {
			int y, z; cin >> y >> z;
			update_maxTree(1, y, data[z], 0, N - 1);		
			update_minTree(1, y, data[z], 0, N - 1);		

			update_maxTree(1, z, data[y], 0, N - 1);		
			update_minTree(1, z, data[y], 0, N - 1);		

			swap(data[y], data[z]);
		} else {
			long long y, z; cin >> y >> z;
			int mini = find_minTree(1, y, z, 0, N - 1);
			int maxi = find_maxTree(1, y, z, 0, N - 1);
			if(mini == y && maxi == z) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC; cin >> TC;
	for(int i = 0; i < TC; i++) solve();
}