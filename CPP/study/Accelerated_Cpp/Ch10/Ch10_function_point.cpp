#include <iostream>
using namespace std;

int next(int x) {
    return x+1;
}

int main() {
    int (*fp)(int);
    fp = &next;
    int i = 0;
    cout << fp(i) << endl << (*fp)(i) << endl;
}