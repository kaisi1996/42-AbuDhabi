#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class RobotomyRequestForm : public AForm
{
	private:
		std::string		target;
		virtual void	performAction() const;
	
	public:
	// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		// exceptions
		class RobotomyFailed : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif