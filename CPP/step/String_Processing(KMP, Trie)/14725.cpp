/*
Problem: 개미굴
Tier: Gold 2
Detail: 다음은 로봇 개미들이 윤수에게 보내준 정보다.
    KIWI BANANA
    KIWI APPLE
    APPLE APPLE
    APPLE BANANA KIWI
(공백을 기준으로 왼쪽부터 순서대로 로봇 개미가 첫 층부터 각 층마다 지나온 방에 있는 먹이 이름을 뜻한다.)
윤수는 로봇 개미들이 보내준 정보를 바탕으로 다음과 같이 개미굴의 구조를 손으로 그려봤다.
APPLE
--APPLE
--BANANA
----KIWI
KIWI
--APPLE
--BANANA
(개미굴의 각 층은 "--" 로 구분을 하였다. 또 같은 층에 여러 개의 방이 있을 때에는 사전 순서가 앞서는 먹이 정보가 먼저 나온다.)
Comment: 일반적인 트라이 구조가 아닌, 문제에 맞게 변경/간소화 해야 풀 수 있을듯...
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Node {
    map<string, Node> child;
} root;

void insert(Node &v, vector<string> vec, int cnt) {
    if(cnt == vec.size()) return;
    if(v.child.find(vec[cnt]) == v.child.end()) v.child.insert(make_pair(vec[cnt], Node()));
    insert(v.child[vec[cnt]], vec, cnt + 1);
}

void dfs(Node &v, int cnt = 0) {
	for(auto i : v.child){
		for(int j = 0; j < cnt; j++) cout << "--";
		cout << i.first << "\n";
		dfs(i.second, cnt + 1);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int m; cin >> m;
        vector<string> vec;
        for(int i = 0; i < m; i++) {
            string s;
            cin >> s;
            vec.push_back(s);
        }
        insert(root, vec, 0);
    }
    dfs(root, 0);
    return 0;
}