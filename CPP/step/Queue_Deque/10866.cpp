/*
Problem: 덱 (10866)
Tier: Silver 4
Detail: 정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여덟 가지이다.
Comment: STL..
*/

#include <deque>
#include <iostream>
#include <string>
using namespace std;

int N;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if(s == "push_front") {
            int tmp;
            cin >> tmp;
            d.push_front(tmp);
        }
        if(s == "push_back") {
            int tmp;
            cin >> tmp;
            d.push_back(tmp);
        }
        else if(s == "front") {
            if(d.size() == 0) cout << -1 << "\n";
            else cout << d.front() << "\n";
        }        
        else if(s == "back") {
            if(d.size() == 0) cout << -1 << "\n";
            else cout << d.back() << "\n";
        }
        else if(s == "size") {
            cout << d.size() << "\n";
        }
        else if(s == "empty") {
            if(d.size() == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "pop_front") {
            if(d.size() == 0) cout << -1 << "\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if(s == "pop_back") {
            if(d.size() == 0) cout << -1 << "\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
    }
    return 0;
}