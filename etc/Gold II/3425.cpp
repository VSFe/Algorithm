/*
Problem: 고스택
Tier: Gold 2
Detail: 고창영은 스택을 조금 변형해서 고스택을 만들었다. 고스택은 숫자만을 저장할 수 있고, 다음과 같은 10가지 연산을 수행할 수 있다. 편의상 스택의 가장 위에 저장된 수를 첫 번째 수라고 하고, 그 다음은 차례대로 두 번째 수, 세 번째 수라고 한다.
    NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)
    POP: 스택 가장 위의 숫자를 제거한다.
    INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
    DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
    SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
    ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
    SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
    MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
    DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
    MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
이항 연산자의 경우에 첫 번째 숫자가 오른쪽에 있는 수이고, 두 번째 숫자가 왼쪽에 있는 수이다. 또, 연산을 수행하기 전에 두 숫자를 모두 스택에서 제거한 뒤, 결과를 다시 스택에 저장하는 것이다.
숫자가 부족해서 연산을 수행할 수 없을 때, 0으로 나눴을 때 (DIV, MOD), 연산 결과의 절댓값이 109를 넘어갈 때는 모두 프로그램 에러이다.
음수 나눗셈에 대한 모호함을 피하기 위해 다음과 같이 계산한다. 나눗셈의 피연산자에 음수가 있을 때는, 그 수를 절댓값을 씌운 뒤 계산한다. 그리고 나서 몫과 나머지의 부호는 다음과 같이 결정한다. 피연산자중 음수가 한 개일때는 몫의 부호가 음수이다. 이 경우를 제외하면 몫의 부호는 항상 양수이다. 나머지의 부호는 피제수의 부호와 같다. 따라서, 13 div -4 = -3, -13 mod 4 = -1, -13 mod -4 = -1이다.
프로그램 에러가 발생했을 경우에는, 현재 프로그램의 수행을 멈추고, 그 다음 어떤 명령도 수행하지 않는다.
Comment: 빡빡한 구현문제인데 재밌게 푼듯?
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/root/debug/input.txt", "r", stdin);
    #endif
    while(true) {
        string s;
        vector<string> oper;
        vector<int> num;
        vector<int> add;
        while(true) {
            cin >> s;
            if(s == "QUIT") return 0;
            if(s == "END") break;  
            oper.push_back(s);
            if(s == "NUM") {
                int tmp; cin >> tmp;
                add.push_back(tmp);
            }
        }
        int t;
        cin >> t;
        for(int i = 0; i < t; i++) {
            int tmp; cin >> tmp;
            num.push_back(tmp);
        }
        for(int idx = 0; idx < num.size(); idx++) {
            stack<int> st;
            st.push(num[idx]);
            bool is_error = false;
            int add_idx = 0;
            for(int i = 0; i < oper.size(); i++) {
                string ot = oper[i];
                if(ot == "POP") {
                    if(st.empty()) {
                        is_error = true;
                        break;
                    }
                    else st.pop();
                }
                else if(ot == "INV") {
                    if(st.empty()) {
                        is_error = true;
                        break;
                    }
                    st.top() *= -1;
                }
                else if(ot == "DUP") {
                    if(st.empty()) {
                        is_error = true;
                        break;
                    }
                    st.push(st.top());
                }
                else if(ot == "SWP") {
                    if(st.size() <= 1) {
                        is_error = true;
                        break;
                    }
                    int tmp = st.top(); st.pop();
                    swap(st.top(), tmp);
                    st.push(tmp);
                }
                else if(ot == "ADD") {
                    if(st.size() <= 1) {
                        is_error = true;
                        break;
                    }
                    int x = st.top(); st.pop();
                    int ret = x + st.top();
                    if(abs(ret) > 1e9) {
                        is_error = true;
                        break;
                    }
                    st.top() = ret;
                }
                else if(ot == "SUB") {
                    if(st.size() <= 1) {
                        is_error = true;
                        break;
                    }
                    int x = st.top(); st.pop();
                    int ret = st.top() - x;
                    if(abs(ret) > 1e9) {
                        is_error = true;
                        break;
                    }
                    st.top() = ret;
                }
                else if(ot == "MUL") {
                    if(st.size() <= 1) {
                        is_error = true;
                        break;
                    }
                    long long x = st.top(); st.pop();
                    long long ret = x * (long long)(st.top());
                    if(abs(ret) > 1e9) {
                        is_error = true;
                        break;
                    }
                    st.top() = int(ret);
                }
                else if(ot == "DIV") {
                    if(st.size() <= 1 || st.top() == 0) {
                        is_error = true;
                        break;
                    }
                    int x = st.top(); st.pop();
                    bool is_minus = ((x < 0) ^ (st.top() < 0));
                    int ret = is_minus ? abs(st.top()) / abs(x) * -1 : abs(st.top()) / abs(x);
                    st.top() = ret;
                }
                else if(ot == "MOD") {
                    if(st.size() <= 1 || st.top() == 0) {
                        is_error = true;
                        break;
                    }
                    int x = st.top(); st.pop();
                    bool is_minus = ((st.top() < 0));
                    int ret = is_minus ? abs(st.top()) % abs(x) * -1 : abs(st.top()) % abs(x);
                    st.top() = ret;
                }
                else {
                    st.push(add[add_idx++]);
                }
            }
            if(st.size() == 1 && !is_error) cout << st.top() << '\n';
            else cout << "ERROR" << '\n';
        }
        cout << '\n';
    }
}