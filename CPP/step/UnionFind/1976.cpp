/*
Problem: 여행 가자(1976)
Tier: Gold 4
Detail: 동혁이는 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다.
동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 예를 들어 도시가 5개 있고,
A-B, B-C, A-D, B-D, E-A의 길이 있고, 동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.
도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때(중복 가능) 가능한지 여부를 판별하는 프로그램을 작성하시오.
Comment: UnionFind를 경량화 해보자.
*/

#include <stdio.h>

int uf[101];
int travel[1000];

int find(int i) {
    return (uf[i] == i) ? i : (uf[i] = find(uf[i])); 
}

void un(int i, int j) {
    int pu = find(i);
    int pj = find(j);
    if(pu != pj) uf[pj] = pu;
}

bool is_same(int i, int j) {
    if(find(i) == find(j)) return true;
    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) uf[i] = i;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int s; scanf("%d", &s);
            if(s == 1) un(i, j);
        }
    }
    for(int i = 0; i < M; i++) scanf("%d", &travel[i]);
    for(int i = 0; i < M - 1; i++) {
        if(is_same(travel[i], travel[i+1])) continue;
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}

