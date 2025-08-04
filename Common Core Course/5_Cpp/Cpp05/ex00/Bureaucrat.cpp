#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{	
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;	
	return (*this);
}


Bureaucrat::~Bureaucrat()
{

}

// Member functions
std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	else
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}