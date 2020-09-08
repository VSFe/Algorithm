#include <iostream>
#include <vector>
using namespace std;

int N, W, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> W >> B;

    vector<vector<int>> lastAppear, firstAppear;
    vector<int> answer;
    int height = 0;

    for(int TC = 0; TC < N; TC++) {
        int h, top = 0; cin >> h;
        vector<int> first(W, -1), last(W, -1);
        string tmp;

        for(int i = 0; i < h; i++) {
            cin >> tmp;
            for(int j = 0; j < W; j++) {
                if(tmp[j] == 'X') {
                    if(first[j] == -1) { 
                        first[j] = h - i - 1;
                        top = max(first[j], top);
                    }
                    last[j] = h - i - 1;
                }
            }
        }
        lastAppear.push_back(last);
        firstAppear.push_back(first);

        if(TC) {
            int add = 0;
            for(int i = 0; i < W; i++) {
                add = max(add, firstAppear[TC - 1][i] - lastAppear[TC][i] + 1);
            }
            if(top + add + 1> B) {
                answer.push_back(height);
                height = top + 1;
            } else {
                for(int i = 0; i < W; i++) {
                    firstAppear[TC][i] += add;
                }
                height = top + add + 1;
            }
        } else height = h;
    }

    for(int i : answer) cout << i << ' ';
    cout << height;
    return 0;
}