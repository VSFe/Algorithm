/*
Problem: 트리 순회 (1991)
Tier: Silver 1
Detail: 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
Comment: 개념문제...
*/

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> tree;

void inorder(int idx) {
    int left = tree[idx][0], right = tree[idx][1];
    if(left != -18) inorder(left);
    printf("%c", char('@' + idx));
    if(right != -18) inorder(right);
}

void preorder(int idx) {
    int left = tree[idx][0], right = tree[idx][1];
    printf("%c", char('@' + idx));
    if(left != -18) preorder(left);
    if(right != -18) preorder(right);
}

void postorder(int idx) {
    int left = tree[idx][0], right = tree[idx][1];
    if(left != -18) postorder(left);
    if(right != -18) postorder(right);
    printf("%c", char('@' + idx));
}


int main() {
    int t;
    scanf("%d", &t);
    tree.assign(t+1, vector<int>(2));
    for(int i = 1; i <= t; i++) {
        char a, left, right;
        scanf(" %c %c %c", &a, &left, &right);
        int idx = int(a - '@');
        tree[idx][0] = (int(left - '@'));
        tree[idx][1] = (int(right - '@'));
    }
    preorder(1); printf("\n");
    inorder(1); printf("\n");
    postorder(1); printf("\n");
    return 0;
}