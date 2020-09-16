#include <iostream>
#include <string>
using namespace std;

int uf[51];

int uf_find(int x) {
    return uf[x] == -1 ? x : uf[x] = uf_find(uf[x]);
}

void uf_union(int x, int y) {
    uf[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, answer = 0;
    string strs[51];

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> strs[i];
    }
    fill(uf, uf+N, -1);

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            string x = strs[i], y = strs[j];
            int len = min(x.size(), y.size());

            if(x.substr(0, len) == y.substr(0, len)) {
                if(x.size() > y.size()) uf_union(i, j);
                else uf_union(j, i);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(uf_find(i) == i) answer++;
    }

    cout << answer;
}