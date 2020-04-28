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
using namespace std;

int N, M;
int marble[30], dp[15001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> marble[i];
    }
    for(int i = 0; i < N; i++) {
        vector<int> vec;
        int k = marble[i];
        vec.push_back(k);
        for(int j = 0; j <= k; j++) {
            if(dp[j]) {
                vec.push_back(k - j);
                vec.push_back(k + j);
            }
        }
        for(int j = k + 1; j < 15001; j++) {
            if(dp[j]) {
                vec.push_back(j - k);
                if(k + j <= 15000) vec.push_back(k + j);
            }
        }
        for(int j = 0; j < vec.size(); j++) {
            dp[vec[j]] = 1;
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        if(tmp > 15000) cout << 'N' << ' ';
        else if(dp[tmp]) cout << 'Y' << ' ';
        else cout << 'N' << ' ';
    }
} 