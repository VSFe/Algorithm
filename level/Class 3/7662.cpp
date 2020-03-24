/*
Problem: 이중 우선순위 큐(7662)
Tier: Gold 5
Detail: 이중 우선순위 큐(dual priority queue)는 전형적인 우선순위 큐처럼 데이터를 삽입, 삭제할 수 있는 자료 구조이다.
전형적인 큐와의 차이점은 데이터를 삭제할 때 연산(operation) 명령에 따라 우선순위가 가장 높은 데이터 또는 가장 낮은 데이터 중 하나를 삭제하는 점이다.
이중 우선순위 큐를 위해선 두 가지 연산이 사용되는데, 하나는 데이터를 삽입하는 연산이고 다른 하나는 데이터를 삭제하는 연산이다.
데이터를 삭제하는 연산은 또 두 가지로 구분되는데 하나는 우선순위가 가장 높은 것을 삭제하기 위한 것이고 다른 하나는 우선순위가 가장 낮은 것을 삭제하기 위한 것이다. 
정수만 저장하는 이중 우선순위 큐 Q가 있다고 가정하자. Q에 저장된 각 정수의 값 자체를 우선순위라고 간주하자. 
Q에 적용될 일련의 연산이 주어질 때 이를 처리한 후 최종적으로 Q에 저장된 데이터 중 최댓값과 최솟값을 출력하는 프로그램을 작성하라.
Comment: multiset!
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        multiset<int> ms;
        int tc; cin >> tc;
        for(int j = 0; j < tc; j++) {
            char c;
            int num;
            cin >> c >> num;
            if(c == 'I') ms.insert(num);
            else if(ms.empty()) continue;
            else if(num == -1) ms.erase(ms.begin());
            else ms.erase(--ms.end());
        }
        if(ms.empty()) cout << "EMPTY" << "\n";
        else cout << *(--ms.end()) << ' ' << *(ms.begin()) << "\n"; 
    }
    return 0;
}