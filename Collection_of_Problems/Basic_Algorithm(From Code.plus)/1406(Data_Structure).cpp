/*
Problem: 에디터 (1406)
Tier: Silver 3
Detail: 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때,
모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오.
단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.
Comment: 딱 봐도 링크드 리스트로 풀면 될 것 같았음...
*/

#include <stdio.h>
#include <cstring>
#include <list>
using namespace std;

char input[100001];
int N;

int main() {
    scanf("%s %d", input, &N);
    list<char> li;
    int size = strlen(input);
    for(int i = 0; i < size; i++) {
        li.push_back(input[i]);
    }
    list<char>::iterator p = li.end();
    for(int i = 0; i < N; i++) {
        char X, Y;
        scanf(" %c", &X);
        switch (X) {
            case 'L':
                if(p != li.begin()) p--;
                    continue;
            case 'D':
                if(p != li.end()) p++; 
                    continue;
            case 'B':
                if(p != li.begin()) {
                    p--;
                    p = li.erase(p);
                }
                continue;
            case 'P':
                scanf(" %c", &Y);
                li.insert(p, Y);
                continue;
        }
    }
    for(list<char>::const_iterator i = li.begin(); i != li.end(); i++) {
        printf("%c", *i);
    }
    return 0;
}