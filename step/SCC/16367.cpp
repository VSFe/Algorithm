/*
Problem: TV Show Game (16367)
Tier: Platinum 3
Detail:  Mr. Dajuda, who is famous for a TV show program, occasionally suggests an interesting game for the audience and gives them some gifts as a prize. The game he suggested this week can be explained as follows.
The k(> 3) lamps on the stage are all turned off at the beginning of the game. For convenience, lamps are numbered from 1 to k. Each lamp has a color, either red or blue.
However, the color of a lamp cannot be identified until it is turned on. Game participants are asked to select three lamps at random and to guess the colors of them.
Then each participant submits a paper on which the predicted colors of selected lamps are recorded to Mr. Dajuda, the game host. When all the lamps are turned on, each participant checks how many predicted colors match the actual colors of the lamps.
If two or more colors match, he/she will receive a nice gift as a prize. Mr. Dajuda prepared a special gift today.
That is, after reviewing all the papers received from the game participants he tries to adjust the color of each lamp so that every participant can receive a prize if possible.
Given information about the predicted colors as explained above, write a program that determines whether the colors of all the lamps can be adjusted so that all the participants can receive prizes.
Comment: A, B, C중 두개 이상이 참
-> (A or B) and (B or C) and (A or C)
따라서 하나의 정보를 세개로 나누면 2-SAT 문제가 된다...
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[10100];
int dfs_num[10100], RB[5020], finished[10100];
int cnt = 1, SC = 1, N, M;
stack<int> st;

const int stand = 5010;

void dfs(int idx, int prev) {
    int dfn = dfs_num[idx] = cnt++;
    st.push(idx);
    for(auto next : graph[idx]) {
        if(!dfs_num[next]) dfs(next, idx);
        if(!finished[next]) dfs_num[idx] = min(dfs_num[idx], dfs_num[next]);
    }
    if(dfs_num[idx] == dfn) {
        while(1) {
            int t = st.top();
            finished[t] = SC;
            st.pop();
            if(t == idx) break;
        } SC++;
    }
}

void get_answer() {
    vector<pair<int, int>> vec;
	for (int i = 1; i <= N; i++){
		vec.push_back({finished[stand - i], stand - i});
		vec.push_back({finished[stand + i], stand + i});
	}
	sort(vec.begin(), vec.end(), greater<pair<int, int>>());
	for (auto p : vec){
		int x, tf;
		x = p.second;
		if (x < stand){ x = stand - x; tf = 1; }
		else { x = x - stand; tf = 0; }
		if (RB[x] < 0) RB[x] = tf;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(RB, -1, sizeof(RB));
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int num[3], rb[3];
        char tmp;
        for(int i = 0; i < 3; i++) {
            cin >> num[i] >> tmp;
            if(tmp == 'R') rb[i] = 1;
            else rb[i] = -1;
        }
        graph[stand - num[0] * rb[0]].push_back(stand + num[1] * rb[1]);
        graph[stand - num[0] * rb[0]].push_back(stand + num[2] * rb[2]);
        graph[stand - num[1] * rb[1]].push_back(stand + num[0] * rb[0]);
        graph[stand - num[1] * rb[1]].push_back(stand + num[2] * rb[2]);
        graph[stand - num[2] * rb[2]].push_back(stand + num[0] * rb[0]);
        graph[stand - num[2] * rb[2]].push_back(stand + num[1] * rb[1]);
    }
    for(int i = 1; i <= N; i++) {
        if(!dfs_num[stand - i]) dfs(stand - i, 0);
        if(!dfs_num[stand + i]) dfs(stand + i, 0);
    }
    for(int i = 1; i <= N; i++) {
        if(finished[stand - i] == finished[stand + i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    get_answer();
    for(int i = 1; i <= N; i++) {
        if(RB[i] == 0) cout << 'B';
        else cout << 'R';
    }
    return 0;
}