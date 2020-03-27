#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define TRIENUM 26 //알파벳? 10진법 숫자?

class Trie {    
    private:
        bool is_end;
        Trie *children[TRIENUM];
    public:
        Trie() : is_end(false) { memset(children, 0, sizeof(children)); }
        ~Trie() {
            for(int i = 0; i < TRIENUM; i++) {
                if(children[i]) delete children[i];
            }
        }
        void insert(string key, int idx) {
            if(idx == key.size()) is_end = true;
            else {
                int index = key[idx] - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
                if(children[index] == 0) children[index] = new Trie();
                children[index]->insert(key, ++idx);
            }
        }
        Trie* find(string key, int idx) {
            if(idx == key.size()) return this;
            int index = key[idx] - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
            if(children[index] == 0) return NULL;
            return children[index]->find(key, ++idx);
        }
        bool string_exist(string key, int idx) {
            if(idx == key.size() && is_end) return true;
            int index = key[idx] - 'A'; // 알파벳 대/소문자 여부, 숫자 여부에 따라 조정할 것.
            if(children[index] == 0) return false;
            return children[index]->string_exist(key, ++idx);
        }
};

int main() { //Driver
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
}