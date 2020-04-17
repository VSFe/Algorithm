/*
Problem: 데이터 구조 (12899)
Tier: Platinum IV
Detail: 자연수를 저장하는 데이터베이스 S에 대해 다음의 쿼리를 처리합시다.
유형 1 : S에 자연수 X를 추가한다.
유형 2 : S에 포함된 숫자 중 X번째로 작은 수를 응답하고 그 수를 삭제한다.
Comment: 세그먼트 트리에 익숙하지 않아서 이런 유형이 아직 어렵다...
숫자를 정말 일일히 추가할 생각을 하지 말고, 2000000이라는 범위가 정해졌기 때문에 그냥 해당 전체구간을 세그먼트 트리로 활용하면 된다.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int stand = 2000000;
int N;

void update(vector<int> &tree, int node, int start, int end, int index) {
    if(start > index || index > end) return;
    tree[node] += 1;
    if(start != end) {
        update(tree, node * 2 + 1, start, (start + end)/2, index);
        update(tree, node * 2 + 2, (start + end)/2 + 1, end, index);
    }
}

void kth(vector<int> &tree, int node, int start, int end, int index, int prev) {
    tree[node]--;
    if(start == end) cout << start << '\n';
    else if(tree[node * 2 + 1] + prev >= index) kth(tree, node * 2 + 1, start, (start + end)/2,  index, prev);
    else kth(tree, node * 2 + 2, (start + end) / 2 + 1, end, index, prev + tree[node * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int h = (int)ceil(log2(stand));
    int tree_size = (1 << (h + 1));
    vector<int> vec(tree_size, 0);
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        if(x == 1) update(vec, 0, 0, stand, y);
        else kth(vec, 0, 0, stand, y, 0);
    }
}