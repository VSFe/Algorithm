#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <iterator>
#include "Ch08_split.h"
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) split(s, ostream_iterator<string>(cout, "\n"));
    return 0;
}