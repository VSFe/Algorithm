/*
Problem: 집합 (11723)
Tier: Silver 5
Detail: 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
    add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
    remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
    check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
    toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
    all: S를 {1, 2, ..., 20} 으로 바꾼다.
    empty: S를 공집합으로 바꾼다. 
Comment: 비트마스크로 하면 쉽다...
사실 시간적 여유 때문에 일반적인 배열로 해도 되겠지만.
*/

#include <iostream>
#include <string>
using namespace std;

int st = 1 << 21;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        if(s == "all") st = (1 << 22) - 1;
        else if(s == "empty") st = 1 << 21;
        else {
            int num;
            cin >> num;
            if(s == "add") {
                st |= (1 << num);
            } else if(s == "check") {
                if(st & (1 << num)) cout << 1 << "\n";
                else cout << 0 << "\n";
            } else if(s == "remove") {
                st &= ~(1 << num);
            } else if(s == "toggle") {
                st ^= (1 << num);
            }
        }
    }
    return 0;
}