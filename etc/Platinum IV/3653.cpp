/*
Problem: 영화 수집 (3653)
Tier: Platinum IV
Detail: 상근이는 영화 DVD 수집가이다. 상근이는 그의 DVD 콜렉션을 쌓아 보관한다.
보고 싶은 영화가 있을 때는, DVD의 위치를 찾은 다음 쌓아놓은 콜렉션이 무너지지 않게 조심스럽게 DVD를 뺀다. 영화를 다 본 이후에는 가장 위에 놓는다.
상근이는 DVD가 매우 많기 때문에, 영화의 위치를 찾는데 시간이 너무 오래 걸린다. 각 DVD의 위치는, 찾으려는 DVD의 위에 있는 영화의 개수만 알면 쉽게 구할 수 있다. 각 영화는 DVD 표지에 붙어있는 숫자로 쉽게 구별할 수 있다.
각 영화의 위치를 기록하는 프로그램을 작성하시오. 상근이가 영화를 한 편 볼 때마다 그 DVD의 위에 몇 개의 DVD가 있었는지를 구해야 한다.
Comment: 위에 있는 DVD의 수 -> 구간 합 -> 세그먼트 트리
그런데 계속해서 구간 자체가 변동이 일어남... -> 쿼리의 수가 10만회를 넘지 않으니 그냥 세그먼트 트리의 노드 수를 N * 2로 만들면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int TC, N, M, index[100001];
vector<int> vec;

int preprocess(int node, int start, int end, int left, int right) {
    if(left > end || start > right) return 0;
    if(start == end) return vec[node] = 1;
    return vec[node] = preprocess(node * 2 + 1, start, (start + end) / 2, left, right) + preprocess(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
}

int get_val(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return vec[node];
    return get_val(node * 2 + 1, start, (start + end) / 2, left, right) + get_val(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, int val) {
    if(index < start || index > end) return;
    vec[node] += val;
    if(start != end) {
        update(node * 2 + 1, start, (start + end) / 2, index, val);       
        update(node * 2 + 2, (start + end) / 2 + 1, end, index, val);       
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        cin >> N >> M;
        int len = N + M;
        int h = (int)ceil(log2(len));
        int tree_size = (1 << (h + 1));
        int cnt = N - 1;
        vec.assign(tree_size, 0);
        preprocess(0, 0, len, 0, N-1);
        for(int i = 1; i <= N; i++) index[i] = N - i;
        for(int i = 0; i < M; i++) {
            int tmp; cin >> tmp;
            if(index[tmp] == cnt) cout << 0 << ' ';
            else {
                update(0, 0, len, index[tmp], -1);
                cout << get_val(0, 0, len, index[tmp], cnt) << ' ';
                index[tmp] = ++cnt;
                update(0, 0, len, index[tmp], 1);
            }
        }
        cout << '\n';
    }
}