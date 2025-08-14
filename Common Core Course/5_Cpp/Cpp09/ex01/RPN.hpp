#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

class RPN
{
	private:
		std::stack<double> stack;
		void executeStack(std::string const token);

	public:
		//Constructors
		RPN();
		RPN(const std::string  &inputStr);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		//Getters
		double getResult() const;


		//Exceptions
		class invalidArgument : public std::runtime_error
		{
			public:
				explicit invalidArgument(const std::string& msg);
		};

		class emptyStack : public std::runtime_error
		{
			public:
				explicit emptyStack(const std::string& msg);
		};

		class divisionByZero : public std::runtime_error
		{
			public:
				explicit divisionByZero(const std::string& msg);
		};	
};

#endif