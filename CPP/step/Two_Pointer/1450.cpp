/*
Problem: 냅색문제 (1450)
Tier: Gold 1
Detail: 세준이는 N개의 물건을 가지고 있고, 최대 C만큼의 무게를 넣을 수 있는 가방을 하나 가지고 있다.
N개의 물건을 가방에 넣는 방법의 수를 구하는 프로그램을 작성하시오.
Commant: 단순 백트래킹으로 접근하면  2^30...
그렇지만 반반 나눠서 2^15 2^15로 나누면 할만하다.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<long long> front_data, back_data;
vector<long long> data;
int N, C;

void dfs(int idx, int end, long long weight, vector<long long> &vec) {
    if(idx == end) {
        vec.push_back(weight);
        return;
    }
    dfs(idx + 1, end, weight, vec);
    dfs(idx + 1, end, weight + data[idx], vec);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;
    data.resize(N);
    for(int i = 0; i < N; i++) cin >> data[i];
    dfs(0, N / 2, 0, front_data);
    dfs(N / 2, N, 0, back_data);

    sort(back_data.begin(), back_data.end());

    long long answer = 0;

    for(long long i : front_data) {
        long long ok = C - i;
        answer += upper_bound(back_data.begin(), back_data.end(), ok) - back_data.begin();
    }

    cout << answer;
}