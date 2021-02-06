/*
Problem: 이진 탐색 트리 (8916)
Tier: Platinum 4
Comment: 이진 트리를 만들어서 왼쪽/오른쪽의 자식의 수를 기록하고, 이걸 활용하여 경우의 수를 구하는 문제.
다행히 n <= 20 이라 팩토리얼 미리 만들어놔서 초과하지 않아서 다행.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long fact[21];
int N;
int children[21];
int tree[21][2];
const int MOD = 9999991;

long long getAnswer(int idx, int remain) {
    long long multiple = fact[remain] / fact[children[tree[idx][0]] + 1] / fact[children[tree[idx][1]] + 1];
    long long multiLeft = 1, multiRight = 1;
    if(children[tree[idx][0]]) multiLeft = getAnswer(tree[idx][0], children[tree[idx][0]]);
    if(children[tree[idx][1]]) multiRight = getAnswer(tree[idx][1], children[tree[idx][1]]);
    return (multiple * multiLeft * multiRight) % MOD;
}

void append(int idx, int data) {
    children[idx]++;
    if(data > idx) {
        if(tree[idx][1] == -1) tree[idx][1] = data;
        else append(tree[idx][1], data);
    } else {
        if(tree[idx][0] == -1) tree[idx][0] = data;
        else append(tree[idx][0], data);
    }
}

void solution() {
    memset(tree, -1, sizeof(tree));
    memset(children, 0, sizeof(children));
    cin >> N;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        append(0, tmp);
    }

    cout << getAnswer(tree[0][1], N - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    fact[0] = 1;
    fact[1] = 1;
    for(long long i = 2; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    int TC; cin >> TC;
    for(int i = 0; i < TC; i++) solution();
}