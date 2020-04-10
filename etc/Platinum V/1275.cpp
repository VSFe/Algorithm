/*
Problem: 커피숍 2
Tier: Platinum 5
Detail: 어느 날 커피숍의 손님 A씨가 동호에게 게임을 하자고 했다. 그 게임은 다음과 같은 규칙을 갖는다.
N개의 정수가 있으면, 동호는 다음과 같이 말한다. “3~7번째 수의 합은 무엇이죠?” 그러면 상대방은
“그 답은 000입니다. 그리고 8번째 수를 2로 고치도록 하죠” 그러면 동호는 “네 알겠습니다.”라고 한 뒤에 다시 상대방이 동호가 했던 것처럼 “8~9번째 수의 합은 무엇이죠?”라고 묻게된다.
이 것을 번갈아 가면서 반복하는 게임이다. 당신은 이 게임의 심판 역을 맡았다. 요컨대, 질문에 대한 답들을 미리 알아야 한다는 것이다.
당신의 머리가 출중하다면 10만개 가량 되는 정수와 10만턴 정도 되는 게임을 기억할 수 있을 것이다.
몇판 이 게임을 즐기던 동호는 많은 사람들이 이 게임을 하기를 바라게 되었고, 당신에게 심판 프로그램을 구현해달라고 요청했다.
Comment: 나오는 수가 32비트라고 합이 32비트가 아닐수는 없으니까...
*/

#define ll long long
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, Q;
vector<ll> sgtree, arr;

ll make_tree(int node, int start, int end) {
    if(start == end) return sgtree[node] = arr[start];
    return sgtree[node] = make_tree(node * 2, start, (start + end)/2) + make_tree(node*2 + 1, (start + end)/2 + 1, end);
}

void update(int node, int start, int end, int index, ll diff) {
    if(index > end || index < start) return;
    sgtree[node] += diff;
    if(start != end) {
        update(node * 2, start, (start + end)/ 2, index, diff);
        update(node * 2 + 1, (start + end)/ 2 + 1, end, index, diff);        
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return sgtree[node];
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    int tree_height = (int)(ceil(log2(N)));
    sgtree.assign((1 << (tree_height + 1)), 0);
    arr.assign(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];
    make_tree(1, 0, N-1);
    for(int i = 0; i < Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(a > b) cout << sum(1, 0, N-1, b-1, a-1) << '\n';
        else cout << sum(1, 0, N-1, a-1, b-1) << '\n';
        ll diff = d - arr[c-1];
        arr[c-1] = d; 
        update(1, 0, N-1, c-1, diff);
    }
}