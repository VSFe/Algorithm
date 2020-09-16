/*
Problem: 나무 자르기 (2805)
Tier: Silver 3
Detail: 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다.
따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자.
상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다.
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
Comment: mid 값을 단순히 2로 나눌 경우, 상한/하한의 차이가 1일 경우 문제가 생길 수 있다.
따라서 변화를 위해 +1이나 -1을 주고 하는 것도 괜찮은 방법인 것 같음...
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int MAX = 0;
vector<int> vec;

int main() {
    scanf("%d %d", &N, &M);
    vec.reserve(N);
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        MAX = max(MAX, tmp);
        vec.push_back(tmp);
    }
    int lower_bound = 0, upper_bound = MAX;
    while(lower_bound < upper_bound) {
        int mid = (lower_bound + upper_bound) / 2 + 1;
        long long int leng = 0;
        for(int i = 0; i < N; i++) {
            if(vec[i] > mid) leng += vec[i] - mid;
        }
        if(leng == M) lower_bound = upper_bound = mid;
        else if(leng > M) lower_bound = mid;
        else upper_bound = mid-1;
    }    
    printf("%d", lower_bound);
    return 0;
}