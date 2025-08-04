#include "ScalarConverter.hpp"

void	printSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	convChar(const std::string& str)
{
	char	c = 0;
    size_t  len = str.length();

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void	convInt(const std::string& str)
{
	long	l = std::atol(str.c_str());

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(l))
			std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout	<< static_cast<int>(l) << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

bool    add_dot_or_dont(const std::string& str)
{
    size_t  start_index;
    size_t  dot_index = str.find('.');
    size_t  after_dot_index = dot_index;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != '0')
        {
            start_index = i;
            break;
        }
    }
    for (size_t i = dot_index + 1; i < str.length(); i++)
    {
        if (str[i] != '0')
        {
            after_dot_index = i;
            break;
        }
    }
    if ((after_dot_index - start_index <= 6 && dot_index == after_dot_index) || (dot_index - start_index <= 6 && after_dot_index - start_index > 7) ||
        (dot_index - start_index == 6 && after_dot_index - start_index == 7))
    {
        return true;
    }
    return false;
}

void	convFloat(const std::string& str)
{
	float   f = std::atof(str.c_str());
	bool    add_dot = add_dot_or_dont(str);
    
	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << (add_dot ? ".0f" : "f") << std::endl;
    std::cout << "double: ";
	if (f < MIN_DOUBLE || f > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(f) << (add_dot ? ".0" : "") << std::endl;
}

void	convDouble(const std::string& str)
{
	double	d = std::atof(str.c_str());
	bool    add_dot = add_dot_or_dont(str);

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (add_dot ? ".0f" : "f") << std::endl;
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << (add_dot ? ".0" : "") << std::endl;
}