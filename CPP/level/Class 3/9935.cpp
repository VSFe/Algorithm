/*
Problem: 문자열 폭발 (9935)
Tier: Gold 4
Detail: 상근이는 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.
폭발은 다음과 같은 과정으로 진행된다.
    문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
    새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
    폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.
폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
Comment: 폭발 문자열의 글자들을 set에 넣고, 있다면 스위치를 끄고, 없다면 스위치를 키면 됨.
*/

#include <iostream>
#include <string>
using namespace std;

string str;
string bomb;
char result[1000001];
int idx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> bomb;
    for(int i = 0; i < str.size(); i++) {
        int j = bomb.size();
        result[idx] = str[i];
        if(result[idx] == bomb[--j]) {
            bool is_same = true;
            for(int k = 1; k < bomb.size(); k++) {
                if(result[idx - k] != bomb[--j]) {
                    is_same = false;
                    break;
                }
            }
            if(is_same) idx -= bomb.size() ;
        } idx++;
    }
    if(idx == 0) cout << "FRULA";
    else for(int i = 0; i < idx; i++) cout << result[i];
    return 0;
}