#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string	darkestSecret;
public:
	// Constructors
	Contact();
	Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret);

	// Mutators
	void	setAll(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

	// Accessors
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
		
};

#endif