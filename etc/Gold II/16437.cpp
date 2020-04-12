/*
Problem: 양 구출 작전
Tier: Gold 2
Detail: N개의 섬으로 이루어진 나라가 있습니다. 섬들은 1번 섬부터 N번 섬까지 있습니다.
1번 섬에는 구명보트만 있고 다른 섬에는 양들 또는 늑대들이 살고 있습니다.
늘어나는 늑대의 개체 수를 감당할 수 없던 양들은 구명보트를 타고 늑대가 없는 나라로 이주하기로 했습니다.
각 섬에서 1번 섬으로 가는 경로는 유일하며 i번 섬에는 pi번 섬으로 가는 다리가 있습니다. 
양들은 1번 섬으로 가는 경로로 이동하며 늑대들은 원래 있는 섬에서 움직이지 않고 섬으로 들어온 양들을 잡아먹습니다. 늑대는 날렵하기 때문에 섬에 들어온 양을 항상 잡을 수 있습니다. 그리고 늑대 한 마리는 최대 한 마리의 양만 잡아먹습니다.
얼마나 많은 양이 1번 섬에 도달할 수 있을까요?
Comment: 트리의 특성을 활용.
어차피 부모는 하나니까 단 한번의 재귀로도 해결할 수 있음...
*/

#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
ll sw[123457];
vector<int> graph[123457];
ll result = 0;

ll dfs(int idx) {
    ll num = sw[idx];
    for(int next : graph[idx]) num += dfs(next);
    if(num < 0) num = 0;
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i <= N; i++) {
        char a; ll b; int c;
        cin >> a >> b >> c;
        if(a == 'W') b *= -1;
        sw[i] = b;
        graph[c].push_back(i);
    }
    cout << dfs(1);
}

