#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stdexcept>
#include <iomanip>
#include <ios>

using namespace std;

struct Students_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;
    vec_sz a = vec.size();

    if(a == 0) throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = a / 2;
    return a % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];    
}

double grade(double midterm, double final, vector<double> homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * median(homework);
}

double grade(const Students_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Students_info& test) {
    return grade(test) < 60; 
}

bool compare(const Students_info& x, Students_info& y) {
    return x.name < y.name;
}

list<Students_info> extract_fails(list<Students_info>& students) {
    list<Students_info> fail;
    list<Students_info>::iterator iter = students.begin();

    while(iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else ++iter;
    }
    return fail;
}

int main() {

}