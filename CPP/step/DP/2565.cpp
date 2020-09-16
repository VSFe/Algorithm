/*
Problem: 전깃줄 (2565)
Tier: Silver 1
Detail: 두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다.
합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄,
A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.
전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다.
전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때,
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.
Comment: 처음엔 뭔 소리인지 몰랐는데 LIS를 만들고 나면 너무나도 쉽게 풀림.
처음을 기준으로 정렬을 하고 두번째 값을 활용해 LIS를 만들면 끝!
*/

#include <utility>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int IDX = 0;
vector<pair<int, int>> gap;
int dt[1000], result[1001]; 

int bs(int val, int start, int end) {
    if(start == end) return end;
    int mid = (start + end) / 2;
    if(result[mid] < val) return bs(val, mid + 1, end);
    else return bs(val, start, mid);
}

int main() {
    scanf("%d", &N);
    gap.reserve(N);
    for (int i = 0; i < N; i++) {  
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);    
        gap.push_back(make_pair(tmp1, tmp2));
    }
    sort(gap.begin(), gap.end());
    for (int i =0; i < N; i++) dt[i] = gap[i].second;
    result[0] = 0;
    for(int i =0; i < N; i++) {
        if(result[IDX] < dt[i]) result[++IDX] = dt[i];
        else {
            int tmp = bs(dt[i], 1, IDX);
            if(result[tmp] > dt[i]) result[tmp] = dt[i]; 
        }
    }
    printf("%d", N - IDX);
    return 0;
}


