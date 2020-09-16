/*
Problem: 문자열 제곱 (4354)
Tier: Gold 3
Detail: 알파벳 소문자로 이루어진 두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻한다. 예를 들어, a="abc", b="def"일 때, a*b="abcdef"이다.
이러한 이어 붙이는 것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수 있다.
    a^0 = "" (빈 문자열)
    a^(n+1) = a*(a^n)
문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을 만족하는 가장 큰 n을 찾는 프로그램을 작성하시오.
Comment: KMP의 Preprocessing 과정을 활용함.
패턴의 길이가 N이라면, 마지막 전처리 벡터의 값은 LEN - N 이어야 하고, 반드시 배수여야 한다는 점을 상기.
*/

#define MAX_N 1000001
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string P;
int n;
vector<int> Preprocessed;

void KMPPreprocess() {
    int i = 0, j = -1;
    Preprocessed.push_back(-1);
    while(i < n) {
        while(j >= 0 && P[i] != P[j]) j = Preprocessed[j];
        i++; j++;
        Preprocessed.push_back(j);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true) {
        getline(cin, P, '\n');
        if(P == ".") break;
        n = P.size(); Preprocessed.reserve(P.size());
        KMPPreprocess();
        int size = *(--Preprocessed.end()), pattern_size = P.size() - size;
        if(size == 0 || size % pattern_size != 0) cout << '1' << '\n';
        else {
            string PA = P.substr(0, pattern_size), PB = P.substr(pattern_size, pattern_size);
            if(PA == PB) cout << (size / pattern_size) + 1 << '\n';
            else cout << '1' << '\n';
        }            
    }
    return 0;
}