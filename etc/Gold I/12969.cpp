/*
Problem: ABC (12969)
Tier: Gold 1
Detail: 정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.
    문자열 S의 길이는 N이고, 'A', 'B', 'C'로 이루어져 있다.
    문자열 S에는 0 ≤ i < j < N 이면서 S[i] < S[j]를 만족하는 (i, j) 쌍이 K개가 있다.
Comment: 일반항을 구해서 계산했더니 안된다...
그래서 그냥 재귀 DP로 해결...
*/
#include <iostream>
using namespace std;

bool visited[31][31][31][450];
char ans[32];

int N, K;
bool solve(int n, int a, int b, int k)
{
	if (n == N) {
		if (K == k) return true;
		else return false;
	}

	if (visited[n][a][b][k]) return false;
	visited[n][a][b][k] = true;

	ans[n] = 'A';
	if (solve(n + 1, a + 1, b, k)) return true;
	
	ans[n] = 'B';
	if (solve(n + 1, a, b + 1, k + a)) return true;

	ans[n] = 'C';
	if (solve(n + 1, a, b, k + a + b)) return true;

	return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> N >> K;
	if (solve(0, 0, 0, 0))
		cout << ans << "\n";
	else
		cout << -1 << "\n";
	return 0;
}