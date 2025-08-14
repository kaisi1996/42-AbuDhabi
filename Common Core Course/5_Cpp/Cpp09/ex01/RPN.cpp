#include "RPN.hpp"

//Constructors
RPN::RPN()
{
}

RPN::RPN(const std::string &inputStr)
{
	std::istringstream ss(inputStr);
	std::string token;
	int num;

	while (std::getline(ss, token, ' '))
	{
		if (token.length() == 1 && isdigit(token[0]))
		{
			std::istringstream(token) >> num;
			stack.push(num);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
			executeStack(token);
		else
			throw RPN::invalidArgument("Invalid argument: " + token);
	}
}

RPN::RPN(const RPN &other)
{
	this->stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->stack = other.stack;
	return (*this);
}

RPN::~RPN()
{
}

// Exceptions
RPN::invalidArgument::invalidArgument(const std::string& msg) : std::runtime_error(msg)
{
}

RPN::emptyStack::emptyStack(const std::string& msg) : std::runtime_error(msg)
{
}

RPN::divisionByZero::divisionByZero(const std::string& msg) : std::runtime_error(msg)
{
}


// Getters
double RPN::getResult() const
{
	if (stack.empty())
		throw RPN::emptyStack("Empty stack");
	else if (stack.size() > 1)
		throw RPN::invalidArgument("Invalid argument");
	return (stack.top());
}

// Private methods
void RPN::executeStack(std::string const token)
{
	double a;
	double b;

	if (stack.size() < 2)
		throw RPN::emptyStack("Empty stack");
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
    if (token == "+")
	    stack.push(b + a);
    else if (token == "-")
	    stack.push(b - a);
    else if (token == "*")
	    stack.push(b * a);
    else if (token == "/")
    {
        if (a == 0)
		throw RPN::divisionByZero("Division by zero");
        stack.push(b / a);
    }
}
