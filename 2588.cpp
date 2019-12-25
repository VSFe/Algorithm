#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
	string b;
    cin >> a >> b;
    cout << a * (b % 10) << a * (b/10)endl;
    return 0;
}


/*
 
string to int - string에서 int로 변환

atoi()함수 사용. -> atoi(char*)

인자가 char*형이기 때문에 c_str()함수로 변환해주어야함.

string str = "34";
int intValue = atoi(str.c_str());


int to string - int에서 string으로 변환

to_string()함수 사용. -> to_string(int)

int intValue = 5;
string str = to_string(intValue);

*/