/*
Problem: 소가 길을 건너간 이유 9 (14463)
Tier: Platinum IV
Detail: 존의 농장에는 원형 목초지가 있고, 그 둘레에 길이 둘러져 있다. 존의 소는 매일 아침 이 길을 건너가 풀을 먹고 저녁에 다시 길을 건너가 헛간으로 돌아간다.
이 소들은 자신의 습관대로 매일 똑같은 방법으로 길을 건넌다. 각각의 소는 원형 길의 정해진 한 점을 지나 들어오고, 다른 점을 지나 나간다.
어떤 두 소도 길 위의 같은 점을 지나가지 않는다. 이걸 지켜본 존은 이 점들을 분석해 보기로 했다. 소는 총 N마리고, 1, 2, ..., N이라는 번호가 붙는다.
(원래 A부터 Z까지 이름이 있었는데, 소가 많아지면서 더 이상 그 방법을 사용할 수 없게 되었다.) 존은 2N개의 점을 시계방향으로 보면서 각 점을 어떤 소가 지나가는지 기록했다.
이렇게 만들어 낸 길이 2N의 수열에는 각 번호가 두 번씩 나타날 것이다. 어떤 두 소는 어떤 방법으로 걷든 그 경로가 어딘가에서 만나야 될 수도 있다. 그런 소가 총 몇 쌍인지 구해 보자.
Comment: 모델링을 해보면 A 숫자가 출연하고 그 이후에 A 숫자가 한번 더 나올 때 까지 등장한 숫자의 수가 만나게 되는 쌍의 수이다.
처음에는 해당 풀이를 떠올리고 스택으로 구현을 했는데, 대략적인 시간복잡도가 O(N^2)이라 터짐...
세그먼트 트리로 풀이를 바꿔서 시도해보니 통과.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N, ans = 0, idx[50001];
vector<int> vec;

void update(int node, int start, int end, int index, int val) {
    if(index < start || index > end) return;
    vec[node] += val;
    if(start != end) {
        update(node * 2 + 1, start, (start + end) / 2, index, val);
        update(node * 2 + 2, (start + end) / 2 + 1, end, index, val);
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
    N *= 2;
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vec.assign(tree_size, 0);
    memset(idx, -1, sizeof(idx));
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if(idx[tmp] == -1) {
            idx[tmp] = i;
            update(0, 0, N-1, i, 1);
        }
        else {
            update(0, 0, N-1, idx[tmp], -1);
            ans += get_val(0, 0, N-1, idx[tmp], i);
        }
    }
    cout << ans;
}