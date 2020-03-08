/*
Problem: 가장 가까운 두 점(2261)
Tier: Platinum 5
Detail: 2차원 평면상에 n개의 점이 주어졌을 때,
이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.
Comment: 
절반으로 나눠서
왼쪽에서의 최솟값, 오른쪽에서의 최솟값을 구함.
일단 이것부터 해볼까.
쪼개고 나서가 문제인데....
점 1개 : return 0
점 2개 : return 두개의 거리
점 3개? 근데 여기부턴 걍 1개 2개로 나누는게 맞지 않나.
iterator도 어떻게 보면 포인터의 일종이라 배열처럼 참조가 가능한건가??

*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;

vector<pair<int, int>> dot;
int N;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

bool compare_2(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int dist(const pair<int, int> &x, const pair<int, int> &y) {
    return (pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int find_max(vector<pair<int, int>>::iterator it, int n) {
    if(n == 2) return dist(it[0], it[1]);
    if(n == 3) return min({dist(it[0], it[1]), dist(it[0], it[2]), dist(it[2], it[1])});
    int mid_line = (it[n/2 - 1].first + it[n/2].first) / 2;
    int MIN = min(find_max(it, n/2), find_max(it + n/2, n - n/2));
    vector<pair<int, int>> vec;
    vec.reserve(n);
    for(int i = 0; i < n; i++) {
        if(pow(mid_line  - it[i].first, 2) < MIN) vec.push_back(it[i]); 
    }
    sort(vec.begin(), vec.end(), compare_2);
    int size = vec.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(pow(vec[j].second - vec[i].second, 2) < MIN) {
                MIN = min(MIN, dist(vec[i], vec[j]));
            } else break;
        }
    }
    return MIN;
}

int main() {
    scanf("%d", &N);
    dot.reserve(N);
    for(int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dot.push_back(make_pair(x, y));
    }
    sort(dot.begin(), dot.end(), compare);
    vector<pair<int, int>>::iterator iter = dot.begin();
    printf("%d", find_max(iter, N));
    return 0;
}
