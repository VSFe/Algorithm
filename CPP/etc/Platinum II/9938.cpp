/*
Problem: 방 청소 (9938)
Tier: Platinum 2
Detail: 은기는 술병 N개(1부터 N까지 번호가 매겨져 있다)와 서랍 L개(1부터 L까지 번호가 매겨져 있다)를 가지고 있다. 술병은 은기의 방 바닥에 흩어져 있고, 어린이날을 맞이해 방 청소를 하려고 한다.  서랍에는 술병이 하나 들어갈 수 있다. 나중에 원하는 술을 빠르게 찾을 수 있게 하기 위해 은기는 각각의 술병이 들어갈 수 있는 서랍의 번호 Ai와 Bi를 공책에 적어 놓았다.
은기는 술병을 1번부터 N번까지 순서대로 정리할 것이고, 각각의 술병에 대해서 다음과 같은 과정을 거친다.
    서랍 Ai가 비어있다면, i번 술을 그 서랍에 보관한다.
    서랍 Bi가 비어있다면, i번 술을 그 서랍에 보관한다.
    Ai에 들어있는 술을 다른 서랍으로 이동시킨다.(다른 서랍은 Ai에 들어있는 술이 들어갈 수 있는 서랍 중 하나이다) 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Ai에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
    Bi에 들어있는 술을 다른 서랍으로 이동시킨다. 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Bi에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
    위의 과정이 모두 불가능한 경우에는 i번 술을 그 자리에서 마셔버린다. (은기는 전혀 취하지 않는다)
각각의 술에 대해서, 서랍에 보관할 수 있는지, 그 자리에서 마셔버리는지를 구하는 프로그램을 작성하시오.
Comment: Union-Find 활용.
1. Ai가 차 있다면 Bi를 활용함 (Union-Find 구조상 둘 중 하나에만 넣을 수 있으면 됨.)
2. Ai에 들어있는 술을 다른 서랍으로 이동시킴 (다른 서랍은 Ai에 들어있는 술이 들어갈 수 있는 다른 자리)
-> 다른 (Ai <-> Bi) 조합과의 Union-Find
3. 정 안될 때면 그 술을 다른 서랍으로 보내버림
-> 다른 서랍에 들어있던 술의 체인.
루트가 비어 있어야 문제에서 요구하는데로 풀 수 있음...
아이디어 떠올리기 정말 어려운 문제.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, uf[300001], alcohol[300001];

int find(int i) {
    return (uf[i] < 0) ? i : (uf[i] = find(uf[i]));
}

void un(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if(pi == pj) return;
    if(alcohol[pi]) uf[pi] = pj;
    else uf[pj] = pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) uf[i] = -1;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x = find(x), y = find(y);
        if(alcohol[x] && alcohol[y]) cout << "SMECE" << '\n';
        else {
            cout << "LADICA" << '\n';
            if(alcohol[x]) alcohol[y] = 1;
            else alcohol[x] = 1;
            un(x, y);
        }
    }
}