/*
Problem: 히스토그램에서 가장 큰 직사각형(6549)
Tier: Gold 1
Detail: 히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다.
예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.
히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.
Comment: Segment Tree 활용.
최솟값의 인덱스를 담은 세그먼트 트리를 만들면 될 듯.
*/

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int N = 1;
vector<long long> VEC;

class Segment_tree {
    public:
        Segment_tree() {};
        Segment_tree(int N);
        int set(int node, int start, int end);
        int cal_submin(int node, int start, int end, int left, int right);
        void print(int index) {
            printf("%d\n", vec[index]);
        }
    private:
        int size;
        vector<int> vec;
};

Segment_tree::Segment_tree(int N) {
    vec.reserve(N * 4);
}

int Segment_tree::set(int node, int start, int end) {
    if(start == end) vec[node] = start;
    else {
        int leftv = set(node * 2 + 1, start, (start + end) / 2);
        int rightv = set(node * 2 + 2, (start + end) / 2 + 1, end);
        return vec[node] = VEC[leftv] > VEC[rightv] ? rightv : leftv;
    }
}

int Segment_tree::cal_submin(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return -1;
    if(left <= start && end <= right) return vec[node];
    int leftv = cal_submin(node * 2 + 1, start, (start + end) / 2, left, right);
    int rightv = cal_submin(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
    if(leftv == -1) return rightv;
    if(rightv == -1) return leftv;
    return VEC[leftv] > VEC[rightv] ? rightv : leftv;
}

long long largest(Segment_tree &st, int start, int end) {
    int m = st.cal_submin(0, 0, N-1, start, end);
    long long ret = (end - start + 1) * VEC[m];
    if(start <= m - 1) ret = max(ret, largest(st, start, m - 1));
    if(end >= m + 1) ret = max(ret, largest(st, m + 1, end));
    return ret;
}

// Driver
int main() {
    while(true) {
        scanf("%d", &N);
        if(N == 0) return 0;
        Segment_tree st = Segment_tree(N);
        VEC.resize(N);
        for(int i = 0; i < N; i++) {
            scanf("%lld", &VEC[i]);
        }
        st.set(0, 0, N-1);
        printf("%lld\n", largest(st, 0, N-1));
    }
    return 0;
}