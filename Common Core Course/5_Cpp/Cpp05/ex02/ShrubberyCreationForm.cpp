#include "ShrubberyCreationForm.hpp"
#include <string>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = other.target;
    setIsSigned(other.getIsSigned());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
    {
        this->target = other.target;
	    setIsSigned(other.getIsSigned());
    }
	return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}


void ShrubberyCreationForm::performAction() const
{
	std::ofstream outFile((target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileExeption();
		
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}