/*
Problem: 양팔저울 (2629)
Tier: Gold 2
Detail: 양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할 수 있는지를 결정하려고 한다.
무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를 양팔 저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다.
또 다른 구슬이 4g인지를 확인하려면 1g 추 대신 4g 추를 올려놓으면 된다.
구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 수평을 이루게 된다. 따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.
<그림 2>와 같은 방법을 사용하면 구슬이 5g인지도 확인할 수 있다. 구슬이 2g이면 주어진 추를 가지고는 확인할 수 없다.
추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성하시오.
Comment: 차와 합을 따지는 dp. 지연해서 dp값을 입력해야 하기 때문에 일단은 벡터를 사용함.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, tmp, finds;
int IDX = 0, result[2][100001], dt[2][100001];
bool is_alive[500001];
vector<pair<int, int>> vec_p;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    vec_p.reserve(N);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vec_p.push_back({y, x});
    }
    sort(vec_p.begin(), vec_p.end());
    for(int i = 0; i < N; i++) {
        dt[0][i] = vec_p[i].second;
    }
    for(int i = 0; i < N; i++) {
        tmp = lower_bound(result[0], result[0] + IDX, dt[0][i]) - result[0];
        if(tmp == IDX) IDX++;
        result[0][tmp] = dt[0][i];
        result[1][tmp] = i;
        dt[1][i] = result[1][tmp - 1];
    }
    cout << N - IDX << '\n';
    finds = result[1][IDX - 1];
    for(int i = 0; i < IDX; i++) {
        is_alive[dt[0][finds]] = 1;
        finds = dt[1][finds];
    }
    for(int i = 0; i < N; i++) {
        if(!is_alive[vec_p[i].second]) ans.push_back(vec_p[i].second);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}