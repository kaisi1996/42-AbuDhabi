#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{ }

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void) other;
}

ScalarConverter::~ScalarConverter(void)
{ }

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

void    ScalarConverter::convert(const std::string& str)
{
    _type  type = Type(str);
    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case SPECIAL:
            printSpecial(str);
            break;
        case CHAR:
            convChar(str);
            break;
        case INT:
            convInt(str);
            break;
        case FLOAT:
            convFloat(str);
            break;
        case DOUBLE:
            convDouble(str);
            break;
    }
}