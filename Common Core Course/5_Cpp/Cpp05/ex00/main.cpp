#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << "Test 1: too high and too low creation" << std::endl;
	try
	{
		Bureaucrat person1("Person1", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat person2("Person2", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Test 2: increasing" << std::endl;
	Bureaucrat kaisi("Kaisi", 2);
	std::cout << kaisi;
	try
	{
		kaisi.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << kaisi;
	
	try
	{
		kaisi.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << kaisi;



	std::cout << std::endl << "Test 3: decreasing" << std::endl;
	Bureaucrat salem("Salem", 149);
	std::cout << salem;
	try
	{
		salem.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << salem;
	
	try
	{
		salem.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << salem;
	
	return (0);
}