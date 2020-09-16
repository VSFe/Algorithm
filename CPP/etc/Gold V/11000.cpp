/*
Problem: 강의실 배정 (11000)
Tier: Gold 5
Detail: 수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 
김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 
참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
수강신청 대충한 게 찔리면, 선생님을 도와드리자!
Comment: 회의실 배정 (1931)의 강화판.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, S, T, cnt = 0; cin >> N;
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        cin >> S >> T;
        vec.push_back({S, T});
    }
    sort(vec.begin(), vec.end());
    pq.push(vec[0].second);
	for(int i = 1 ; i < N ; i++){
		if(pq.top()>vec[i].first){
			pq.push(vec[i].second);
		}
		else{
			pq.pop();
			pq.push(vec[i].second);
			}	
		}
	cout << pq.size();
    return 0;
}