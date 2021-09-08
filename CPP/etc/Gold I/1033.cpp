/**
 * Problem: 칵테일 (1033)
 * Comment: 비율을 트리로 변환해 gcd, lcm 구해서 조물딱 조물딱.
 * /

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, pair<ll, ll>>> graph[10];
ll numerator[11];
ll denominator[11];
int visited[11];
int N;

void dfs(int node) {
    visited[node] = 1;
    for (auto next : graph[node]) {
        if (visited[next.first]) continue;
        numerator[next.first] = next.second.first * numerator[node];
        denominator[next.first] = next.second.second * denominator[node];
        dfs(next.first);
    }
}

ll get_gcd(ll x, ll y) {
    return x % y ? get_gcd(y, x % y) : y;
}

ll get_lcm(ll x, ll y) {
    ll gcd = get_gcd(max(x, y), min(x, y));
    return x / gcd * y;
}

int main() {
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b, p, q; cin >> a >> b >> p >> q;
        int gcd = get_gcd(p, q);
        p /= gcd; q /= gcd;
        graph[a].push_back({b, {q, p}});
        graph[b].push_back({a, {p, q}});
    }

    numerator[0] = 1;
    denominator[0] = 1;

    dfs(0);

    ll pres_lcm = 1;
    for (int i = 1; i < N; i++) {
        ll gcd = get_gcd(max(denominator[i], numerator[i]), min(denominator[i], numerator[i]));
        denominator[i] /= gcd;
        numerator[i] /= gcd;

        pres_lcm = get_lcm(denominator[i], pres_lcm);
    }

    for (int i = 0; i < N; i++) {
        cout << pres_lcm / denominator[i] * numerator[i] << ' ';
    }

    return 0;
}