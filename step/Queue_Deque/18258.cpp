/*
Problem: 큐 2 (18258)
Tier: Silver 3
Detail: 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
Comment: 걍 STL 쓸래.
※ endl도 시간 잡아먹는 괴물임!!!!!!
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if(s == "push") {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        else if(s == "front") {
            if(q.size() == 0) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }        
        else if(s == "back") {
            if(q.size() == 0) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
        else if(s == "size") {
            cout << q.size() << "\n";
        }
        else if(s == "empty") {
            if(q.size() == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "pop") {
            if(q.size() == 0) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}