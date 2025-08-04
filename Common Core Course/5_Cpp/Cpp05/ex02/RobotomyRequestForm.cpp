#include "RobotomyRequestForm.hpp"
#include <string>
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default target")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = other.target;
	setIsSigned(other.getIsSigned());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    	setIsSigned(other.getIsSigned());
    }
	return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	
}


void RobotomyRequestForm::performAction() const
{
	int random_number;

	random_number = rand() % 2;

	if (random_number == 1)
		std::cout << "Beeep Beeeee Beeeeeeeep. " << target << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotomyFailed();
}

const char *RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("Unfortunately robotomy failed.");
}