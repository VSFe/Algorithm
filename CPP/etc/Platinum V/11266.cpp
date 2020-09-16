#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int V, E, dfsCnt;
int dfsn[10001];
vector<int> graph[10001];
vector<vector<pair<int, int>>> BCC;
stack<pair<int, int>> st;

int dfs(int idx, int prev) {
    int result = dfsn[idx] = dfsCnt++;
    for(int next : graph[idx]) {
        if(next == prev) continue;
        if(dfsn[idx] > dfsn[next]) st.push({idx, next});
        if(dfsn[next] > 0) result = min(result, dfsn[next]);
        else {
            int tmp = dfs(next, idx);
            result = min(result, tmp);
            if(tmp >= dfsn[idx]) {
                vector<pair<int, int>> vec;
                while(!st.empty() && st.top() != pair<int, int>{idx, next}) {
                    vec.push_back(st.top()); st.pop();
                }
                vec.push_back(st.top()); st.pop();
                BCC.push_back(vec);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}