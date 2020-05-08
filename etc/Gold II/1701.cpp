/*
Problem: Cubeitor (1701))
Tier: Gold 2
Detail: Cubelover는 프로그래밍 언어 Whitespace의 코딩을 도와주는 언어인 Cubelang을 만들었다. Cubelang을 이용해 코딩을 하다보니, 점점 이 언어에 맞는 새로운 에디터가 필요하게 되었다.
오랜 시간 고생한 끝에 새로운 에디터를 만들게 되었고, 그 에디터의 이름은 Cubeditor이다.
텍스트 에디터는 찾기 기능을 지원한다. 대부분의 에디터는 찾으려고 하는 문자열이 단 한 번만 나와도 찾는다. Cubelover는 이 기능은 Cubelang에 부적합하다고 생각했다.
Cubelang에서 필요한 기능은 어떤 문자열 내에서 부분 문자열이 두 번 이상 나오는 문자열을 찾는 기능이다. 이때, 두 부분 문자열은 겹쳐도 된다.
예를 들어, abcdabc에서 abc는 두 번 나오기 때문에 검색이 가능하지만, abcd는 한 번 나오기 때문에 검색이 되지를 않는다.
이렇게 어떤 문자열에서 두 번 이상 나오는 부분 문자열은 매우 많을 수도 있다. 이러한 부분 문자열 중에서 가장 길이가 긴 것을 구하는 프로그램을 작성하시오.
예를 들어, abcabcabc에서 abc는 세 번 나오기 때문에 검색할 수 있다. 또, abcabc도 두 번 나오기 때문에 검색할 수 있다. 하지만, abcabca는 한 번 나오기 때문에 검색할 수 없다.
따라서, 두 번 이상 나오는 부분 문자열 중에서 가장 긴 것은 abcabc이기 때문에, 이 문자열이 답이 된다
Comment: KMP... 이거 다시 공부해야겠네..
*/

#define MAX_N 5001
#include <string>
#include <iostream>
using namespace std;

string T, P;
int b[MAX_N], ans = 0;

void KMPPreprocess() {
    int j = 0;
    for(int i = 1; i < P.length(); i++) {
        while(j > 0 && P[i] != P[j]) j = b[j - 1];
        if(P[i] == P[j]) b[i] = ++j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i < T.length(); i++) {
        fill(b, b + MAX_N, 0);
        P = T.substr(i);
        KMPPreprocess();
        for(int j = 0; j < P.length(); j++) ans = max(ans, b[j]);
    }
    cout << ans;
    return 0;
}