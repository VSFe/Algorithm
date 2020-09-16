/*
Problem: 트리의 순회 (2263)
Tier: Gold 3
Detail: n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다.
이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.
Comment:
Inorder - 좌-중-우
Postorder - 좌-우-중
Preorder - 중-좌-우
따라서 재귀로 계속 나누면 됨!
-> 통과는 하지만 1144ms... 순차탐색의 문제로 보임.
--> 숫자의 중복 가능성이 없으니 해싱이 가능함! --> idx_inorder를 만들어 놓으면 44ms!
*/

#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;

int N;
vector<int> inorder, postorder;
stack<pair<int, int>> st;
int idx_inorder[100001];

void find_preorder(int in_s, int in_e, int po_s, int po_e) {
    if(in_e < in_s || po_e < po_s) return;
    if(in_e == in_s && po_s == po_e) {
        printf("%d ", inorder[in_e]);
        return;
    }
    int ob = postorder[po_e], idx, cnt;
    idx = idx_inorder[ob], cnt = in_e - idx;
    find_preorder(idx, idx, po_e, po_e);
    find_preorder(in_s, idx - 1, po_s, po_e - in_e + idx - 1);
    find_preorder(idx + 1, in_e, po_e - in_e + idx, po_e - 1);
}

int main() {
    scanf("%d", &N);
    inorder.reserve(N);
    postorder.reserve(N);
    int tmp;
    for(int i = 0; i < N; i++) { scanf("%d", &tmp); inorder.push_back(tmp); }
    for(int i = 0; i < N; i++) { scanf("%d", &tmp); postorder.push_back(tmp); }
    for(int i = 0; i < N; i++) idx_inorder[inorder[i]] = i;
    find_preorder(0, N-1, 0, N-1);
    return 0;
}