/*
Problem: 파일 합치기 (11066)
Tier: Gold 3
Detail: 소설가인 김대전은 소설을 여러 장(chapter)으로 나누어 쓰는데, 각 장은 각각 다른 파일에 저장하곤 한다.
소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어있는 한 개의 파일을 만든다.
이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 파일을 합쳐나가고,
최종적으로는 하나의 파일로 합친다. 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합이라고 가정할 때,
최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.
Comment: DP[i][j] = sum(data[i, i+1, ... j]) + min(dp[i][i+1] + dp[i+2][j], dp[i][i+2] + dp[i+3][j] ...)
부분합을 계산하기 위해 2차원 테이블을 만드는 것 보다, 1차원으로 만들어서 메모리를 절약하는게 낫다는 생각이 들었음.
*/

#include <stdio.h>
#include <vector>
using namespace std;

int N;

int get_ans(vector<vector<int>> &vec, const vector<int> &sum_vec, int s, int e) {
    int min = 2000000000;
    int tmp = 0;
    if(s == e) return 0;
    if(vec[s][e] != 0) return vec[s][e];
    for(int i = 0; i <= e - s - 1; i++) {
        tmp = get_ans(vec, sum_vec, s, s + i) + get_ans(vec, sum_vec, s + i + 1, e);
        if(min > tmp) min = tmp;
    }
    if(s == 0) return vec[s][e] = sum_vec[e] + min;
    return vec[s][e] = sum_vec[e] - sum_vec[s-1] + min;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        vector<vector<int>> vec(k, vector<int>(k, 0));
        vector<int> sum_vec(k);
        vector<int> data(k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &data[i]);
        }
        sum_vec[0] = data[0];
        for(int i = 1; i < k; i++) {
            sum_vec[i] = sum_vec[i-1] + data[i];
        }
        printf("%d\n", get_ans(vec, sum_vec, 0, k-1));
    }
    return 0;
}