/* 세그먼트 트리
부분 합, 구간 내 최댓값, 최솟값 등을 계산하기 위해 사용.

*/

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Segment_tree {
    public:
        Segment_tree() {};
        Segment_tree(int N);
        long long set(const vector<long long>&a, int node, int start, int end);
        long long cal_subtotal(int node, int start, int end, int left, int right);
        void update(int node, int start, int end, int index, long long val);
    private:
        int size;
        vector<long long> vec;
};

Segment_tree::Segment_tree(int N) {
    vec.reserve(N * 4);
}

long long Segment_tree::set(const vector<long long>&a, int node, int start, int end) {
    if(start == end) return vec[node] = a[start];
    else return vec[node] = set(a, node * 2 + 1, start, (start + end) / 2) + set(a, node * 2 + 2, (start + end) / 2 + 1, end);
}

long long Segment_tree::cal_subtotal(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return vec[node];
    return cal_subtotal(node * 2 + 1, start, (start + end) / 2, left, right) + cal_subtotal(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
}

void Segment_tree::update(int node, int start, int end, int index, long long diff) {
    // 차이를 뺌.
    if (index < start || index > end) return;
    vec[node] = vec[node] + diff;
    if (start != end) {
        update(node * 2 + 1, start, (start+end)/2, index, diff);
        update(node * 2 + 2, (start+end)/2+1, end, index, diff);
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    Segment_tree st = Segment_tree(n);
    vector<long long> test(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &test[i]);
    }
    st.set(test, 0, 0, n-1);
    int size = m + k;
    for(int i = 0; i < size; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {
            int diff = z - test[y-1];
            test[y-1] = z;
            st.update(0, 0, n-1, y-1, diff);
        }
        if(x == 2) {
            printf("%lld\n", st.cal_subtotal(0, 0, n-1, y-1, z-1));
        }
    }
    return 0;
}