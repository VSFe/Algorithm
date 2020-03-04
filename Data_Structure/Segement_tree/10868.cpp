/*
Problem: 최솟값(10868)
Tier: Platinum 5
Detail: N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 것은 어려운 일이 아니다.
하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.
여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최솟값을 찾아야 한다.
각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.
Comment: Segment Tree 활용.
최솟값의 인덱스를 담은 세그먼트 트리를 만들면 될 듯.
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
        long long cal_min(int node, int start, int end, int left, int right);
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
    else return vec[node] = min(set(a, node * 2 + 1, start, (start + end) / 2), set(a, node * 2 + 2, (start + end) / 2 + 1, end));
}

long long Segment_tree::cal_min(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 1000000000;
    if(left <= start && end <= right) return vec[node];
    return min(cal_min(node * 2 + 1, start, (start + end) / 2, left, right), cal_min(node * 2 + 2, (start + end) / 2 + 1, end, left, right));
}

// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Segment_tree st = Segment_tree(n);
    vector<long long> test(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &test[i]);
    }
    st.set(test, 0, 0, n-1);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld\n", st.cal_min(0, 0, n-1, x - 1, y - 1));
    }
    return 0;
}