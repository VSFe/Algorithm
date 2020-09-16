/*
Problem: 구간 곱 구하기 (11505)
Tier: Platinum V
Detail: 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 곱을 구하려 한다.
만약에 1, 2, 3, 4, 5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 곱을 구하라고 한다면 240을 출력하면 되는 것이다.
그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 곱을 구하라고 한다면 48이 될 것이다.
Comment: 전~~~~형적인 세그먼트
*/
#define DIVIDE 1000000007
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
    else return vec[node] = (set(a, node * 2 + 1, start, (start + end) / 2) * set(a, node * 2 + 2, (start + end) / 2 + 1, end)) % DIVIDE;
}

long long Segment_tree::cal_subtotal(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return vec[node];
    return (cal_subtotal(node * 2 + 1, start, (start + end) / 2, left, right) * cal_subtotal(node * 2 + 2, (start + end) / 2 + 1, end, left, right)) % DIVIDE;
}

void Segment_tree::update(int node, int start, int end, int index, long long val) {
    // 차이를 뺌.
    if (index < start || index > end) return;
    if (start == end) return vec[node] = val;
    if (start != end) {
        return vec[node] = update(node * 2 + 1, start, (start+end)/2, index, diff) * update(node * 2 + 2, (start+end)/2+1, end, index, diff);
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
            double diff = z / test[y-1];
            test[y-1] = z;
            st.update(0, 0, n-1, y-1, diff);
        }
        if(x == 2) {
            printf("%lld\n", st.cal_subtotal(0, 0, n-1, y-1, z-1));
        }
    }
    return 0;
}