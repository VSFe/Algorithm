#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const size_t NDIM = 3;
    double coord[NDIM];
    vector<double> c;
    copy(coord, coord + NDIM, back_inserter(c));
    vector<double> v(coord, coord + NDIM);
    if(c == v) {
        cout << "Good" << endl;
    }
    
    return 0;
}