/*
Problem: 트리의 부모 찾기 (11723)
Tier: Silver 2
Detail: 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.
Comment: 트리도 사실상 그래프로 구현해야 하는거 아닌가? (이진트리인지 확실하지 X)
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    vector<int> pa(t+1, 0); vector<vector<int>> tree(t+1);
    queue<int> q;
    for(int i = 0; i < t-1; i++) {
        int s, e; scanf("%d %d", &s, &e);
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    q.push(1);
    while(!q.empty()) {
        int b = q.front(); q.pop();
        for(int i = 0; i < size; i++) {
            int tmp = tree[b][i];
            if(pa[tmp] == 0) {
                pa[tmp] = b;
                q.push(tmp);
            }
        }
    }
    for(int i = 2; i <= t; i++) {
        printf("%d\n", pa[i]);
    }
    return 0;
}
