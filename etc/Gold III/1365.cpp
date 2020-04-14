/*
Problem: 꼬인 전깃줄 (1365)
Tier: Gold 3
Detail: 공화국에 있는 유스타운 시에서는 길을 사이에 두고 전봇대가 아래와 같이 두 줄로 늘어서 있다. 그리고 길 왼편과 길 오른편의 전봇대는 하나의 전선으로 연결되어 있다.
어떤 전봇대도 두 개 이상의 다른 전봇대와 연결되어 있지는 않다. 문제는 이 두 전봇대 사이에 있는 전깃줄이 매우 꼬여 있다는 점이다.
꼬여있는 전깃줄은 화재를 유발할 가능성이 있기 때문에 유스타운 시의 시장 임한수는 전격적으로 이 문제를 해결하기로 했다. 임한수는 꼬여 있는 전깃줄 중 몇 개를 적절히 잘라 내어 이 문제를 해결하기로 했다.
하지만 이미 설치해 놓은 전선이 아깝기 때문에 잘라내는 전선을 최소로 하여 꼬여 있는 전선이 하나도 없게 만들려고 한다. 유스타운 시의 시장 임한수를 도와 잘라내야 할 전선의 최소 개수를 구하는 프로그램을 작성하시오.
Comment: LIS네.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp;
int IDX = 0, result[100001];
int *p, *res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    p = new int[N];
    for(int i = 0; i < N; i++) cin >> *(p + i);
    for(int i = 0; i < N; i++) {
        tmp = lower_bound(result, result + IDX, p[i]) - result;
        if(tmp == IDX) IDX++;
        result[tmp] = p[i];
    }
    cout << N - IDX << '\n';
    return 0;
}