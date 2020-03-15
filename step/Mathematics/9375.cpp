/*
Problem: 패션왕 신해빈 (9375)
Tier: Silver 1
Detail: 해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다.
예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다.
해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?
Comment: a! * b! ... * d! - 1
*/

#include <string>
#include <iostream>
#include <map>
using namespace std;

string s, t;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        map<string, int> dat;
        cin >> M;
        for(int j = 0; j < M; j++) {
            cin >> s >> t;
            if(dat.find(t) == dat.end()) dat.insert(make_pair(t, 1));
            else dat[t]++;
        }
        int result = 1;
        for(map<string, int>::const_iterator q = dat.begin(); q != dat.end(); q++) {
            result *= ((q->second) + 1);
        }
        cout << result - 1 << endl;
    }
    return 0;
}