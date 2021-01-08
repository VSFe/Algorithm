/*
Problem: 부분합 (1806)
Tier: Gold 4
Detail: 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.
Commant: 같이 이동하는 경우는 크기가 동일함. 그래서 그렇게 하면 틀림!!
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;
int answer = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vec.push_back(0);
    
    for(int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        vec.push_back(vec[i - 1] + tmp);
    }

    int left = 0, right = 0;
    while(left != N + 1 && right != N + 1) {
        if(vec[right] - vec[left] >= M) {
            answer = min(answer, right - left);
            left++;
        } else right++;
    }
    if(answer == 1e9) cout << 0;
    else cout << answer;
}