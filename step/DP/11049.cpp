/*
Problem: 행렬 곱셈 순서 (11049)
Tier: Gold 3
Detail: 크기가 N×M인 행렬 A와 M×K인 B를 곱할 때 필요한 곱셈 연산의 수는 총 N×M×K번이다. 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.
예를 들어, A의 크기가 5×3이고, B의 크기가 3×2, C의 크기가 2×6인 경우에 행렬의 곱 ABC를 구하는 경우를 생각해보자.
    AB를 먼저 곱하고 C를 곱하는 경우 (AB)C에 필요한 곱셈 연산의 수는 5×3×2 + 5×2×6 = 30 + 60 = 90번이다.
    BC를 먼저 곱하고 A를 곱하는 경우 A(BC)에 필요한 곱셈 연산의 수는 3×2×6 + 5×3×6 = 36 + 90 = 126번이다.
같은 곱셈이지만, 곱셈을 하는 순서에 따라서 곱셈 연산의 수가 달라진다.
행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램을 작성하시오. 입력으로 주어진 행렬의 순서를 바꾸면 안 된다.
Comment: 11066번과 유사한 문제라고 생각하는데...
11066번은 재귀로 풀어서 함수 오버헤드가 많이 나옴 -> 그래서 이번엔 내부 순환으로 해결할 수 있도록 해봐야지.
*/

#define INF 2147483647
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> vec;
vector<pair<int, int>> vec_data;

int main() {
    scanf("%d", &n);
    vec = vector<vector<int>>(n, vector<int>(n, 0));
    vec_data.reserve(n);
    for(int i = 0; i < n; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        vec_data[i] = make_pair(tmp1, tmp2);
    }
    for(int dia = 1; dia < n; dia++) {
        for(int i = 0; i <  n - dia; i++) {
            int j = dia + i;
            vec[i][j] = INF;
            for(int k = 0; k <= j - i - 1; k++) {
                vec[i][j] = min(vec[i][j], vec[i][i+k] + vec[i+k+1][j] + vec_data[i].first * vec_data[i+k].second * vec_data[j].second);
            }
        }
    }
    printf("%d", vec[0][n-1]);
    return 0;
}