/*
Problem: Haybale Feast (15459)
Tier: Platinum 1
Detail: Farmer John is preparing a delicious meal for his cows! In his barn, he has N haybales. The ith haybale has a Fi certain flavor and a Si certain spiciness.
The meal will consist of a single course, being a contiguous interval containing one or more consecutive haybales (Farmer John cannot change the order of the haybales).
The total flavor of the meal is the sum of the flavors in the interval. The spiciness of the meal is the maximum spiciness of all haybales in the interval.
Farmer John would like to determine the minimum spiciness his single-course meal could achieve, given that it must have a total flavor of at least M.
Comment: 연속적인 애들이 나와야 하니 함부러 합쳤다가는 큰일남...
매운맛을 하나씩 올려가면서 좌우 비교.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> spices[100001];
pair<int, long long>hay_list[100001];
int N, uf[100001];
long long M;

int find(int i) {
    return (uf[i] < 0) ? i : (uf[i] = find(uf[i]));
}

void un(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if(pi == pj) return;
    uf[pi] = pj;
    hay_list[pj].second += hay_list[pi].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) uf[i] = -1;
    for(int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        spices[i] = {y, i};
        hay_list[i] = {y, x};
    }
    sort(spices + 1, spices + N + 1);
    for(int i = 1; i <= N; i++) {
        int p_idx = spices[i].second, p_spicy = spices[i].first;
        if(p_idx != 1 && hay_list[p_idx - 1].first < p_spicy) un(p_idx - 1, p_idx);
        if(p_idx != N && hay_list[p_idx + 1].first < p_spicy) un(p_idx + 1, p_idx);
        if(hay_list[p_idx].second >= M) {
            cout << hay_list[p_idx].first;
            return 0;
        }
    }
    cout << spices[N].first;
    return 0;
}