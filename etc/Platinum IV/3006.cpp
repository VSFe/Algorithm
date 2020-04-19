/*
Problem: 터보소트 (3006)
Tier: Platinum IV
Detail: 명우가 소트 알고리즘을 하나 발명했다. 이 알고리즘의 이름은 터보소트이다. 
터보소트는 1부터 N까지 총 N개의 수가 섞여있을 때만 사용할 수 있으며, 다음과 같이 N단계로 이루어져 있다.
    첫 번째 단계에서 숫자 1의 위치를 찾는다. 그 다음 바로 앞의 숫자와 위치를 바꾸어가면서, 1이 제일 앞에 오게 바꾼다.
    두 번째 단계에서는 숫자 N의 위치를 찾는다. 그 다음 바로 뒤의 숫자와 위치를 바꾸어가면서, N이 제일 마지막에 오게 바꾼다.
    세 번째 단계는 숫자 2의 위치를 찾은 후에, 바로 앞의 숫자와 위치를 바꾸어가면서, 두 번째 위치에 오게 바꾼다.
    네 번째 단계는 숫자 N-1의 위치를 찾은 다음에, 바로 뒤의 숫자와 위치를 바꾸면서, 뒤에서 2번째 위치에 오게 바꾼다.
    다섯 번째 단계도 위와 같은 식으로 하면 되고 이를 N번 반복하는 것이다.
정리하면, 홀수번째 단계이면, 아직까지 고르지 않은 숫자 중 제일 작은 수를 고른 다음에, 그것을 인접한 숫자와 위치를 바꾸면서 올바른 위치로 이동시키고,
짝수번째 단계일때는, 제일 큰 수를 고른 다음에 위치를 이동시키는 것이다. 명우는 이때, 각 단계에서 숫자의 위치를 몇 번 바꾸는지 구하려고 한다.
1부터 N까지 총 N개의 수로 이루어진 배열이 주어졌을 때, 터보 소트의 각 단계에서, 숫자의 위치를 몇 번씩 바꾸는지 출력하는 프로그램을 작성하시오.
Comment: 맨 끝으로 보낼 때 마주하는 숫자의 갯수를 구하는 문제 -> 구간합이라고 해석할 수 있음.
마지막의 경우는 사실상 무조건 0 -> 홀수 일때 따로 한번 더 함수를 돌리지 말고 그냥 0을 출력시켜버리면 됨.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, index[100001];
vector<int> vec;

int preprocess(int node, int start, int end) {
    if(start == end) return vec[node] = 1;
    return vec[node] = preprocess(node * 2 + 1, start, (start + end) / 2) + preprocess(node * 2 + 2, (start + end) / 2 + 1, end); 
}

void update(int node, int start, int end, int index) {
    if(index < start || index > end) return;
    vec[node]--;
    if(start != end) {
        update(node * 2 + 1, start, (start + end) / 2, index);
        update(node * 2 + 2, (start + end) / 2 + 1, end, index);
    }
}

int get_val(int node, int start, int end, int left, int right) {
    if(right < start || left > end) return 0;
    if(right >= end && left <= start) return vec[node];
    return get_val(node * 2 + 1, start, (start + end)/2, left, right) + get_val(node * 2 + 2, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vec.reserve(tree_size);
    preprocess(0, 0, N-1);
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        index[tmp] = i;
    }
    int size = N/2;
    for(int i = 1; i <= size; i++) {
        int t1 = index[i], t2 = index[N - i + 1];
        if(!t1) cout << 0 << '\n';
        else cout << get_val(0, 0, N-1, 0, t1 - 1) << '\n';
        update(0, 0, N-1, t1);
        cout << get_val(0, 0, N-1, t2 + 1, N- 1) << '\n';
        update(0, 0, N-1, t2);
    }
    if(N % 2) cout << 0;
}