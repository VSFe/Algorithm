/*
Problem: 공항(10775)
Tier: Gold 2
Detail: 공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.
공항에는 P개의 비행기가 순서대로 도착할 예정이며, 당신은 i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다. 비행기가 도킹된 게이트에는 다른 비행기가 도착할 수 없다.
이렇게 공항을 운영할 경우 간혹 비행기가 어떤 곳에도 도킹하지 못하는 사고가 발생한다. 이러한 사고가 일어나면 공항의 평판이 급속히 나빠져, 이후 어떤 비행기도 도착하지 않으려 할 것이다.
Comment: 딴건 몰라도 일단 자기 자리에 도킹하는게 젤 낫고, 그렇지 않으면 뒤로 하나씩 뺀다고 생각하면 됨.
-> 뒷자리에 Union!!!
*/

#include <stdio.h>

int G, P, uf[100001];
int result = 0;

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
    scanf("%d %d", &G, &P);
    for(int i = 0; i <= G; i++) uf[i] = i; 
    for(int i = 0; i < P; i++) {
        int t;
        scanf("%d", &t);
        int pr = find(t);
        if(pr == 0) break;
        result++;
        un(pr-1, pr);
    }
    printf("%d", result);
    return 0;
}