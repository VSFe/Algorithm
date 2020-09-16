/*
Problem: IQ Test (1111)
Tier: Gold 2
Detail: IQ Test의 문제 중에는 공통된 패턴을 찾는 문제가 있다. 수열이 주어졌을 때, 다음 수를 찾는 문제이다.
예를 들어, 1, 2, 3, 4, 5가 주어졌다. 다음 수는 무엇인가? 당연히 답은 6이다. 약간 더 어려운 문제를 보면, 3, 6, 12, 24, 48이 주어졌을 때, 다음 수는 무엇인가? 역시 답은 96이다.
이제 제일 어려운 문제를 보자. 1, 4, 13, 40이 주어졌을 때, 다음 수는 무엇일까? 답은 121이다. 그 이유는 항상 다음 수는 앞 수*3+1이기 때문이다.
은진이는 위의 3문제를 모두 풀지 못했으므로, 자동으로 풀어주는 프로그램을 작성하기로 했다. 항상 모든 답은 구하는 규칙은 앞 수*a + b이다. 그리고, a와 b는 정수이다.
수 N개가 주어졌을 때, 규칙에 맞는 다음 수를 구하는 프로그램을 작성하시오.
Comment: 수의 규칙을 어떻게 찾을까?
N(n-1) * a + b = N(n)... 이런 식을 세워서 일반항을 찾아버리면 해결...
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, a, b, v[50];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    if(N == 1 || (N == 2 && v[0] != v[1])) {
        cout << "A";
        return 0;
    }
    if(N == 2) {
        cout << v[0];
        return 0;
    }
    if(v[0] == v[1]) {
        if(v[1] != v[2]) {
            cout << "B";
            return 0;
        }
        a = 1, b = 0;
    } else {
        if((v[2] - v[1]) % (v[1] - v[0])) {
            cout << "B";
            return 0;
        }
        a = (v[2] - v[1]) / (v[1] - v[0]);
        b = v[1] - a * v[0];
    }
    for(int i = 3; i < N; i++) {
        if(v[i] != v[i - 1] * a + b) {
            cout << "B";
            return 0;
        }
    }
    cout << v[N - 1] * a + b;
}