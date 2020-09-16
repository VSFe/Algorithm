#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> tree[50];
vector<vector<int>> answer(2, vector<int>());
vector<pair<int, int>> pos[50];

int findChild(int left, int right, int depth) {
    if(left > right) return -1;
    while(depth >= 0 && pos[depth].size() == 0) depth--;
    if(depth < 0) return -1;
    
    for(pair<int, int> p: pos[depth]) {
        int idx = p.second;
        if(p.first >= left && p.first <= right) {
            tree[idx].first = findChild(left, p.first - 1, depth - 1);
            tree[idx].second = findChild(p.first + 1, right, depth - 1);
            return idx;
        }
    }
    
    return -1;
}

void preorder(int idx) {
    answer[0].push_back(idx + 1);
    if(tree[idx].first != -1) preorder(tree[idx].first);
    if(tree[idx].second != -1) preorder(tree[idx].second);
}

void postorder(int idx) {
    if(tree[idx].first != -1) postorder(tree[idx].first);
    if(tree[idx].second != -1) postorder(tree[idx].second);
    answer[1].push_back(idx + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int root = -1, roof = -1;
    for(int i = 0; i < nodeinfo.size(); i++) {
        if(nodeinfo[i][1] > roof) {
            roof = nodeinfo[i][1];
            root = i;
        }
        pos[nodeinfo[i][1]].push_back({nodeinfo[i][0], i});
    }
    
    tree[root].first = findChild(0, nodeinfo[root][0] - 1, roof - 1);
    tree[root].second = findChild(nodeinfo[root][0] + 1, 100000, roof - 1);
    
    preorder(root);
    postorder(root);
    
    return answer;
}

// Driver
int main() {
    int N; cin >> N;
    vector<vector<int>> vec(N, vector<int>(2));
    for(int i = 0; i < N; i++) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<vector<int>> answer = solution(vec);
    for(int i = 0; i < N; i++) cout << vec[0][i] << ' ';
    cout << endl;
    for(int i = 0; i < N; i++) cout << vec[1][i] << ' ';
    cout << endl;
}