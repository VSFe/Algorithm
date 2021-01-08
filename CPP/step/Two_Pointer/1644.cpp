/*
Problem: 소수의 연속합 (1644)
Tier: Gold 3
Detail: 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다.
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다.
또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.
자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.
Commant: 소수 구하고 부분합에 대한 투포인터로 풀면 쉽게 풀림.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prime;
int N;

void makePrime() {
    vector<bool> vec(N + 1, 1);

    prime.push_back(0);
    prime.push_back(2);
    int size = sqrt(N);
    for(int i = 3; i <= N; i += 2) {
        if(vec[i]) {
            prime.push_back(i);
            if(i <= size)
                for(int j = i * i; j <= N; j += i) vec[j] = false;
        }
    }
}

int main() {
    cin >> N;
    makePrime();

    for(int i = 1; i < prime.size(); i++) prime[i] += prime[i - 1];

    int left = 0, right = 0;
    int answer = 0;

    while(left != prime.size() && right != prime.size()) {
        if(prime[right] - prime[left] == N) {
            answer++;
            left++, right++;
        }
        else if(prime[right] - prime[left] < N) right++;
        else left++;
    }

    cout << answer;
    return 0;
}
