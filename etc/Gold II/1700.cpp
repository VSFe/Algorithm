/*
Problem: 멀티탭 스케쥴링
Tier: Gold 2
Detail: 기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다.
준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다.
그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.
예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면, 
    키보드
    헤어드라이기
    핸드폰 충전기
    디지털 카메라 충전기
    키보드
    헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다. 
Comment: 뒷 부분을 확인해서 먼저 나오는 것을 출력하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 500;
int dt[101], location[101], turnon[101], cnt = 0, ans = 0;
vector<int> vec[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin >> N >> K;
    vector<int> plug(N);
    for(int i = 1; i <= K; i++) {
        int tmp; cin >> tmp;
        vec[tmp].push_back(i);
        dt[i] = tmp;
    }
    for(int i = 1; i <= K; i++) {
        vec[i].push_back(-1);
    }
    for(int i = 1; i <= K; i++) {
        if(cnt < N) {
            if(!turnon[dt[i]]) {
                turnon[dt[i]] = 1;
                plug[cnt] = dt[i];
                location[plug[cnt]]++;
                cnt++;
            } else location[dt[i]]++;
            continue;
        }
        int MIN = -1, MIN_val = -1, flag = 0;
        if(turnon[dt[i]]) {
            location[dt[i]]++;
            continue;
        }
        for(int j = 0; j < N; j++) {
            int tmp = vec[plug[j]][location[plug[j]]];
            if(tmp == -1) {
                MIN = j;
                break;
            }
            else if(MIN_val < tmp) {
                MIN_val = tmp;
                MIN = j;
            }
        }
        turnon[plug[MIN]] = 0;
        turnon[dt[i]] = 1;
        plug[MIN] = dt[i];
        location[dt[i]]++;
        ans++;
    }
    cout << ans;
}