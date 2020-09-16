#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
deque<char> oper;
deque<ll> dq;
map<char, int> m;

ll solution() {
    if(oper.empty()) return dq.front();
    while(oper.size() > 1) {
        ll firstHead, secondHead, firstTail, secondTail;
        firstHead = dq.front(), secondTail = dq.back();
        dq.pop_back(); dq.pop_front();
        secondHead = dq.front(), firstTail = dq.back();

        ll head[4] = {firstHead + secondHead, firstHead - secondHead, firstHead * secondHead, 0};
        ll tail[4] = {firstTail + secondTail, firstTail - secondTail, firstTail * secondTail, 0};

        if(secondHead != 0) head[3] = firstHead / secondHead;
        if(secondTail != 0) tail[3] = firstTail / secondTail;

        char h = oper.front(), t = oper.back();
        int hIdx = m.find(h)->second, tIdx = m.find(t)->second;

        if(hIdx / 2 > tIdx / 2) {
            ll ans = head[hIdx];
            
            dq.pop_front();
            dq.push_front(ans);
            dq.push_back(secondTail);
            oper.pop_front();
        } else if(hIdx / 2 < tIdx / 2) {
            ll ans = tail[tIdx];
            
            dq.pop_back();
            dq.push_back(ans);
            dq.push_front(firstHead);
            oper.pop_back();
        } else {
            ll hAns = head[hIdx], tAns = tail[tIdx];

            if(hAns >= tAns) {
                dq.pop_front();
                dq.push_front(hAns);
                dq.push_back(secondTail);
                oper.pop_front();
            } else {
                dq.pop_back();
                dq.push_back(tAns);
                dq.push_front(firstHead);
                oper.pop_back();
            }
        }
    }

    int idx = m[oper.front()];
    ll a = dq.front(), b = dq.back();
    ll answer[4] = {a + b, a - b, a * b, 0};
    if(b != 0) answer[3] = a / b;

    return answer[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int prev = 0;
    int idx = 0;
    if(s[idx] == '-') idx++;

    while(idx != s.size()) {
        if(!(s[idx] >= '0' && s[idx] <= '9')) {
            string tmp = s.substr(prev, idx - prev);
            dq.push_back(stoll(tmp));
            oper.push_back(s[idx]);
            prev = idx + 1;              
        }
        idx++;  
    } dq.push_back(stoll(s.substr(prev)));
    
    m.insert({'+', 0});
    m.insert({'-', 1});
    m.insert({'*', 2});
    m.insert({'/', 3});

    if(dq.size() == oper.size()) {
        oper.pop_front();
        dq.front() *= -1;
    }

    cout << solution();
}