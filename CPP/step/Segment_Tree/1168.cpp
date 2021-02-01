#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
vector<ll> tree;
vector<int> answer;

ll make_tree(int idx, int start, int end) {
    if(start == end) return tree[idx] = 1;
    else return tree[idx] = make_tree(idx * 2, start, (start + end) / 2) + make_tree(idx * 2 + 1, (start + end) / 2 + 1, end);
}

void find_tree(int idx, int pos, int start, int end, int prev) {
    tree[idx]--;
    if(start == end) answer.push_back(start + 1);
    else if(tree[idx * 2] + prev >= pos) find_tree(idx * 2, pos, start, (start + end) / 2, prev);
    else find_tree(idx * 2 + 1, pos, (start + end) / 2 + 1, end, prev + tree[idx * 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int height = ceil(log2(N)) + 1;
    tree.resize(1 << height);
    make_tree(1, 0, N - 1);
    int cnt = N, idx = -1;
    for(int i = 0; i < N; i++) {
        idx = (idx + K) % (cnt--);
        find_tree(1, idx + 1, 0, N-1, 0);
        idx--;
    }

    cout << '<';
    for(int i = 1; i < answer.size(); i++) cout << answer[i-1] << ", ";
    cout << answer.back() << ">";
}