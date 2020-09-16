/*
Problem: 스타트와 링크
Tier: Silver 3
Detail: 오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다.
축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다.
능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다.
팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며,
i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 
Comment: 뭔가 아이디어 없이 혼자서 열심히 풀긴 했는데...
시간 복잡도 면에서 조금 아쉽다.
괜히 쓸데 없는 메소드를 끌어오지 말고 할 수 있는건 그냥 풀 수 있는 연습을 하면 좋을 것 같음... 흑흑
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int stat[20][20];
int start = 0, link = 0;
int mindiff = 100000000;


void test(vector<int> start_tmp, vector<int> link_tmp) {
    for(vector<int>::const_iterator iter1 = start_tmp.begin(); iter1 != start_tmp.end(); iter1++) {
        for(vector<int>::const_iterator iter2 = iter1; iter2 != start_tmp.end(); iter2++) {
            start += stat[*iter1][*iter2];
            start += stat[*iter2][*iter1];
        }
    }
    for(vector<int>::const_iterator iter1 = link_tmp.begin(); iter1 != link_tmp.end(); iter1++) {
        for(vector<int>::const_iterator iter2 = iter1; iter2 != link_tmp.end(); iter2++) {
            link += stat[*iter1][*iter2];
            link += stat[*iter2][*iter1];
        }
    }
    mindiff = min(mindiff, abs(start - link));
    start = 0, link = 0;
}

void select(vector<int> le) {
    vector<bool> tmp1(N);
    vector<int> start_tmp(N/2);
    vector<int> link_tmp(N/2);
    fill(tmp1.end() - N/2, tmp1.end(), true);
    int idx1, idx2;
    do {
        idx1 = 0, idx2 = 0;
        for(int i = 0; i < N; ++i) {
            if(tmp1[i]) start_tmp[idx1++] = *(le.begin() + i);
            else link_tmp[idx2++] = *(le.begin() + i);
        } 
        test(start_tmp, link_tmp);
    } while (next_permutation(tmp1.begin(), tmp1.end()));   
}

int main() {
    scanf("%d", &N);
    vector<int> length;

    for(int i = 0; i < N; i++) {
        length.push_back(i);
        for(int j=0; j < N; j++) {
            scanf("%d", &stat[i][j]);
        }
    }
    select(length);
    cout << mindiff;
    return 0;
}