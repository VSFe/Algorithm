/*
Problem: 문자열 집합
Tier: Silver 3
Detail: 총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.
Comment: Trie로 풀었는데 원래 이거 메모리가 1기가 나오고 그래?
*/

#include <stdio.h>
#include <cstring>
using namespace std;

#define TRIENUM 26 // 알파벳? 10진법 숫자?

struct Trie{
    bool is_end;
    Trie *children[TRIENUM];
    
    Trie() : is_end(false) { memset(children, 0, sizeof(children)); }
    ~Trie() {
        for(int i = 0; i < TRIENUM; i++) {
            if(children[i]) delete children[i];
        }
    }
    
    void insert(const char * key) {
        if(*key == '\0') is_end = true;
        else {
            int index = *key - 'a'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
            if(children[index] == 0) children[index] = new Trie();
            children[index]->insert(key + 1);
        }
    }

    Trie* find(const char *key) {
        if(*key == 0) return this;
        int index = *key - 'a'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
        if(children[index] == 0) return NULL;
        return children[index]->find(key+1);
    }

    bool string_exist(const char * key) {
        if(*key == 0 && is_end) return true;
        int index = *key - 'a'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
        if(children[index] == 0) return false;
        return children[index]->string_exist(key + 1);
    }
};

int main() {
    Trie tr;
    int N, M, cnt = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        char tmp[501];
        scanf("%s", tmp);
        tr.insert(tmp);
    }
    for(int i = 0; i < M; i++) {
        char tmp[501];
        scanf("%s", tmp);
        if(tr.string_exist(tmp)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}