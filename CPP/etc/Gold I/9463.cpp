/*
Problem: 순열 그래프 (9463)
Tier: Gold 1
Detail: 그래프 G는 정점의 집합 V와 간선의 집합 E로 이루어져 있고, G = (V, E)로 나타낸다. 대부분의 경우에 V와 E는 명시되어 있다.
일부 그래프의 경우에는 집합이 명시되어 있지 않다. 예를 들어, 순열 그래프는 간선의 집합이 명시되어 있지 않다.
{1, 2, 3, 4, 5}로 이루어진 두 순열 (2, 5, 4, 1, 3)과 (1, 5, 3, 2, 4)가 있다. 평행선을 그리고, 그 위에 순열에 적힌 숫자 순서대로 정점을 그린다.
그 다음 같은 숫자끼리 선분을 연결한다. 아래 그림과 같이 교차하는 선분의 쌍은 총 여섯 개라는 것을 알 수 있다.
교차하는 쌍은 순열 그래프의 간선이 된다. 순열 그래프의 정점은 숫자가 되고, 간선은 교차하는 쌍이 된다.
위의 예를 이용해 순열 그래프를 만들면 V = {1, 2, 3, 4, 5}, E = {(1,2), (1,4), (1,5), (2,3), (2,5), (3,4)}. 위의 두 순열을 이용해 순열 그래프를 그리면 아래 그림과 같이 된다.
{1, 2, ..., n}으로 이루어진 두 순열이 주어졌을 때, 두 순열을 이용해 만든 순열 그래프의 간선의 개수를 구하는 프로그램을 작성하시오.
예를 들어, (2, 5, 4, 1, 3)과 (1, 5, 3, 2, 4)로 만든 순열 그래프의 간선의 개수는 6개이다.
Comment: 세그먼트 트리 활용문제...
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int TC, N;
long long answer = 0;

int make_tree(vector<int> &tree, int node, int start, int end) {
    if(start == end) return tree[node] = 1;
    return tree[node] = make_tree(tree, node * 2 + 1, start, (start + end) / 2) + make_tree(tree, node * 2 + 2, (start + end) / 2 + 1, end);
}

void update(vector<int> &tree, int node, int start, int end, int index) {
    if(start > index || index > end) return;
    tree[node] -= 1;
    if(start != end) {
        update(tree, node * 2 + 1, start, (start + end)/2, index);
        update(tree, node * 2 + 2, (start + end)/2 + 1, end, index);
    }
}

int get_ans(vector<int> &tree, int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return get_ans(tree, node * 2 + 1, start, (start + end) / 2, left, right) + get_ans(tree, node * 2 + 2, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    while(TC--) {
        answer = 0;
        cin >> N;
        int h = (int)ceil(log2(N));
        int tree_size = (1 << (h + 1));
        vector<int> vec(tree_size, 0);
        make_tree(vec, 0, 0, N-1);
        vector<int> idx(N + 1, 0);
        for(int i = 0; i < N; i++) {
            int x; cin >> x;
            idx[x] = i;
        }
        for(int i = 0; i < N; i++) {
            int x; cin >> x;
            answer += (get_ans(vec, 0, 0, N - 1, 0, idx[x]) - 1);
            update(vec, 0, 0, N-1, idx[x]);
        }
        cout << answer << '\n';
    }
}