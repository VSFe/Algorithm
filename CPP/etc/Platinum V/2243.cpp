/*
Problem: 사탕상자 (2243)
Tier: Platinum 5
Comment: 요세푸스 문제 2와 매우 유사하지만 데이터 입력이 있음.
근데 데이터 입력 구현은 전혀 어렵지 않으니까...
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int SIZE = 1e6;
int N;
vector<int> tree;

void find_tree(int idx, int target, int start, int end, int prev) {
    tree[idx]--;
    if(start == end) cout << start << '\n';
    else if(prev + tree[idx * 2] >= target) find_tree(idx * 2, target, start, (start + end) / 2, prev);
    else find_tree(idx * 2 + 1, target, (start + end) / 2 + 1, end, prev + tree[idx * 2]);
}

void update_tree(int idx, int pos, int diff, int start, int end) {
    if(start > pos || pos > end) return;
    tree[idx] += diff;
    if(start != end) {
        update_tree(idx * 2, pos, diff, start, (start + end) / 2);
        update_tree(idx * 2 + 1, pos, diff, (start + end) / 2 + 1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int height = ceil(log2(SIZE));
    tree.resize(1 << (height + 1));
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x == 1) {
            int y; cin >> y;
            find_tree(1, y, 0, SIZE - 1, 0);
        } else {
            int y, z; cin >> y >> z;
            update_tree(1, y, z, 0, SIZE - 1);
        }
    }
}