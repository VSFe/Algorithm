/*
Problem: 용량 부족
Tier: Platinum 3
Detail: 팀포2 덕후 연수는 팀포2를 다운받던 도중 하드 용량이 부족하다는 것을 알았다. 이때는 침착하게 팀포2를 하지 말거나 하드를 새로 사면 되지만 불가능했고, 결국 하드에서 쓸모없는 파일을 지워야만 한다.
연수는 또한 턱스 덕후여서 리눅스를 사용중이다. 리눅스에서 현재 디렉토리의 특정 파일을 지우려면 "rm 파일명"의 형식을 갖춰 명령하면 된다.
그러나 파일 개수가 너무 많을 경우 일일이 다 칠 수 없기에, 와일드카드 '*'를 사용할 수도 있다.
"rm 문자열*" 형식으로 명령하면 현재 디렉토리에서 파일 이름이 "문자열"이거나 "문자열"로 시작하는 모든 파일이 한번에 삭제된다! 그러나 지워서는 안 되는 파일들 또한 존재한다.
rm 명령어를 잘못 사용하여 이러한 파일들을 지우지 않도록 조심해야 할 것이다. 때에 따라서 "rm *"도 사용할 수 있긴 하다. 현재 디렉토리의 모든 파일을 지우고 싶을 때만...
모든 파일이 디렉토리 하나에 존재하고 연수가 그 디렉토리에 있을 때, 지우고 싶은 파일들을 모두 지우는 데 필요한 최소 rm 명령 횟수를 구하시오.
단, 사용할 수 있는 와일드카드는 '*' 뿐이며 반드시 제일 끝에만 사용해야 한다. 예를 들면 "rm *.txt"는 사용할 수 없다.
Comment: 트라이를 만들어주고, 안되는 것 끼리 일단 검색을 돌린다.
검색 과정에서 방문한 모든 트라이 노드에 색칠을 하고, 이후 지워야 하는 파일을 다시 한 번 검색하면서 색칠 안된 포인트를 만나기 전 까지 계속 탐색한다.
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool initial;
int answer, T;
char str[1000][21], str_2[1000][21];

struct Trie{
    bool is_end;
    bool is_visited;
    bool is_processed;
    Trie *children[63];
    
    Trie() : is_end(false), is_visited(false), is_processed(false){
        for(int i = 0; i < 63; i++) children[i] = nullptr;
    }
    ~Trie() {
        for(int i = 0; i < 63; i++) {
            if(children[i]) delete children[i];
        }
    }
    
    void insert(const char * key) {
        if(*key == '\0') is_end = true;
        else {
            int index;
            if(*key < '0') index = 0;
            else if(*key < 'A') index = *key - '0' + 1;
            else if(*key < 'a') index = *key - 'A' + 11;
            else index = *key - 'a' + 37;
            if(children[index] == nullptr) {
                children[index] = new Trie();
            }
            children[index]->insert(key + 1);
        }
    }
    
    void findSafe(char * str) {
        is_visited = true;
        if(*str == '\0') return;
        int index;
        if(*str < '0') index = 0;
        else if(*str < 'A') index = *str - '0' + 1;
        else if(*str < 'a') index = *str - 'A' + 11;
        else index = *str - 'a' + 37;
        if(children[index] == nullptr) return;
        children[index]->findSafe(str + 1);  
    }

    void find(char * str) {
        if(!is_visited || *str == '\0') {
            if(is_processed) return;
            is_processed = true;
            answer++;
            return;
        }
        int index;
        if(*str < '0') index = 0;
        else if(*str < 'A') index = *str - '0' + 1;
        else if(*str < 'a') index = *str - 'A' + 11;
        else index = *str - 'a' + 37;
        children[index]->find(str + 1);  
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++) {
        int num_remove, num_notremove;
        Trie* root = new Trie();
        answer = 0;
        cin >> num_remove;
        for(int i = 0; i < num_remove; i++) {
            cin >> str[i];
            root->insert(str[i]);
        }
        cin >> num_notremove;
        for(int i = 0; i < num_notremove; i++) {
            cin >> str_2[i];
            root->findSafe(str_2[i]);
        }
        for(int i = 0; i < num_remove; i++) {
            root->find(str[i]);
        }

        cout << answer << '\n';
        delete root;

    }
    return 0;
}