/*
Problem: 휴대폰 자판
Tier: Platinum 3
Detail: 휴대폰에서 길이가 P인 영단어를 입력하려면 버튼을 P번 눌러야 한다. 그러나 시스템프로그래밍 연구실에 근무하는 승혁연구원은 사전을 사용해 이 입력을 더 빨리 할 수 있는 자판 모듈을 개발하였다.
이 모듈은 사전 내에서 가능한 다음 글자가 하나뿐이라면 그 글자를 버튼 입력 없이 자동으로 입력해 준다! 자세한 작동 과정을 설명하자면 다음과 같다.
    모듈이 단어의 첫 번째 글자를 추론하지는 않는다. 즉, 사전의 모든 단어가 같은 알파벳으로 시작하더라도 반드시 첫 글자는 사용자가 버튼을 눌러 입력해야 한다.
    길이가 1 이상인 문자열 c1c2...cn이 지금까지 입력되었을 때, 사전 안의 모든 c1c2...cn으로 시작하는 단어가 c1c2...cnc로도 시작하는 글자 c가 존재한다면 모듈은 사용자의 버튼 입력 없이도 자동으로 c를 입력해 준다. 그렇지 않다면 사용자의 입력을 기다린다.
예를 들면, 사전에 "hello", "hell", "heaven", "goodbye" 4개의 단어가 있고 사용자가 "h"를 입력하면 모듈은 자동으로 "e"를 입력해 준다.
사전상의 "h"로 시작하는 단어들은 모두 그 뒤에 "e"가 오기 때문이다. 그러나 단어들 중 "hel"로 시작하는 것도, "hea"로 시작하는 것도 있기 때문에 여기서 모듈은 사용자의 입력을 기다린다.
이어서 사용자가 "l"을 입력하면 모듈은 "l"을 자동으로 입력해 준다. 그러나 여기서 끝나는 단어인 "hell"과 그렇지 않은 단어인 "hello"가 공존하므로 모듈은 다시 입력을 기다린다.
사용자가 "hell"을 입력하기 원한다면 여기서 입력을 멈출 것이고, "hello"를 입력하기 원한다면 직접 "o" 버튼을 눌러서 입력해 줘야 한다.
따라서 "hello"를 입력하려면 사용자는 총 3번 버튼을 눌러야 하고, "hell", "heaven"은 2번이다. "heaven"의 경우 "he"에서 "a"를 입력하면 바로 뒷부분이 모두 자동으로 입력되기 때문이다.
비슷하게, "goodbye"는 단 한 번만 버튼을 눌러도 입력이 완료될 것이다. "g"를 입력하는 순간 뒤에 오는 글자가 항상 유일하므로 끝까지 자동으로 입력되기 때문이다. 
이때 사전에 있는 단어들을 입력하기 위해 버튼을 눌러야 하는 횟수의 평균은 (3 + 2 + 2 + 1)/4 = 2.00이다.
사전이 주어졌을 때, 이 모듈을 사용하면서 이와 같이 각 단어를 입력하기 위해 버튼을 눌러야 하는 횟수의 평균을 구하는 프로그램을 작성하시오.
Comment: 처음 구현한 트라이 구조를 사용하면 당~~~~~~~연히 메모리가 폭발한다.
트라이 최적화가 이 문제의 핵심 포인트가 될 것.
-> 배열로 바꿈
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

bool initial;
int answer, T;
char str[100000][81];

struct Trie{
    bool is_end;
    int cnt;
    Trie *children[26];
    
    Trie() : is_end(false), cnt(0) {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(children[i]) delete children[i];
        }
    }
    
    void insert(const char * key) {
        if(*key == '\0') is_end = true;
        else {
            int index = *key - 'a';
            if(children[index] == nullptr) {
                children[index] = new Trie();
                cnt++;
            }
            children[index]->insert(key + 1);
        }
    }
    
    void find(char * str) {
        if(*str == '\0') return;
        if(initial) {
            initial = false;
            answer++;
        }
        else {
            if(is_end) answer++;
            else if(cnt > 1) answer++;
        }
        int index = *str - 'a';
        children[index]->find(str + 1);  
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("E.in", "r", stdin);
    while(cin >> T) {
        Trie* root = new Trie();
        answer = 0;

        for(int i = 0; i < T; i++) {
            cin >> str[i];
            root->insert(str[i]);
        }

        for(int i = 0; i < T; i++) {
            initial = true;
            root->find(str[i]);
        }

        cout << fixed << setprecision(2) << (double)answer / (double)T << '\n';
        delete root;

    }
    return 0;
}