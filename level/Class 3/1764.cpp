/*
Problem: 듣보잡
Tier: Silver 4
Detail:  김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.
Comment: 파이썬으로 하려다가 열 받아서 이걸로 함...
*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

set<string> s;
vector<string> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t1, t2;
    cin >> t1 >> t2;
    for(int i = 0; i < t1; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0; i < t2; i++) {
        string tmp; cin >> tmp;
        if(s.find(tmp) != s.end()) vec.push_back(tmp);
    }
    cout << vec.size() << "\n";
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << "\n";
    return 0;
}