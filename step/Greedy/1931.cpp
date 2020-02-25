/*
Problem: 회의실 배정 (1931)
Tier: Silver 2
<<<<<<< HEAD
Detail: 
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려고 한다.
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대수의 회의를 찾아라.
단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
Comment:
어쨌든 닥치고 첫번째 회의는 가장 먼저 끝나는거
사실 끝나는 시간으로 정렬하고 나서 하나씩 빼는게 맞는 것 같은데
종료시간 기준으로 정렬한거 하나, 시작시간 기준으로 정렬한거 하나

=======
Detail: 한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려고 한다.
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대수의 회의를 찾아라.
Comment: 첫번째는 가장 빨리 끝나는걸로, 그 다음부터도 이어서 먼저 끝나는거 끼리 넣으면 됨...
>>>>>>> b9820479825bac29153f5491c3ebae8c8bc0541c
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
<<<<<<< HEAD
using namespace std;

vector<pair<int, int>> gap;
int N;
int CNT = 1;

bool compare(const pair<int, int>& a, const pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

bool compare2(const pair<int, int>& a, const pair<int, int> &b) {
=======
#include <time.h>
using namespace std;

bool compare (const pair<int, int> &a, const pair<int, int> &b ){
>>>>>>> b9820479825bac29153f5491c3ebae8c8bc0541c
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

<<<<<<< HEAD
int main() {
    scanf("%d", &N);
    gap.reserve(N);
    int tmp1, tmp2;
    for(int i =0; i < N; i++) {
        scanf("%d %d" ,&tmp1, &tmp2);
        gap.push_back(make_pair(tmp1, tmp2));
    }
    sort(gap.begin(), gap.end(), compare2);
    int tmp = gap.front().second;
    if(N != 1) {
        for(vector<pair<int, int>>::const_iterator i = gap.begin()++; i != gap.end(); i++) {
            if(tmp <= i->first) {
                CNT++;
                tmp = i->second;
            }
        }
    }
    printf("%d", CNT);
    return 0;
}
=======
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
>>>>>>> b9820479825bac29153f5491c3ebae8c8bc0541c
