/*
Problem: 음악프로그램 (2623)
Tier: Gold 2
Detail: 인터넷 방송 KOI(Korea Open Internet)의 음악 프로그램 PD인 남일이는 자기가 맡은 프로그램 '뮤직 KOI'에서 가수의 출연 순서를 정하는 일을 매우 골치 아파한다. 순서를 정하기 위해서는 많은 조건을 따져야 한다.
그래서 오늘 출연 예정인 여섯 팀의 가수에 대해서 남일이가 보조 PD 세 명에게 각자 담당한 가수의 출연 순서를 정해오게 하였다. 보조 PD들이 가져온 것은 아래와 같다.
    1 4 3
    6 2 5 4
    2 3
첫 번째 보조 PD는 1번 가수가 먼저, 다음에 4번 가수, 다음에 3번 가수가 출연하기로 순서를 정했다.
두 번째 보조 PD는 6번, 2번, 5번, 4번 순으로 자기 담당 가수들의 순서를 정했다. 한 가수를 여러 보조 PD가 담당할 수도 있다. 마지막으로, 세 번째 보조 PD는 2번 먼저, 다음에 3번으로 정했다.
남일이가 할 일은 이 순서들을 모아서 전체 가수의 순서를 정하는 것이다. 남일이는 잠시 생각을 하더니 6 2 1 5 4 3으로 순서를 정했다.
이렇게 가수 순서를 정하면 세 보조 PD가 정해온 순서를 모두 만족한다. 물론, 1 6 2 5 4 3으로 전체 순서를 정해도 괜찮다.
경우에 따라서 남일이가 모두를 만족하는 순서를 정하는 것이 불가능할 수도 있다. 예를 들어, 세 번째 보조 PD가 순서를 2 3 대신에 3 2로 정해오면 남일이가 전체 순서를 정하는 것이 불가능하다.
이번에 남일이는 우리 나라의 월드컵 4강 진출 기념 음악제의 PD를 맡게 되었는데, 출연 가수가 아주 많다.
이제 여러분이 해야 할 일은 보조 PD들이 가져 온 순서들을 보고 남일이가 가수 출연 순서를 정할 수 있도록 도와 주는 일이다.
보조 PD들이 만든 순서들이 입력으로 주어질 때, 전체 가수의 순서를 정하는 프로그램을 작성하시오
Comment: 매우 평범한 위상정렬 문제. 사이클 구조만 잘 골라내면 쉬움...
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, in[1001];
vector<int> vec[1001], ans;
priority_queue<int> pq;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int len, u, v;
    for(int i = 0; i < M; i++) {
        cin >> len >> u;
        for(int j = 1; j < len; j++) {
            cin >> v;
            vec[u].push_back(v);
            in[v]++;
            u = v;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(!in[i]) pq.push(i);
    }
    while(!pq.empty()) {
        int num = pq.top(); pq.pop();
        ans.push_back(num);
        for(auto next : vec[num]) {
            if(!(--in[next])) pq.push(next);
        }
    }
    if(ans.size() != N) cout << 0;
    else for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}