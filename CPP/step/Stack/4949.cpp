/*
Problem: 균형잡힌 세상 (4949)
Tier: Silver 4
Detail: 문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.
Comment:에반데
*/

#include <string>
#include <iostream>
#include <stack>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        stack<char> t;
        bool is_true = true;
        getline(cin, s);
        if(s == ".") break;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[') t.push(s[i]);
            else if(s[i] == ')') {
                if(t.size() != 0 && t.top() == '(') t.pop();
                else {
                    is_true = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(t.size() != 0 && t.top() == '[') t.pop();
                else {
                    is_true = false;
                    break;
                }
            }
        }
        if(t.size() == 0 && is_true) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}