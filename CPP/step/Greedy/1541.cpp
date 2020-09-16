/*
Problem: 잃어버린 괄호 (1541)
Tier: Silver 2
Detail: 
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다.
그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
Comment:
숫자 발견 -> 끝까지 일단 구해
뒤 부호가 음수일 경우: 뒷부분에 새로운 음수가 나올 때 까지 쫙 더해줌
if ~~ = '-' 
뒤 부호가 양수일 경우: 그냥 더해줌
다 풀고 나서 느끼는건데 그냥 - 하나 나오면 뒤에꺼 다 더해서 빼면 되는거네...
*/

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string d;
int index = 0;
int result = 0;

int extract_num(string s, int* a) {
    int idx = *a;
    int result;
    while((s[idx] != '-' && s[idx] != '+' && idx != s.length())) idx++;
    string res = s.substr(*a, idx-(*a));
    *a += res.length();
    return stoi(res);
}

int main() {
    cin >> d;
    while(index != d.length()) {
        if(d[index] == '+') result += extract_num(d, &(++index));
        else if(d[index] == '-') {
            int tmp = extract_num(d, &(++index));
            while(true) {
                if(index == d.length() || d[index] == '-') {
                    result -= tmp;
                    break;
                }
                else {
                    tmp += extract_num(d, &(++index));
                }
            }
        }
        else result += extract_num(d, &index);
    }
    printf("%d", result);
    return 0;
}
