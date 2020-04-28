/*
Problem: 퍼즐 (1525)
Tier: Gold 2
Detail: 3×3 표에 다음과 같이 수가 채워져 있다. 오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.
어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 나가는 경우는 불가능하다.
우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다.
Comment: 빡구현...
2048과 유사한데 일정 홧수에서 커트해야한다.
해싱 방법: 1 << (3 * i + j) * graph[i][j] 로 해보자.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
 
const int FINISH = 123456789;
 
pair<int, int> moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int start = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            if (num == 0) num = 9;
            start = start * 10 + num;
        }

    queue<int> q;
    map<int, int> visited;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        string s = to_string(cur);
        q.pop(); 
        if (cur == FINISH) break;
        int z = s.find('9');
        int y = z / 3;
        int x = z % 3;

        for (int i = 0; i < 4; i++) {
            int Y = y + moveDir[i].second;
            int X = x + moveDir[i].first;

            if (Y >= 3 || Y < 0 ||X >= 3 || X < 0) continue;
            string temp = s;
            swap(temp[y * 3 + x], temp[Y * 3 + X]);

            int next = stoi(temp);
            if (!visited.count(next)) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
    if (!visited.count(FINISH)) cout << -1 << "\n";
    else cout << visited[FINISH] << "\n";
}