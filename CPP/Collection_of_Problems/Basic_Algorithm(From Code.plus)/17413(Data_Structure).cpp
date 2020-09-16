/*
Problem: 단어 뒤집기 2 (17413)
Tier: Silver 3
Detail: 문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.
태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다.
단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다. 태그는 단어가 아니며,
태그와 단어 사이에는 공백이 없다.
Comment: 순차 탐색 + 스택?
*/

#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;

stack<char> st;
char ch[100001];

int main() {
    scanf("%[^\n]s", ch);
    int size = strlen(ch);
    bool is_sign = false;
    for(int i = 0; i < size; i++) {
        if(ch[i] == '<') {
            is_sign = true;
            if(st.size() != 0) {
                int st_size = st.size();
                for(int i = 0; i < st_size; i++) {
                    char tmp = st.top();
                    st.pop();
                    printf("%c", tmp);
                }
            }
            printf("%c", ch[i]);
        }
        else if(ch[i] == '>') {
            is_sign = false;
            printf("%c", ch[i]);
        }
        else if(is_sign) printf("%c", ch[i]);
        else if(ch[i] == ' ') {
            int st_size = st.size();
            for(int i = 0; i < st_size; i++) {
                char tmp = st.top();
                st.pop();
                printf("%c", tmp);
            }
            printf(" ");
        } 
        else st.push(ch[i]);
    }
    int st_size = st.size();
    for(int i = 0; i < st_size; i++) {
        char tmp = st.top();
        st.pop();
        printf("%c", tmp);
    }
    return 0;
}