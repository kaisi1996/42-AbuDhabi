#include "PresidentialPardonForm.hpp"
#include <string>
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default target")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = other.target;
	setIsSigned(other.getIsSigned());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
	    setIsSigned(other.getIsSigned());
    }
	return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	
}


void PresidentialPardonForm::performAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;		
}