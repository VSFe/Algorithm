/*
Problem: 비밀번호 찾기
Tier: Silver 4
Detail: 컴맹인 경민이는 메모장에서 찾기 기능을 활용하지 못하고 직접 눈으로 사이트의 주소와 비밀번호를 찾았다. 메모장에 저장된 사이트의 수가 늘어나면서 경민이는 비밀번호를 찾는 일에 시간을 너무 많이 쓰게 되었다.
이를 딱하게 여긴 문석이는 경민이를 위해 메모장에서 비밀번호를 찾는 프로그램을 만들기로 결심하였다! 문석이를 도와 경민이의 메모장에서 비밀번호를 찾아주는 프로그램을 만들어보자.
Comment: map!
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, string> PW;

int M, TC;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> TC;
    for(int i = 0; i < M; i++) {
        string web, pw;
        cin >> web >> pw;
        PW.insert(make_pair(web, pw));
    }
    for(int i = 0; i < TC; i++) {
        string web;
        cin >> web;
        cout << PW.find(web)->second << '\n';
    }
    return 0;
}