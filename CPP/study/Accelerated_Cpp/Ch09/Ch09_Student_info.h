#ifndef GUARD_Ch09_Student_info_h
#define GUARD_Ch09_Student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info {
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
public:
    Student_info(); 
    Student_info(std::istream&);
    std::string name() const { return n; }
    double grade() const;
    std::istream& read(std::istream&);
    bool valid() const { return !homework.empty(); }
};

bool compare(const Student_info&, const Student_info&);

#endif