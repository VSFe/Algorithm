/*
Problem: 쇠막대기 (10799)
Tier: Silver 3
Detail: 여러 개의 쇠막대기를 레이저로 절단하려고 한다. 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자른다. 쇠막대기와 레이저의 배치는 다음 조건을 만족한다.
    쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다. - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
    각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
    레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다. 
이러한 레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있다.
    레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
    쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다. 
쇠막대기는 레이저에 의해 몇 개의 조각으로 잘려지는데, 위 예에서 가장 위에 있는 두 개의 쇠막대기는 각각 3개와 2개의 조각으로 잘려지고,
이와 같은 방식으로 주어진 쇠막대기들은 총 17개의 조각으로 잘려진다. 
쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 주어졌을 때, 잘려진 쇠막대기 조각의 총 개수를 구하는 프로그램을 작성하시오.
Comment: 스택인데?
()(((()())(())()))(()) → 17
단순 괄호 : 0, 괄호 속 괄호: 2...
괄호 속 괄호를 찾아라! 같은건데...
*/

#include <stack>
#include <iostream>
#include <string>
using namespace std;

stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    int size = s.size();
    bool is_continue = false;
    int answer = 0;
    for(int i = 0 ; i < size; i++) {
        if(s[i] == '(') {
            st.push(1);
            is_continue = false;
        } else {
            st.pop();
            if(is_continue) answer++;
            else {
                answer += st.size();
                is_continue = true;
            }
        }
    }
    cout << answer;
    return 0;
}