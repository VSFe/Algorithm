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
*/

#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;

int N;
vector<int> inorder, preorder, postorder;
stack<pair<int, int>> st;

int main() {
    scanf("%d", &N);
    inorder.reserve(N);
    postorder.reserve(N);
    int tmp;
    for(int i = 0; i < N; i++) { scanf("%d", &tmp); inorder.push_back(tmp); }
    for(int i = 0; i < N; i++) { scanf("%d", &tmp); postorder.push_back(tmp); }
    while(true) {
        
    }
    return 0;
}