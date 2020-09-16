#include <iostream>
#include <cstring>
#include <cstddef>
#include <string>
using namespace std;

string letter_grade(double grade) {
    static const double numbers[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    /*
    const char * : 상수형 문자에 대한 포인터. 포인터가 가리키는 변수의 값 변경 불가
    char const * : 문자에 대한 상수형 포인터. 포인터 값 변경 불가
    const char * const : 상수형 문자에 대한 상수형 포인터
    */
    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers); // 바이트 수 / 첫번째 배열 요소의 바이트 수 (모든 배열 요소의 바이트 크기는 같다.)

    for (size_t i = 0; i < ngrades; i++) {
        if (grade >= numbers[i]) return letters[i];
    }
    return "?\ ?\ ?"; //???
}

int main(int argc, char** argv) {
    if(argc > 1) {
        cout << argv[1];
        for(int i = 2; i != argc; i++) {
            cout << " " << argv[i];
        }
    }
    cout << endl;
    return 0;
    /*
    argv 각각은 배열의 첫번째 문자를 가르키는 포인터.
    ./Ch10_char hello world. 입력 시
    argc = 3
    argv[0] = { '.', '/', 'C', 'h', '1', '0' ...}
    argv[1] = {'H', 'e', 'l', 'l', 'o', '\n'}
    argv[2] = ...
    */
}