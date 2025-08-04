#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), sign_grade(150), execute_grade(150)
{

}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{

}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

AForm::~AForm()
{
	
}

// Member function
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= sign_grade)
    {
        is_signed = true;
        return;
    }
	throw GradeTooLowException();
}


std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (is_signed);
}

int AForm::getSignGrade() const
{
	return (sign_grade);
}

int AForm::getExecuteGrade() const
{
	return (execute_grade);
}

void AForm::setIsSigned(bool is_signed)
{
	this->is_signed = is_signed;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (is_signed == false)
		throw IsNotSignedException();
	if (execute_grade < executor.getGrade())
		throw GradeTooLowException();

	performAction();
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}


std::ostream &operator<<(std::ostream &os,  AForm const &aform)
{
	os << "Name: " << aform.getName() << " isSigned: " << aform.getIsSigned() << " SignGrade: " << aform.getSignGrade() << " ExecuteGrade: " << aform.getExecuteGrade() << std::endl;
	return (os);
}