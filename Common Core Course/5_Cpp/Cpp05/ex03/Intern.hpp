#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// classes

class AForm;
// class PresidentialPardonForm;
// class RobotomyRequestForm;
// class ShrubberyCreationForm;

class Intern
{
	private:
		// Private Members

	public:
	// Constructors
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);

	// Member functions
		AForm *makeForm(const std::string form, const std::string target);

};

#endif