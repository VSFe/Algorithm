#ifndef GUARD_Ch08_split_h
#define GUARD_Ch08_split_h

#include <string>
#include <cctype>
#include <algorithm>

inline bool space(char c) {
    return std::isspace(c);
}

inline bool not_space(char c) {
    return !std::isspace(c);
}

template <class Out>
void split(const std::string& str, Out os) {
    typedef std::string::const_iterator iter;
    iter i = str.begin();

    while(i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
    
        if (i != str.end()) *os++ = std::string(i, j);

        i = j;
    }
}

#endif