#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <sstream>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum    _type
{
    INVALID = -1,
    SPECIAL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	public:
		static void	convert(const std::string& str);
};

_type	Type(const std::string& str);
void	printSpecial(const std::string& str);
void	convChar(const std::string& str);
void	convInt(const std::string& str);
void	convFloat(const std::string& str);
void	convDouble(const std::string& str);

#endif