#include "arguments.h"
#include <sstream>

Arguments::~Arguments()
{}

void IntArg::parseValue(const std::string& str)
{
    std::stringstream stream;
    stream << str;
    int number = 0;
    stream >> number;
    setValue(number);
}

void StringArg::parseValue(const std::string& str)
{  
	m_value = str;
}
