/*
Problem: 도시 계획 (11097)
Tier: Platinum 4
Detail: 경기도의 어떤 한 도시는 새 구역을 건설해서 도시를 확장하려고 한다. 그래서 이 도시에서는 우리의 친구 남서를 비롯한 여러 유명 건축가들을 불러 디자인을 시켰다.
남서는 도로망 디자인 담당이 되었는데, 귀찮았던 나머지 구역 내의 지역들을 잇는 모든 도로를 일방통행으로 만들어버렸다.
(다행히도, 두 지역 A B간에 A에서 B로 가는 도로, B에서 A로 가는 도로를 놓아 서로 연결할 수 있다.)
남서는 자신의 도로망 계획을 지도해 그려본 결과, 일방통행 도로들 때문에 몇몇 지역들에서 특정 지역으로 갈 수 없다는 것을 깨달았다.
이 문제를 해결하기 위해서, 남서는 놀라운 접근법을 사용하기로 했다: 종이에 갈 수 있는 모든 경우의 수를 쓰는 것이다.
좀 더 자세히 말하자면, 각 지역 j에 대해서 j로부터 갈 수 있는 모든 지역에 대해 리스트를 작성하는 것이다. 우리는 이 리스트를 도로망의 '갈 수 있는 지역 리스트'라고 부른다.
(만약 A에서 B로 가는 길이, B에서 C로 가는 길이 있다면 A의 리스트에는 B,C가, B의 리스트에는 C가 적힐 것이다.)
그러나, 남서는 문제를 해결하던 도중 하드 디스크가 망가져 자기가 만든 도로망 계획을 모두 잃어버렸다. 그에게 남은 것은 책상 위의 종이 한 장 - '갈 수 있는 지역 리스트' 하나 뿐이다.
우리는 불쌍한 남서를 도와 이 '갈 수 있는 리스트'를 통해서 원래 도로망 계획을 알아내려고 한다. 물론, 한 '갈 수 있는 리스트'에 대해서 여러 도로망 구조가 만들어질 수 있다.
우리는 이 중에서 각 지역을 잇는 도로의 개수가 가장 적은 도로망 계획을 구하고자 한다. 그러면 아마도 남서에게 큰 도움이 될 것이다.
주어진 '갈 수 있는 지역 리스트'에 대해서 가장 적은 도로로 이루어진 도로망 계획을 구하여라.
Comment: 각각의 입력을 string으로 받자.
해시로 잘 넣어준 다음에 각각의 문자열이 처음 등장한 부분을 SCC의 이어진 구간이라고 하자.
SCC끼리는 서로 이어줘야 하고, SCC가 아닌 구간 끼리는 단 한개의 간선으로 이어주면 최소 횟수 확보 가능.
그런데 이렇게 하면 불필요한 간선이 발생하므로 플로이드-워셜 알고리즘을 또 끼얹어서... 최소의 이동횟수를 확보해야한다.
살려줘ㅓㅓㅓㅓ
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

unordered_map<string, int> us;
vector<pair<int, int>> vec;
int N, first_appear[305], idx[305], cnt;
vector<int> scc[305], graph[305];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC; cin >> TC;
    string s;
    for(int tc = 0; tc < TC; tc++) {
    cin >> N;
    cnt = 0;
    vec.clear();
    us.clear();
    for(int i = 1; i < 305; i++) scc[i].clear();
    for(int i = 1; i < 305; i++) graph[i].clear();
    fill(first_appear, first_appear + 305, 0);
    fill(idx, idx + 305, 0);
    for(int i = 1; i <= N; i++) {
        cin >> s;
        if(us.insert({s, i}).second) {
            cnt++;
            first_appear[cnt] = i;
            idx[i] = cnt;
            scc[cnt].push_back(i);
        }
        else {
            int where = us.find(s)->second;
            idx[i] = where;
            scc[where].push_back(i);
        }
    }
    for(int i = 1; i <= N; i++) {
        if(scc[i].size() >= 2) vec.push_back({scc[i].back(), scc[i].front()});
        for(int j = 1; j < scc[i].size(); j++) {
            vec.push_back({scc[i][j-1], scc[i][j]});
        }
    }
    for(unordered_map<string, int>::iterator iter = us.begin(); iter != us.end(); iter++) {
        int pos = iter->second;
        string str = iter->first;
        for(int j = 0; j < str.size(); j++) {
            int tmp = j + 1;
            if(str[j] == '0') continue;
            if(idx[pos] == idx[tmp]) continue;
            if(first_appear[idx[tmp]] == tmp) {
                graph[idx[pos]].push_back(idx[tmp]);
            }
        }
    }
    int floyd [305][305] = {0,};
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            floyd[i][graph[i][j]] = 1;
        }
    }
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(floyd[i][j] && floyd[i][k] && floyd[k][j]) floyd[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(floyd[i][j]) vec.push_back({i, j});
        }
    }
    cout << vec.size() << '\n';
    for(int i = 0; i < vec.size(); i++) cout << vec[i].first << ' ' << vec[i].second << '\n';
    cout << '\n';
}} 