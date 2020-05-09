/*
Problem: 홍준 프로그래밍 대회 (1222)
Tier: Gold 1
Detail: 홍준이는 프로그래밍 대회를 개최했다. 이 대회는 사람들이 팀을 이루어서 참가해야 하며, 팀원의 수는 홍준이가 정해준다.
팀원이 홍준이가 정한 값보다 부족하다면, 그 팀은 대회에 참여할 수 없다. 모든 팀은 같은 수의 팀원으로 이루어져 있다.
대회에 참여 의사를 밝힌 학교는 총 N개이다. 각 학교는 모든 학생이 참여할 수 있는 경우에만 대회에 참가한다. 즉, 남는 사람 없이 모든 학생이 팀에 들어갈 수 있어야 한다.
대회는 예선과 본선으로 구성되어 있다. 모든 팀은 같은 학교 소속으로 이루어져 있어야 한다. 예선에서 각 학교 1등팀만 본선에 진출한다. 
홍준이의 대회는 올해가 첫 해이기 때문에, 많은 관심이 필요하다. 따라서, 본선에 참가하는 사람의 수를 최대가 되도록 팀원의 수를 정하려고 한다.
또, 본선이 지루해지는 것을 막기 위해 적어도 두 팀이 본선에 참가할 수 있어야 한다.
홍준이가 팀원을 몇 명으로 정해야 본선에 참가하는 사람의 수가 최대가 되는지 구하는 프로그램을 작성하시오.
Comment: 인수를 구해서 2개 이상인 경우에 곱의 합을 구하면 된다.
*/

#include <iostream>
using namespace std;

int total_list[2000001], members[200001];
int N;

void get_ans() {
    for(int i = 0; i < N; i++) {
        int dt = members[i];
        for(int j = 1; j * j <= dt; j++) {
            if(dt % j == 0) {
                total_list[j]++; 
                if(j != dt / j) total_list[dt / j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> members[i];
    get_ans();
    long long ans = 0;
    for(int i = 1; i < 2000001; i++) {
        if(total_list[i] > 1) ans = max(ans, (long long)(total_list[i]) * i);
    }
    cout << ans;
}