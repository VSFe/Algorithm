/*
Problem: 회의실 배정 (1931)
Tier: Silver 2
Detail: 한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려고 한다.
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대수의 회의를 찾아라.
Comment: 첫번째는 가장 빨리 끝나는걸로, 그 다음부터도 이어서 먼저 끝나는거 끼리 넣으면 됨...
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

bool compare (const pair<int, int> &a, const pair<int, int> &b ){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int N;
vector<pair<int, int>> yee;
int CNT = 1;

int main() {
    scanf("%d", &N);
    yee.reserve(N);
    for(int i =0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        yee.push_back(make_pair(x, y));
    }
    clock_t start = clock();
    sort(yee.begin(), yee.end(), compare);
    int cut = yee.front().second;
    for(int i = 1; i < N; i++) {
        if(yee[i].first >= cut) {
            CNT++;
            cut = yee[i].second;
        }
    }
    clock_t end = clock();
    printf("%d", CNT);
    //printf("%f ms", (double)(end - start));
    return 0;
}
