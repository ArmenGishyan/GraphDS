#include "arguments.h"
#include <sstream>

void IntArg::parseValue(const std::string& str)
{
    std::stringstream stream;
    stream << str;
    int number = 0;
    stream >> number;
    setValue(number);
}
