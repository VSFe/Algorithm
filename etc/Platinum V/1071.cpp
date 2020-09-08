#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        map<int, int>::iterator iter = m.find(tmp);

        if(iter == m.end()) {
            m.insert({tmp, 1});
        }
        else {
            iter->second++;
        }
    }

    m.insert({10000, 1});

    while(m.size() > 1) {
        map<int, int>::iterator iter1, iter2;
        iter1 = iter2 = m.begin();
        iter2++;

        if(iter1->first + 1 == iter2->first) {
            iter2++;
            if(iter2->first != 10000) {
                cout << iter1->first << ' ';
                if(--(iter1->second) == 0) {
                    m.erase(iter1->first);
                    cout << iter2->first << ' ';
                    if(--(iter2->second) == 0) {
                        m.erase(iter2->first);
                    }                    
                }
            }
            else {
                iter2--;
                cout << iter2->first << ' ';
                if(--(iter2->second) == 0) {
                    m.erase(iter2->first);
                }
            }
        }

        else {
            cout << iter1->first << ' ';
            if(--(iter1->second) == 0) {
                m.erase(iter1->first);
            }
        }
    }
}