#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), sign_grade(150), execute_grade(150)
{

}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{

}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{

}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
	    is_signed = other.is_signed;
	return (*this);
}

Form::~Form()
{
	
}

// Member function
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= sign_grade)
    {
        is_signed = true;
        return;
    }
	throw GradeTooLowException();
}


std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (is_signed);
}

int Form::getSignGrade() const
{
	return (sign_grade);
}

int Form::getExecuteGrade() const
{
	return (execute_grade);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}


std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}