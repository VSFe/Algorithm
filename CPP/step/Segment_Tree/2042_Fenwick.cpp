/*
Problem: 구간 합 구하기
Tier: Gold 1
Detail: 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다.
Comment: 펜윅트리로 풀어봤다.
재밌네...
*/

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> tree;
vector<ll> data;
int N, M, K;

ll find_tree(int idx) {
    ll result = 0;
    while(idx) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void update(int idx, ll diff) {
    while(idx <= N) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

void doQuery() {
    int size = M + K;
    for(int i = 0; i < size; i++) {
        int x, y; ll z; cin >> x >> y >> z;
        if(x == 1) {
            ll diff = z - data[y];
            update(y, diff);
            data[y] = z;
        }
        else {
            cout << find_tree(z) - find_tree(y - 1) << '\n';
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    tree.resize(N + 1);
    data.resize(N + 1);

    for(int i = 0; i < N; i++) {
        cin >> data[i + 1];
        update(i + 1, data[i + 1]);
    }

    doQuery();
}