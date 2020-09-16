/*
Problem: 트리의 높이와 너비
Tier: Gold 2
Detail: 이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.
    이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
    한 열에는 한 노드만 존재한다.
    임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
    노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다.
트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다. 아래 그림은 어떤 이진트리를 위의 규칙에 따라 그려 본 것이다. 첫 번째 레벨의 너비는 1, 두 번째 레벨의 너비는 13, 3번째, 4번째 레벨의 너비는 각각 18이고, 5번째 레벨의 너비는 13이며, 그리고 6번째 레벨의 너비는 12이다.
우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다. 위의 그림의 예에서 너비가 가장 넓은 레벨은 3번째와 4번째로 그 너비는 18이다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다.
그러므로 이 예에 대한 답은 레벨은 3이고, 너비는 18이다. 임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오
Comment: 중위탐색을 하면 좌 -> 중 -> 우 순서로 방문하게 되는데, 이 방문 순서가 표로 만들었을 때의 인덱스이다!!
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> tree[10001];
vector<int> tree_height[10001];
int N, cnt = 1;
bool is_child[10001];

void inorder(int idx, int height) {
    if(tree[idx].first != -1) inorder(tree[idx].first, height + 1);
    tree_height[height].push_back(cnt++);
    if(tree[idx].second != -1) inorder(tree[idx].second, height + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        tree[x] = {y, z};
        is_child[y] = 1, is_child[z] = 1;
    }
    int root;
    for(int i = 1; i <= N; i++) {
        if(!is_child[i]) {
            root = i;
            break;
        }
    }
    inorder(root, 1);
    int ans = 0, ans_idx = 1;
    for(int i = 1; i < 10001; i++) {
        if(!tree_height[i].size()) break;
        sort(tree_height[i].begin(), tree_height[i].end());
        int tmp = tree_height[i].back() - tree_height[i].front();
        if(tmp > ans) {
            ans = tmp;
            ans_idx = i;
        }
    }
    cout << ans_idx << ' ' << ans + 1;
}