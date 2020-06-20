/*
Problem: 오아시스 재결합 (3015)
Tier: Gold 1
Detail: 오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다. 이 역사적인 순간을 맞이하기 위해 줄에서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.
두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다. 줄에 서있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.
Comment: 스택 활용 문제.
'쌍'으로 접근해야 하기에, 한번에 더해지는 수가 많지 않다. 그저 같은 숫자 처리만 잘 하면 되는 문제.
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, tmp;
long long ans = 0;
stack<pair<int, int>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        int check = 1;
        while(!st.empty() && st.top().first <= tmp) {
            ans += st.top().second;
            if(st.top().first == tmp) check += st.top().second;
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push({tmp, check});
    }
    cout << ans;
}