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
            int index = *key - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
            if(children[index] == 0) children[index] = new Trie();
            children[index]->insert(key + 1);
        }
    }

    Trie* find(const char *key) {
        if(*key == 0) return this;
        int index = *key - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
        if(children[index] == 0) return NULL;
        return children[index]->find(key+1);
    }

    bool string_exist(const char * key) {
        if(*key == 0 && is_end) return true;
        int index = *key - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
        if(children[index] == 0) return false;
        return children[index]->string_exist(key + 1);
    }
};