/*
Problem: 수학은 너무 쉬워 (2904)
Tier: Gold 3
Detail: 상근이의 할머니는 매우 유명한 수학자이다. 할머니는 매일 수학 문제로 상근이를 힘들게 한다. 할머니는 종이 N장에 숫자를 하나씩 쓴 다음 상근이에게 준다. 그 다음 상근이는 다음과 같이 문제를 풀어야 한다.
두 수 A와 B를 고르고, A를 나눌 수 있는 소수 X를 고른다. 그 다음, A를 지우고 A/X를 쓰고, B를 지우고 B×X를 쓴다.
상근이는 위의 행동을 무한히 반복할 수 있다. 할머니는 상근이가 만든 수를 보고 점수를 계산한다. 점수가 높을수록 할머니는 상근이에게 사탕을 많이 준다. 점수는 종이에 적혀있는 모든 수의 최대공약수이다.
상근이가 얻을 수 있는 가장 높은 점수를 구하는 프로그램을 작성하시오. 또, 그 점수를 얻으려면 최소 몇 번 해야 하는지도 구한다.
Comment: 각각의 소수가 소인수로 몇개나 존재? / 전체
수가 1000000 이하이니 소인수는 1000이하면 됨.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1001;

vector<int> prime;
int N, ans = 1, cnt = 0, pFactor[1001], pList[100][1001], num[100];

void findPrime() {
    bool is_prime[MAX];
    fill(is_prime + 2, is_prime + MAX, true);
    for(int i = 4; i < MAX; i+=2) is_prime[i] = false;
    for(int i = 2; i < MAX; i++) {
        if(!is_prime[i]) continue;
        prime.push_back(i);
        for(int j = i * i; j < MAX; j += i * 2) {
            is_prime[j] = false;
        }
    }
}

int decomposition(int idx, int num) {
    for(int i = 0; num > 1; i++) {
        if(i == prime.size()) return num;
        while(num % prime[i] == 0) {
            pList[idx][prime[i]]++;
            pFactor[prime[i]]++;
            num /= prime[i];
        }
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    findPrime();
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        num[i] = decomposition(i, tmp);
    }
    for(int i = 2; i < MAX; i++) {
        if(pFactor[i] >= N) {
            pFactor[i] = pFactor[i]/N;
            ans *= pow(i, pFactor[i]);
        }
        else pFactor[i] = 0;
    }
    for(int i = 2; i < MAX; i++) {
        if(!pFactor[i]) continue;
        for(int j = 0; j < N; j++) {
            if(pList[j][i] < pFactor[i]) cnt += pFactor[i] - pList[j][i];
        }
    }
    bool is_same = true;
    for (int i = 1; i < N; i++) {
        if(num[i] != num[i - 1]) {
            is_same = false; break;
        }
    }
    if(is_same) ans *= num[0];
    cout << ans << ' ' << cnt;
}

