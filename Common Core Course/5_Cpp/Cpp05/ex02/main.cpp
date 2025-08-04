#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	std::cout << std::endl << "Test 1: ShrubberyCreationForm" << std::endl;
	Bureaucrat Shrubberry("Shrubberry", 130);
	ShrubberyCreationForm Shrubberry_form("Hello");
	
	std::cout << Shrubberry_form;
	Shrubberry.signForm(Shrubberry_form);
	std::cout << Shrubberry_form;
	Shrubberry.executeForm(Shrubberry_form);

	std::cout << std::endl << "Test 2: RobotomyRequestForm" << std::endl;
	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);

	std::cout << std::endl << "Test 3: PresidentialPardonForm" << std::endl;
	PresidentialPardonForm President_form("I am a president form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_Robo.executeForm(President_form);
	Mr_Robo.signForm(President_form);

	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	
	return (0);
}