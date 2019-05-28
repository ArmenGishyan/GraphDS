#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>
#include <vector>
#include <sstream>

namespace Helper {
    std::vector<std::string> splitString(const std::string& sourceStr, const char how = ' ')
    {
        std::vector<std::string> vec;
        std::istringstream f(sourceStr);
        std::string s;
        while (getline(f, s, how)) {
            vec.push_back(s);
        }
        return vec;
    }
}
#endif // HELPERFUNCTIONS_H
