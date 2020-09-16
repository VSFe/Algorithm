/*
Problem: 책 페이지 (1019)
Tier: Gold 1
Detail: 지민이는 N쪽인 책이 한권 있다. 첫 페이지는 1쪽이고, 마지막 페이지는 N쪽이다. 각 숫자가 모두 몇 번이 나오는지 출력하는 프로그램을 작성하시오.
Comment: 처음에 DP인 줄 알고 고민했는데, 그냥 규칙을 찾아서 푸는 수학 문제.
각 자리마다 등장하는 수는 앞의 수의 갯수 * 뒤의 수의 갯수로 접근이 가능한데, 0을 처리하는데 있어 조금 어려움을 겪었다....
*/

#include <iostream>
#include <cmath>
using namespace std;

int ans[10];

int main() {
    int num; cin >> num;
    int len = log10(num);
    for(int i = 0; i <= len; i++) {
        int stand = (int)(num / pow(10, i)) % 10;
        int leftCnt = num / pow(10, i + 1) + 1;
        int rightCnt = num % int(pow(10, i)) + 1;
        int addCnt = pow(10, i);

        if(stand == 0) ans[0] += addCnt * (leftCnt - 2) + rightCnt;
        else ans[0] += addCnt * (leftCnt - 1);

        for(int j = 1; j < stand; j++) ans[j] += leftCnt * addCnt;
        if(stand != 0) ans[stand] += addCnt * (leftCnt - 1) + rightCnt;
        for(int j = stand + 1; j <= 9; j++) ans[j] += (leftCnt - 1) * addCnt;
    }
    for(int i = 0; i < 10; i++) cout << ans[i] << ' ';
}