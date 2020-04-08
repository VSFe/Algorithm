/*
Problem: 책 나눠주기 (9576)
Tier: Platinum 5
Detail: 백준이는 방 청소를 하면서 필요 없는 전공 서적을 사람들에게 나눠주려고 한다. 나눠줄 책을 모아보니 총 N권이었다.
책이 너무 많기 때문에 백준이는 책을 구분하기 위해 각각 1부터 N까지의 정수 번호를 중복되지 않게 매겨 두었다.
조사를 해 보니 책을 원하는 서강대학교 학부생이 총 M명이었다. 백준이는 이 M명에게 신청서에 두 정수 a, b (1 ≤ a ≤ b ≤ N)를 적어 내라고 했다.
그러면 백준이는 책 번호가 a 이상 b 이하인 책 중 남아있는 책 한 권을 골라 그 학생에게 준다. 만약 a번부터 b번까지의 모든 책을 이미 다른 학생에게 주고 없다면 그 학생에게는 책을 주지 않는다.
백준이가 책을 줄 수 있는 최대 학생 수를 구하시오.
Comment: 이분매칭 그 자체
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;

int N, M, TC, B[MAX];
vector<int> vec[MAX];
int visited[MAX];

int dfs(int a) {
    if(visited[a]) return 0;
    visited[a] = 1;
    for(int next : vec[a]) {
        if(!B[next] || dfs(B[next])) {
            B[next] = a;
            return true;
        }
    }
    return false;
}

int bimatch() {
    int ret = 0;
    for(int i = 1; i <= M; i++) {
        fill(visited, visited + MAX, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++) {
        fill(B, B+MAX, 0);
        for(int i = 0; i < MAX; i++) vec[i].clear();
        cin >> N >> M;
        for(int i = 1; i <= M; i++) {
            int x, y; cin >> x >> y;
            for(int j = x; j <= y; j++) vec[i].push_back(j);
        }
        cout << bimatch() << '\n';
    }
    return 0;
}
