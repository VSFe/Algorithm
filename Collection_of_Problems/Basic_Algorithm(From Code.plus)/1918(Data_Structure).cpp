/*
Problem: 후위 표기식(1918)
Tier: Gold 5
Detail: 중위 표기식이 주어졌을 때 후위 표기식으로 고치는 프로그램을 작성하시오
Comment: 자료구조에서 배운대로만 하자.
*/

#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;

stack<char> st;
char yee[101];

int main() {
    scanf("%s", yee);
    int size = strlen(yee);
    for(int i = 0; i < size; i++) {
        char tmp = yee[i];
        switch(tmp) {
            case '(':
                st.push('(');
                continue;
            case ')':
                while(st.size() != 0 && st.top() != '(') {
                    printf("%c", st.top());
                    st.pop();
                }
                st.pop();
                continue;
            case '+':
            case '-':
                while(st.size() != 0 && st.top() != '(') {
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(tmp);
                continue;
            case '*':
            case '/':
                while(st.size() != 0 && (st.top() == '*' || st.top() == '/')) {
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(tmp);
                continue;
            default:
                printf("%c", tmp);
                continue;
        }
    }
    int st_size = st.size();
    for(int i = 0; i < st_size; i++) {
        char tmp = st.top();
        st.pop();
        printf("%c", tmp);
    }
    return 0;
}
