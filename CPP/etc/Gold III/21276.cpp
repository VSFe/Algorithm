#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, vector<string>> graph;
map<string, int> indegree;
vector<string> ancestor;
vector<pair<string, vector<string>>> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        graph[s] = {};
        indegree[s] = 0;
    } 

    cin >> M;
    for (int i = 0; i < M; i++) {
        string a, b; cin >> a >> b;
        graph[b].push_back(a);
        indegree[a]++;
    }

    queue<string> q;
    for (auto it = indegree.begin(); it != indegree.end(); it++) {
        if (it->second == 0) {
            ancestor.push_back(it->first);
            q.push(it->first);
        }
    }

    cout << ancestor.size() << '\n';
    for (string s : ancestor) cout << s << ' ';
    cout << '\n';

    while (q.size()) {
        auto name = q.front(); q.pop();
        vector<string> tmp;

        for (auto next : graph[name]) {
            if (--indegree[next] == 0) {
                tmp.push_back(next);
                q.push(next);
            }
        }

        result.push_back({name, tmp});
    }

    sort(result.begin(), result.end());

    for (auto re : result) {
        cout << re.first << ' ' << re.second.size() << ' ';
        if (re.second.size()) {
            sort(re.second.begin(), re.second.end());

            for (int i = 1; i < re.second.size(); i++)
                cout << re.second[i - 1] << ' ';
            cout << re.second.back();
        }
        cout << '\n';
    }
}