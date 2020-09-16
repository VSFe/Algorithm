#include <bits/stdc++.h>

using namespace std;

long long memo[31][2];
vector<int> tree[31];

long long dp(vector<int> &sales, int idx, int cs) {
    long long &ret = memo[idx][cs];
    if(ret != -1) return ret;
    ret = 0;

    if(cs) {
        for(int next: tree[idx]) {
            long long t0 = dp(sales, next, 0);
            long long t1 = dp(sales, next, 1);
            ret += min(t0, t1);
        } ret += sales[idx - 1]; 
    } else {
        vector<long long> first, second;

        if(tree[idx].size() != 0) {
            for(int next : tree[idx]) {
                first.push_back(dp(sales, next, 0));
                second.push_back(dp(sales, next, 1));
            }

            long long answer = 0, minimumMinus = 1e9;
            bool isOk = false;
            for(int i = 0; i < first.size(); i++) {
                if(first[i] >= second[i]) {
                    isOk = true;
                    answer += second[i];
                } else {
                    answer += first[i];
                    minimumMinus = min(minimumMinus, second[i] - first[i]);
                }
            }

            if(isOk) ret = answer;
            else ret = answer + minimumMinus;            
        }
    }
    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for(vector<int> vec: links) {
        tree[vec[0]].push_back(vec[1]);
    }

    memset(memo, -1, sizeof(memo));

    int answer = min(dp(sales, 1, 0), dp(sales, 1, 1));
    return answer;
}

// Driver
int main() {
    int size_len, links_len;
    cin >> size_len >> links_len;
    vector<int> sales(size_len);
    vector<vector<int>> links(links_len, vector<int>(2));

    for(int i = 0; i < size_len; i++) cin >> sales[i];
    for(int i = 0; i < links_len; i++) cin >> links[i][0] >> links[i][1];
    cout << solution(sales, links);
}