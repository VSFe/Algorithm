/*
Problem: 광고 (1305)
Tier: Gold 2
Detail: 세준이는 길 한가운데에서 전광판을 쳐다보고 있었다. 전광판에는 광고가 알파벳으로 흘러나오고 있었다. 한참을 전광판을 쳐다본 세준이는 이 광고가 의미하는 것이 무엇인지 궁금해지기 시작했다.
전광판에는 같은 내용의 문구가 무한히 반복되어 나온다. 또, 전광판의 크기는 전광판에서 한번에 보이는 최대 문자수를 나타낸다. 만약 전광판의 크기가 L이라면, 한번에 L개의 문자를 표시할 수 있는 것이다.
광고업자는 최대한의 광고효과를 내기 위해서 길이가 N인 광고를 무한히 붙여서 광고한다.
예를 들어, 광고 업자 백은진이 광고하고 싶은 내용이 aaba 이고, 전광판의 크기가 6이라면 맨 처음에 보이는 내용은 aabaaa 이다. 시간이 1초가 지날 때마다, 문자는 한 칸씩 옆으로 이동한다.
따라서 처음에 aabaaa가 보였으면 그 다음에는 abaaab가 보인다. 그 다음에는 baaaba가 보인다.
세준이가 어느 순간 전광판을 쳐다봤을 때, 그 때 쓰여 있는 문자가 입력으로 주어졌을 때, 가능한 광고의 길이중 가장 짧은 것을 출력하는 프로그램을 작성하시오.
Comment: 전광판을 보면...
(패턴 1) - (패턴 2) - (패턴 1)
패턴 1은 겹치는 부분, 패턴 2는 겹치지 않는 부분
그러면 마지막 패턴 부분만 빼면 되네!
*/

#define MAX_N 1000001
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string P;
int n, L;
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
    cin >> L >> P;
    n = L; Preprocessed.reserve(L);
    KMPPreprocess();
    int size = *(Preprocessed.end() - 1), rest_size = L - size;
    cout << rest_size;
    return 0;
}