#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Min_Segment_tree {
    public:
        Min_Segment_tree() {};
        Min_Segment_tree(int N);
        long long set(const vector<long long>&a, int node, int start, int end);
        long long cal_min(int node, int start, int end, int left, int right);
        void update(int node, int start, int end, int index, long long val);
    private:
        int size;
        vector<long long> vec;
};

class Max_Segement_tree {
    public:
        Max_Segement_tree() {};
        Max_Segement_tree(int N);
        long long set(const vector<long long>&a, int node, int start, int end);
        long long cal_min(int node, int start, int end, int left, int right);
        void update(int node, int start, int end, int index, long long val);
    private:
        int size;
        vector<long long> vec;
};

Max_Segement_tree::Max_Segement_tree(int N) {
    vec.reserve(N * 4);
}

long long Max_Segement_tree::set(const vector<long long>&a, int node, int start, int end) {
    if(start == end) return vec[node] = a[start];
    else return vec[node] = max(set(a, node * 2 + 1, start, (start + end) / 2), set(a, node * 2 + 2, (start + end) / 2 + 1, end));
}

long long Max_Segement_tree::cal_min(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return vec[node];
    return max(cal_min(node * 2 + 1, start, (start + end) / 2, left, right), cal_min(node * 2 + 2, (start + end) / 2 + 1, end, left, right));
}

Min_Segment_tree::Min_Segment_tree(int N) {
    vec.reserve(N * 4);
}

long long Min_Segment_tree::set(const vector<long long>&a, int node, int start, int end) {
    if(start == end) return vec[node] = a[start];
    else return vec[node] = min(set(a, node * 2 + 1, start, (start + end) / 2), set(a, node * 2 + 2, (start + end) / 2 + 1, end));
}

long long Min_Segment_tree::cal_min(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 1000000000;
    if(left <= start && end <= right) return vec[node];
    return min(cal_min(node * 2 + 1, start, (start + end) / 2, left, right), cal_min(node * 2 + 2, (start + end) / 2 + 1, end, left, right));
}


// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Min_Segment_tree st = Min_Segment_tree(n);
    Max_Segement_tree mst = Max_Segement_tree(n);
    vector<long long> test(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &test[i]);
    }
    st.set(test, 0, 0, n-1);
    mst.set(test, 0, 0, n-1);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld %lld\n", st.cal_min(0, 0, n-1, x - 1, y - 1), mst.cal_min(0, 0, n-1, x-1, y-1));
    }
    return 0;
}