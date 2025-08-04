#include "ScalarConverter.hpp"

static int	isSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 1;
	return 0;
}

static int	isChar(const std::string& str, size_t& len)
{
	if (len == 1 && !isdigit(str[0]))
		return 1;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return 1;
	return 0;
}

static int	isInt(const std::string& str, size_t& len)
{
	int		i = 0;
	bool	flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = true;
	}
	while ((str[i] && len <= 11) || (str[i] && flag == false && len <= 10))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

static int	isFloat(const std::string& str, size_t len)
{
    bool dot_flag = false;

    // when i = len - 1 the letter should be f if it is float 
    // so no need to check since letter f exists in this string
	for (size_t i = 0; i < len - 1; i++)
	{
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        if (str[i] == '.' && dot_flag == false)
            dot_flag = true;
        else if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

_type  Type(const std::string& str)
{
    size_t  len = str.length();
    size_t  dot = str.find('.');
    size_t  f = str.find('f');
    if (dot == std::string::npos)
    {
        if (isSpecial(str))
            return SPECIAL;
        if (isChar(str, len))
            return CHAR;
        if (isInt(str, len))
            return INT;
    }
    if (f != std::string::npos && dot != std::string::npos)
    {
        if (isFloat(str, len))
            return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
    {
        if (isFloat(str, len + 1))
            return DOUBLE;
    }
    return INVALID;
}