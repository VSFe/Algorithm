/*
Problem: 검문 (2981)
Tier: Silver 1
Detail: 
먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때,
나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.
N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.
Comment: 최소값을 기준으로, 1~N까지 뺐을 때 gcd가 1이 아니면 나눠 떨어지는게 맞으니까/... gcd의 약수를 모두 벡터에 넣어버리고 정렬 때리면 끝.
이라고 생각했는데, 진짜 충격적이다.
*/

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

int N;
vector<int> divi;
int gap[100];
int ppap = 1;

int Eucl(int a, int b);

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &gap[i]);
    sort(gap, gap+N);
    int min = gap[0];
    /*for(int i = 0; i < min; i++) {
        int gcd = Eucl(gap[0] - i, gap[1] - i);
        for(int j = 2; j < N; j++) gcd = Eucl(gcd, gap[j] - i);
        if(gcd != 1) ppap = ppap * gcd / Eucl(ppap, gcd);
    }*/
    if(N == 2) ppap = ppap * (gap[1] - gap[0]) / Eucl(ppap, gap[1] - gap[0]);
    else {
        int gcd = gap[1] - min;
        for(int j = 2; j < N; j++) gcd = Eucl(gcd, gap[j] - min);
        if(gcd != 1) ppap = ppap * gcd / Eucl(ppap, gcd);
    }
    for(int i = 1; i < sqrt(ppap); i++) {
        if(ppap % i == 0) {
            divi.push_back(i);
            divi.push_back(ppap / i);
        }
    }
    if(int(sqrt(ppap)) * int(sqrt(ppap)) == ppap) divi.push_back(sqrt(ppap));
    sort(divi.begin(), divi.end());
    for (int i = 1; i < divi.size(); i++) printf("%d ", divi[i]);
    return 0;

}

int Eucl(int a, int b){
    int remain; 
    int tmp1 = max(a, b), tmp2 = min(a, b);
    remain = tmp1 % tmp2;
    if (remain == 0) 
        return tmp2;
    else
    return Eucl(remain, tmp2); 
}