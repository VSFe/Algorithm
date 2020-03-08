/*
Problem: 공유기 설치 (2110)
Tier: Silver 2
Detail: 도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에,
한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.
Comment: 최대 거리의 최댓값 (?)은 length/N.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int N, C;
int MIN = 1000000000;
int save = 0;

int find_upper(int left, int right, int val) {
    int mid = (left + right) / 2 + 1;
    if(vec[mid] == val) return mid;
    if(vec[mid] > val) right = mid;
    else left = mid + 1;
    if(left == right) return left; 
    find_upper(left, right, val);
}

int find_lower(int left, int right, int val) {
    int mid = (left + right) / 2 + 1;
    if(vec[mid] == val) return mid;
    if(vec[mid] > val) right = mid-1;
    else left = mid;
    if(left == right) return left; 
    find_lower(left, right, val);
}

int main() {
    scanf("%d %d", &N ,&C);
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int length = vec.back() - vec.front();
    int interval = length / (C-1);
    save = vec.front();
    for(int i = 1; i < C; i++) {
        int obj = vec.front() + i * interval;
        int row = find_lower(0, N-1, obj);
        int high = find_upper(0, N-1, obj);
        MIN = min(MIN, min(abs(interval - (vec[row] - save)), abs(interval - (vec[high] - save))));
    }
    printf("%d", min(MIN, vec.back() - save));
    return 0;
}
